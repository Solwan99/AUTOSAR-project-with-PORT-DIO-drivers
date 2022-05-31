 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Solwan Shokry Ahmed
 ******************************************************************************/

#include "Port.h"
#include "tm4c123gh6pm_registers.h"


/*Pre-compile option to check if Error detection is on to either keep the Det error code or delete it.*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"

/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
   
#endif

#endif

/*******************************************************************************
 *                           Private Global Variables                          *
 *******************************************************************************/

/*Pointer to Port_ConfigType Structure to store the PORT Module configuration container address, Initially with a NULL value*/
STATIC const Port_ConfigType * Port_ConfigPtr = NULL_PTR;

/*A variable to store Port_Status to be accessed by upper AUTOSAR Layers*/
STATIC Port_Status = PORT_NOT_INITIALIZED;


/*******************************************************************************
 *                        Public Functions Implementations                     *
 *******************************************************************************/

/*******************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port Driver module.
********************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
  /*Check if ConfigPtr is a Null Pointer*/
  if(NULL_PTR==ConfigPtr)
  {
    /*Report (PORT_E_PARAM_CONFIG) DET code to report that API Port_Init service called with wrong parameter*/
    Det_ReportError(PORT_MODULE_ID,
                    PORT_INSTANCE_ID,
                    PORT_INIT_SID,
                    PORT_E_PARAM_CONFIG);
  }
  else
#endif
  {
    /* Set the module state to initialized*/
    Port_Status = PORT_INITIALIZED;
    
    /* Set the global Module Configuration Pointer Port_ConfigPtr to point to the Post-build configuration structure.
     * By storing the address of the first PortContainer structure in Ports array >> Ports[PORT_A]
     */
    Port_ConfigPtr= ConfigPtr;
    
    /*Pointer to hold the Port's corresponding Base register address,Initially with a NULL value*/
    volatile uint32 * Port_BaseReg_Ptr = NULL_PTR; 
    
    volatile uint32 delay = 0;
    
    uint8 Pin_IndexCount;
    uint8 Port_IndexCount;
    
    for(Port_IndexCount=0;Port_IndexCount < ConfigPtr->Port_NumberOfPorts ;Port_IndexCount++)
    {
      switch(ConfigPtr->Ports[Port_IndexCount].PortId)
      {
        case  PORT_A: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                      break;
	case  PORT_B: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                      break;
	case  PORT_C: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                      break;
	case  PORT_D: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                      break;
        case  PORT_E: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                      break;
        case  PORT_F: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                      break;
        default: break;
      }
      /* Enable clock for PORT and allow time for clock to start*/
      SET_BIT(SYSCTL_REGCGC2_REG,ConfigPtr->Ports[Port_IndexCount].PortId);
      delay = SYSCTL_REGCGC2_REG;
      
      for(Pin_IndexCount=0;Pin_IndexCount < ConfigPtr->Ports[Port_IndexCount].Port_NumberOfPortPins ;Pin_IndexCount++)
      {
        /* In case of pins PD7 or PF0 */
        if( ((PORT_D == ConfigPtr->Ports[Port_IndexCount].PortId ) && (PD_7 == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinId )) || ((PORT_F == ConfigPtr->Ports[Port_IndexCount].PortId) && (PF_0 == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinId )) ) 
        {
          /* Unlock the GPIOCR register */
          *(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;
             
          /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_COMMIT_REG_OFFSET) ,Pin_IndexCount);  
        }
        /* In case of pins PC3:PC0   */
        else if( (PORT_C == ConfigPtr->Ports[Port_IndexCount].PortId) && (ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinId <= PC_3) ) 
        {
           /* Do Nothing ...  this is the JTAG pins, Continue looping on the other pins */
          continue;
        }
        else
        {
          /* Do Nothing ... No need to unlock the commit register for this pin */
        }
        
        /*In case of DIO pin*/
        if (PORT_PIN_MODE_DIO == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinInitialMode)
        {
          /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_IndexCount);      
          
          /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,Pin_IndexCount);             
          
           /* Clear the PMCx bits for this pin */
          *(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_IndexCount * 4));
          
          if (PORT_PIN_IN == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinDirection)
          {
             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIR_REG_OFFSET) , Pin_IndexCount);
            
            if (PULL_UP == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinInternalResistorMode)
            {
               /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_PULL_UP_REG_OFFSET) , Pin_IndexCount);      
            }
            else if (PULL_DOWN == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinInternalResistorMode )
            {
               /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Pin_IndexCount);    
            }
            else if (OFF == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinInternalResistorMode)
            {
               /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_PULL_UP_REG_OFFSET) , Pin_IndexCount);
              
              /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull down pin */
              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Pin_IndexCount);    
            }
            else
            {
              /*Do Nothing*/
            }
          }
          else if (PORT_PIN_OUT == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinDirection)
          {
            /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIR_REG_OFFSET) , Pin_IndexCount); 
            
            if(PORT_PIN_LEVEL_LOW == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinInitialValue)
            {
              /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
               CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DATA_REG_OFFSET) ,Pin_IndexCount);        
            }
            else if (PORT_PIN_LEVEL_HIGH == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinInitialValue)
            {
              /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DATA_REG_OFFSET) ,Pin_IndexCount);        
            }
            else
            {
              /*Do nothing*/
            }
          }
          else 
          {
            /*Do nothing*/
          }
          
          /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin_IndexCount);        
        }
        /*In case of analog pin >> (ADC) or (Analog Comparator)*/
        else if(PORT_PIN_MODE_ADC == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinInitialMode || PORT_PIN_MODE_AC == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinInitialMode)
        {
          /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr+ PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin_IndexCount);    
          
          /*An Analog input for ADC mode, Analog comparator input pin mode*/
          if (PORT_PIN_IN == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinDirection)
          {
             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIR_REG_OFFSET) , Pin_IndexCount);
          }
          /*An Analog output pin for Analog Comparator output pin Mode*/
          else if(PORT_PIN_OUT == ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinDirection)
          {
            /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIR_REG_OFFSET) , Pin_IndexCount); 
          }
          else
          {
            /*Do Nothing*/
          }
           /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) ,Pin_IndexCount); 
        }
        /*Any other Alternative digital functionality*/
        else 
        {
          /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_IndexCount);          
          
           /* enable Alternative function for this pin by Setting the corresponding bit in GPIOAFSEL register */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin_IndexCount);                  
          
          /* Clear the PMCx bits for this pin */
          *(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_IndexCount * 4));         
          
          /* Set the PMCx bits for this pin to the selected Alternate function in the configurations */
          *(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_CTL_REG_OFFSET) |= (ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinInitialMode << (Pin_IndexCount * 4));      
          
          /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) ,Pin_IndexCount);             
        }
      }
    }      
  }  
}

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number,
*                  Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction
************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction)
{
  /*Static local Variable to hold the Port Number of the function parameter*/
  STATIC Port_Type Port_Index;
  
  /*Static local Variable to hold the corresponding Pin index in its corresponding Port */
  STATIC Port_PinType Pin_Index;
  
  /*Static local Variable to hold the error occurance state of the API*/
  STATIC boolean error_Occurance;
  
  error_Occurance=FALSE;
  
  /*Precompile option to check if error checking is on.If the the checking is on it keeps the det code.*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if(PORT_NOT_INITIALIZED == Port_Status)
    {
        /*Report DET code to report that an API service was called without module initialization*/
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID,
                        PORT_E_UNINIT);
        error_Occurance = TRUE;
    }
    else /*Port Initialized*/
#endif
    {
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
        if(Pin < PA_0  || Pin > PF_4)
        {
            /*Report DET code to report that an Invalid Port Pin ID is requested*/
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_DIRECTION_SID,
                            PORT_E_PARAM_PIN);
            error_Occurance = TRUE;
        }
        else /*Pin ID is valid*/
    #endif
        {         
          if( PA_0 <= Pin && PB_0 > Pin)
          {
              Port_Index= PORT_A;
              Pin_Index = Pin % PORT_A_NUMBER_OF_PORT_PINS;
          }
          else if (PB_0 <= Pin && PC_0 > Pin)
          {
              Port_Index= PORT_B;
              Pin_Index = Pin % PORT_B_NUMBER_OF_PORT_PINS;
          }
          else if(PC_0 <= Pin && PD_0 > Pin)
          {
              Port_Index= PORT_C;
              Pin_Index = Pin % PORT_C_NUMBER_OF_PORT_PINS;
          }
          else if(PD_0 <= Pin && PE_0 > Pin)
          {
              Port_Index= PORT_D;
              Pin_Index = Pin % PORT_D_NUMBER_OF_PORT_PINS;
          }
          else if(PE_0 <= Pin && PF_0 > Pin)
          {
              Port_Index= PORT_E;
              Pin_Index = Pin - 32;
          }
          else if(PF_0 <= Pin)
          {
              Port_Index= PORT_F;
              Pin_Index = Pin - 38;
          }
          else
          {
              /*Do Nothing*/
          }
          #if (PORT_DEV_ERROR_DETECT == STD_ON)
          if (PORT_PIN_DIRECTION_NOT_CHANGEABLE == Port_ConfigPtr->Ports[Port_Index].Channels[Pin_Index].PortPinDirectionChangeable)
          {
             /* Report to DET  */
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_DIRECTION_SID,
                            PORT_E_DIRECTION_UNCHANGEABLE);
            error_Occurance = TRUE;
          }
          else
          #endif
          {
            if(FALSE == error_Occurance)
            {
              /*Pointer to hold the Port's corresponding Base register address,Initially with a NULL value*/
              volatile uint32 * Port_BaseReg_Ptr = NULL_PTR; 

              switch(Port_Index)
              {
                case  PORT_A: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                              break;
                case  PORT_B: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                              break;
                case  PORT_C: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                              break;
                case  PORT_D: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                              break;
                case  PORT_E: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                              break;
                case  PORT_F: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                              break;
                default: break;
              }
              if(PORT_PIN_IN == Direction)
              {
                /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIR_REG_OFFSET) , Pin_Index);
              }
              else if (PORT_PIN_OUT == Direction)
              {
                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIR_REG_OFFSET) , Pin_Index); 
              }
              else
              {
                /*Do Nothing*/
              }
            }
            else 
            {
              /*Do Nothing*/
            }
          }
        }
    } 
}
#endif


/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection(void)
{  
  /*Static local Variable to hold the error occurance state of the API*/
  STATIC boolean error_Occurance;

  error_Occurance = FALSE;
  /*Precompile option to check if error checking is on.If the the checking is on it keeps the det code.*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  if(PORT_NOT_INITIALIZED == Port_Status)
  {
    /*Report DET code to report that an API service was called without module initialization*/
    Det_ReportError(PORT_MODULE_ID,
                    PORT_INSTANCE_ID,
                    PORT_REFRESH_PORT_DIRECTION_SID,
                    PORT_E_UNINIT);
    error_Occurance = TRUE;
  }
  else /*Port Initialized*/
#endif
  {
    if(FALSE == error_Occurance)
    {
      uint8 Pin_IndexCount;
      uint8 Port_IndexCount;
    
      for(Port_IndexCount=0;Port_IndexCount < Port_ConfigPtr->Port_NumberOfPorts ;Port_IndexCount++)
      {
        switch(Port_ConfigPtr->Ports[Port_IndexCount].PortId)
        {
          case  PORT_A: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                        break;
          case  PORT_B: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                        break;
          case  PORT_C: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                        break;
          case  PORT_D: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                        break;
          case  PORT_E: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                        break;
          case  PORT_F: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                        break;
          default: break;
        }
      
        for(Pin_IndexCount=0;Pin_IndexCount < Port_ConfigPtr->Ports[Port_IndexCount].Port_NumberOfPortPins ;Pin_IndexCount++)
        {
          /*Only the Pins Configured to NOT have a changeable direction*/
          if (PORT_PIN_DIRECTION_NOT_CHANGEABLE == Port_ConfigPtr->Ports[Port_IndexCount].Channels[Pin_IndexCount].PortPinDirectionChangeable)
          {
            if(PORT_PIN_IN == Direction)
            {
              /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIR_REG_OFFSET) , Pin_IndexCount);
            }
            else if (PORT_PIN_OUT == Direction)
            {
              /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
              SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIR_REG_OFFSET) , Pin_IndexCount); 
            }
            else
            {
              /*Do Nothing*/
            }
          }
        }
      }
    }
  }
}

/*Precompile option to keep or remove Port_GetVersionInfo function*/
#ifdef PORT_VERSION_INFO_API
/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): versioninfo
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    /*Static local Variable to hold the error occurance state of the API*/
  STATIC boolean error_Occurance;
  
  error_Occurance = FALSE;

  /*Precompile option to check if error checking is on.If the the checking is on it keeps the det code.*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  if(NULL_PTR == versioninfo)
  {
    /*Report DET code to report that APIs called with a Null Pointer*/
    Det_ReportError(PORT_MODULE_ID,
                    PORT_INSTANCE_ID,
                    PORT_GET_VERSION_INFO_SID,
                    PORT_E_PARAM_POINTER);
    error_Occurance = TRUE;
  }
  else /*Right Parameter*/
#endif
  {
    /*Precompile option to check if error checking is on.If the the checking is on it keeps the det code.*/
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    if(PORT_NOT_INITIALIZED == Port_Status)
    {
      /*Report DET code to report that an API service was called without module initialization*/
      Det_ReportError(PORT_MODULE_ID,
                      PORT_INSTANCE_ID,
                      PORT_GET_VERSION_INFO_SID,
                      PORT_E_UNINIT);
      error_Occurance = TRUE;
    }
    else /*Port Initialized*/
    #endif
    {
      if(FALSE == error_Occurance)
      {
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
      }
    }
  }
}
#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Mode
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
{  
  /*Static local Variable to hold the Port Number of the function parameter*/
  STATIC Port_Type Port_Index;
  
  /*Static local Variable to hold the corresponding Pin index in its corresponding Port */
  STATIC Port_PinType Pin_Index;
  
  /*Static local Variable to hold the error occurance state of the API*/
  STATIC boolean error_Occurance;
  
  error_Occurance=FALSE;
  
  /*Precompile option to check if error checking is on.If the the checking is on it keeps the det code.*/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if(PORT_NOT_INITIALIZED == Port_Status)
    {
        /*Report DET code to report that an API service was called without module initialization*/
        Det_ReportError(PORT_MODULE_ID,
                        PORT_INSTANCE_ID,
                        PORT_SET_PIN_MODE_SID,
                        PORT_E_UNINIT);
        error_Occurance = TRUE;
    }
    else /*Port Initialized*/
#endif
    {
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
        if(Pin < PA_0  || Pin > PF_4)
        {
            /*Report DET code to report that an Invalid Port Pin ID is requested*/
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_MODE_SID,
                            PORT_E_PARAM_PIN);
            error_Occurance = TRUE;
        }
        else /*Pin ID is valid*/
      #endif
        {         
          if( PA_0 <= Pin && PB_0 > Pin)
          {
              Port_Index= PORT_A;
              Pin_Index = Pin % PORT_A_NUMBER_OF_PORT_PINS;
          }
          else if (PB_0 <= Pin && PC_0 > Pin)
          {
              Port_Index= PORT_B;
              Pin_Index = Pin % PORT_B_NUMBER_OF_PORT_PINS;
          }
          else if(PC_0 <= Pin && PD_0 > Pin)
          {
              Port_Index= PORT_C;
              Pin_Index = Pin % PORT_C_NUMBER_OF_PORT_PINS;
          }
          else if(PD_0 <= Pin && PE_0 > Pin)
          {
              Port_Index= PORT_D;
              Pin_Index = Pin % PORT_D_NUMBER_OF_PORT_PINS;
          }
          else if(PE_0 <= Pin && PF_0 > Pin)
          {
              Port_Index= PORT_E;
              Pin_Index = Pin - 32;
          }
          else if(PF_0 <= Pin)
          {
              Port_Index= PORT_F;
              Pin_Index = Pin - 38;
          }
          else
          {
              /*Do Nothing*/
          }
          #if (PORT_DEV_ERROR_DETECT == STD_ON)
          if (PORT_PIN_MODE_NOT_CHANGEABLE == Port_ConfigPtr->Ports[Port_Index].Channels[Pin_Index].PortPinModeChangeable)
          {
             /* Report to DET  */
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_MODE_SID,
                            PORT_E_MODE_UNCHANGEABLE);
            error_Occurance = TRUE;
          }
          else
          #endif
          {
            #if (PORT_DEV_ERROR_DETECT == STD_ON)
          if (Mode < PORT_PIN_MODE_DIO || Mode > PORT_PIN_MODE_ADC)
          {
             /* Report to DET  */
            Det_ReportError(PORT_MODULE_ID,
                            PORT_INSTANCE_ID,
                            PORT_SET_PIN_MODE_SID,
                            PORT_E_PARAM_INVALID_MODE);
            error_Occurance = TRUE;
          }
          else
          #endif
            if(FALSE == error_Occurance)
            {
              /*Pointer to hold the Port's corresponding Base register address,Initially with a NULL value*/
              volatile uint32 * Port_BaseReg_Ptr = NULL_PTR; 

              switch(Port_Index)
              {
                case  PORT_A: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                              break;
                case  PORT_B: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                              break;
                case  PORT_C: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                              break;
                case  PORT_D: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                              break;
                case  PORT_E: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                              break;
                case  PORT_F: Port_BaseReg_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                              break;
                default: break;
              }
              /*In case of DIO pin*/
              if (PORT_PIN_MODE_DIO == Mode)
              {
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_Index);      
          
                /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ALT_FUNC_REG_OFFSET) ,Pin_Index);             
          
                /* Clear the PMCx bits for this pin */
                *(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Index * 4));
                
                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin_Index);  
              }
              /*In case of analog pin >> (ADC) or (Analog Comparator)*/
              else if(PORT_PIN_MODE_ADC == Mode || PORT_PIN_MODE_AC == Mode)
              {
                /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr+ PORT_DIGITAL_ENABLE_REG_OFFSET) , Pin_Index);    
                /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) ,Pin_Index); 
              }
              /*Any other Alternative digital functionality*/
              else 
              {
                /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Pin_Index);          
          
                /* enable Alternative function for this pin by Setting the corresponding bit in GPIOAFSEL register */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Pin_Index);                  
          
                /* Clear the PMCx bits for this pin */
                *(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Pin_Index * 4));         
          
                /* Set the PMCx bits for this pin to the selected Alternate function in the configurations */
                *(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_CTL_REG_OFFSET) |= ( Mode << (Pin_Index * 4));      
          
                /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BaseReg_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) ,Pin_Index);             
              }
            else 
            {
              /*Do Nothing*/
            }
          }
        }
      }
    }
}
