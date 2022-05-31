 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Solwan Shokry Ahmed
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR */
#define PORT_VENDOR_ID    (2299U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION                           (1U)
#define PORT_SW_MINOR_VERSION                           (0U)
#define PORT_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION                   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION                   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION                   (3U)

/*
 * Macros for Port Status
 */
#define PORT_MODULE_DRIVER_INITIALIZED                  (1U)
#define PORT_MODULE_DRIVER_NOT_INITIALIZED              (0U)


/* Standard AUTOSAR types */
#include "Std_Types.h"



/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif
 
/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"
 


/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORTPORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"


   
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

      /* Service ID for PORT Init */
#define PORT_INIT_SID                   (uint8)0x00
   
      /* Service ID for Port SetPinDirection*/
#define PORT_SET_PIN_DIRECTION_SID      (uint8)0x01
   
    /* Service ID for Port RefreshPortDirection*/
#define PORT_REFRESH_PORT_DIRECTION_SID (uint8)0x02
   
    /* Service ID for Port GetVersionInfo*/
#define PORT_GET_VERSION_INFO_SID       (uint8)0x03

   /* Service ID for Port SetPinMode*/
#define PORT_SET_PIN_Mode_SID           (uint8)0x04
   

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
  
   /*DET code to report that an Invalid Port Pin ID is requested*/ 
#define PORT_E_PARAM_PIN                (uint8)0x0A
   
   /*DET code to report that Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE   (uint8)0x0B

    /*DET code to report that API Port_Init service called with wrong parameter.*/
#define PORT_E_PARAM_CONFIG             (uint8)0x0C 
   
   /*DET code to report that API Port_SetPinMode service called when mode is unchangeable.*/
#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D
   
#define PORT_E_MODE_UNCHANGEABLE        (uint8)0x0E
   
    /* DET code to report that an API service was called without module initialization*/
#define PORT_E_UNINIT                   (uint8)0x0F  
  
    /*DET code to report that APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER             (uint8)0x10
   
/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/

/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for Port_PinType used for the symbolic name of a Port */
typedef uint8 Port_Type;

   /* Type definition for Port_PinType used for the symbolic name of a Port Pin 
   >>Having 43 pins only, makes it reasonable to use uint8*/
typedef uint8 Port_PinType;

/*Description: Enum to hold the direction of a Port Pin used by Port APIs.*/
typedef enum {  
  PORT_PIN_IN,
  PORT_PIN_OUT
}Port_PinDirectionType;

/*to hold number of port pin modes*/
typedef uint8 Port_PinModeType;


/* Description: Enum to hold changeability of direction type for PIN */
typedef enum{
  
  PORT_PIN_DIRECTION_NOT_CHANGEABLE,
  PORT_PIN_DIRECTION_CHANGEABLE
    
}Port_DirectionChangeableType;

/* Description: Enum to hold changeability of mode type for PIN */
typedef enum{
  
  PORT_PIN_MODE_NOT_CHANGEABLE,
  PORT_PIN_MODE_CHANGEABLE
    
}Port_ModeChangeableType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{   OFF,
    PULL_UP,
    PULL_DOWN
}Port_InternalResistorType;

/* Description: Enum to hold level value type for PIN */
typedef enum{
  PORT_PIN_LEVEL_LOW,
  PORT_PIN_LEVEL_HIGH
}Port_PinLevelValueType;

/* Description: Structure to hold the configuration container of each PIN:
*	1. Member: PortPinId > the number of the pin in the PORT.
 *	2. Member: PortPinDirection > the direction of pin --> INPUT or OUTPUT.
 *      3. Member: PortPinInternalResistorMode > the internal resistor --> Disable, Pull up or Pull down.
 *      4. Member: PortPinInitialValue > the initial value of the pin.
 *      5. Member: PortPinLevelValue > the value of the pin.
 *      6. Member: PortPinInitialMode > the initial mode number of the pin.
 *      7. Member: PortPinMode > the pin mode number.
 *      8. Member: PortPinDirectionChangeable > the changeability of pin direction during runtime.
 *      9. Member: PortPinModeChangeable > the changeability of pin mode during runtime.
 */
typedef struct 
{
    Port_PinType PortPinId; 
    Port_PinDirectionType PortPinDirection;
    Port_InternalResistorType PortPinInternalResistorMode;
    Port_PinLevelValueType PortPinInitialValue;
    Port_PinLevelValueType PortPinLevelValue;
    Port_PinModeType PortPinInitialMode;
    Port_PinModeType PortPinMode;
    Port_DirectionChangeableType PortPinDirectionChangeable;
    Port_ModeChangeableType PortPinModeChangeable;
}PortPin;

/* Description: Structure to hold the configuration container of each PORT:
 *	1. Member: PortId > the number of the port.
 *	2. Member: Port_NumberOfPortPins > the number of pins in each port.
 *      3. Member: Channels[Port_NumberOfPortPins] > an array of type PortPin to hold the configuration of each pin in the port.
 */
typedef struct{
  Port_Type PortId;
  Port_PinType Port_NumberOfPortPins;
  PortPin Channels[Port_NumberOfPortPins];
  
}PortContainer;

/* Description: Structure to hold the configuration container of each PORT:
 *	1. Member: Port_NumberOfPorts > the number ports to be configured in PORT module.
 *	2. Member: Ports[Port_NumberOfPorts] > an array of type PortContainer to hold the configuration of each port in the Port Module.
 */
typedef struct{
  Port_Type Port_NumberOfPorts;
  PortContainer Ports[Port_NumberOfPorts];
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
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
void Port_Init(const Port_ConfigType* ConfigPtr);

/*Precompile option to keep or remove Port_SetPinDirection function*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON) 
/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction
************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);
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
void Port_RefreshPortDirection(void);

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
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);
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
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Post Build structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

/*A variable to store Port_Status to be accessed by upper AUTOSAR Layers*/
extern uint8 Port_Status;

#endif /* PORT_H */
