 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Solwan Shokry Ahmed
 ******************************************************************************/
/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

#include "Port.h"
/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

   
   
   const Port_ConfigType Port_Configuration={
     
     PORT_NUMBER_OF_PORTS,{
     /*PortContainer Ports[PORT_NUMBER_OF_PORTS]*/
     
       /*Port Container Configuration Structure of Port A*/
     {
       PORT_A,
       PORT_A_NUMBER_OF_PORT_PINS,
       
      /*PortPin Channels[Port_NumberOfPortPins]*/
       {
         /*PortPin configuration Structure of Pin0*/
         {
           PA_0,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin1*/
         {
           PA_1,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin2*/
         {
           PA_2,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin3*/
         {
           PA_3,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin4*/
         {
           PA_4,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin5*/
         {
           PA_5,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin6*/
         {
           PA_6,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin7*/
         {
           PA_7,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         }
       }
     },
     /*Port Container Configuration Structure of Port B*/
     {
       PORT_B,
       PORT_B_NUMBER_OF_PORT_PINS,
       
       /*PortPin Channels[Port_NumberOfPortPins]*/
       {
         /*PortPin configuration Structure of Pin8*/
         {
           PB_0,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin9*/
         {
           PB_1,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin10*/
         {
           PB_2,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin11*/
         {
           PB_3,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin12*/
         {
           PB_4,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin13*/
         {
           PB_5,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin14*/
         {
           PB_6,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin15*/
         {
           PB_7,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         }
       }
     },
     /*Port Container Configuration Structure of Port C*/
     {
       PORT_C,
       PORT_C_NUMBER_OF_PORT_PINS,
       
       /*PortPin Channels[Port_NumberOfPortPins]*/
       {
         /*PortPin configuration Structure of Pin16*/
         {
           PC_0,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin17*/
         {
           PC_1,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin18*/
         {
           PC_2,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin19*/
         {
           PC_3,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin20*/
         {
           PC_4,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin21*/
         {
           PC_5,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin22*/
         {
           PC_6,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin23*/
         {
           PC_7,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         }
       }
     },
     /*Port Container Configuration Structure of Port D*/
     {
       PORT_D,
       PORT_D_NUMBER_OF_PORT_PINS,
       
       /*PortPin Channels[Port_NumberOfPortPins]*/
       {
         /*PortPin configuration Structure of Pin24*/
         {
           PD_0,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin25*/
         {
           PD_1,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin26*/
         {
           PD_2,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin27*/
         {
           PD_3,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin28*/
         {
           PD_4,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin29*/
         {
           PD_5,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin30*/
         {
           PD_6,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin31*/
         {
           PD_7,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         }
       }
     },
     /*Port Container Configuration Structure of Port E*/
     {
       PORT_E,
       PORT_E_NUMBER_OF_PORT_PINS,
       
       /*PortPin Channels[Port_NumberOfPortPins]*/
       {
         /*PortPin configuration Structure of Pin32*/
         {
           PE_0,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin33*/
         {
           PE_1,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin34*/
         {
           PE_2,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin35*/
         {
           PE_3,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin36*/
         {
           PE_4,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin37*/
         {
           PE_5,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
       }
     },
     /*Port Container Configuration Structure of Port F*/
     {
       PORT_F,
       PORT_F_NUMBER_OF_PORT_PINS,
       
       /*PortPin Channels[Port_NumberOfPortPins]*/
       {
         /*PortPin configuration Structure of Pin38*/
         {
           PF_0,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin39*/
         {
           PF_1,
           PORT_PIN_OUT,
           OFF,
           PORT_PIN_LEVEL_LOW,
           PORT_PIN_LEVEL_LOW,
           PORT_PIN_MODE_DIO,
           PORT_PIN_MODE_DIO,
           PORT_PIN_DIRECTION_NOT_CHANGEABLE,
           PORT_PIN_MODE_NOT_CHANGEABLE
         },
         /*PortPin configuration Structure of Pin40*/
         {
           PF_2,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin41*/
         {
           PF_3,
           PORT_DEFAULT_PIN_DIRECTION,
           PORT_DEFAULT_INTERNAL_RESISTOR_MODE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_LEVEL_VALUE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_MODE,
           PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE,
           PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE
         },
         /*PortPin configuration Structure of Pin42*/
         {
           PF_4,
           PORT_PIN_IN,
           PULL_UP,
           PORT_PIN_LEVEL_LOW,
           PORT_PIN_LEVEL_LOW,
           PORT_PIN_MODE_DIO,
           PORT_PIN_MODE_DIO,
           PORT_PIN_DIRECTION_NOT_CHANGEABLE,
           PORT_PIN_MODE_NOT_CHANGEABLE
         },
       }
     } 
   }       
};
       