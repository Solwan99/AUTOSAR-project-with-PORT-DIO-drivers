 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Solwan Shokry Ahmed
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H


/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION               (1U)
#define PORT_CFG_SW_MINOR_VERSION               (0U)
#define PORT_CFG_SW_PATCH_VERSION               (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION       (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION       (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION       (3U)


/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)



/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                   (STD_ON)

/* Pre-compile option for Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API 	        (STD_ON)    

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                   (STD_OFF)

/*Pre-Compile option for number of ports in PORT Module Configuration*/
#define PORT_NUMBER_OF_PORTS                    (Port_Type)(6U)
   
#define PORT_PIN_MODE_DIO                       (Port_PinModeType)(0U)
#define PORT_PIN_MODE_UART                      (Port_PinModeType)(1U)
#define PORT_PIN_MODE_UART1                     (Port_PinModeType)(2U)
#define PORT_PIN_MODE_SSI                       (Port_PinModeType)(2U)
#define PORT_PIN_MODE_I2C                       (Port_PinModeType)(3U)
#define PORT_PIN_MODE_CAN0                      (Port_PinModeType)(3U)
#define PORT_PIN_MODE_PWM0                      (Port_PinModeType)(4U)
#define PORT_PIN_MODE_PWM1                      (Port_PinModeType)(5U)
#define PORT_PIN_MODE_QEI                       (Port_PinModeType)(6U)
#define PORT_PIN_MODE_DIO_GPT                   (Port_PinModeType)(7U)
#define PORT_PIN_MODE_CAN                       (Port_PinModeType)(8U)
#define PORT_PIN_MODE_USB                       (Port_PinModeType)(8U)   
#define PORT_PIN_MODE_AC                        (Port_PinModeType)(9U) 
#define PORT_PIN_MODE_TRD                       (Port_PinModeType)(14U)
#define PORT_PIN_MODE_ADC                       (Port_PinModeType)(15U)

/*Pre-Compile option for indicies of ports in PORT Module Configuration*/
#define PORT_A                                  (Port_Type)(0U)
#define PORT_B                                  (Port_Type)(1U)
#define PORT_C                                  (Port_Type)(2U)
#define PORT_D                                  (Port_Type)(3U)
#define PORT_E                                  (Port_Type)(4U)
#define PORT_F                                  (Port_Type)(5U)

/*Pre-Compile option for number of port pins in PORT Module Configuration*/
#define PORT_A_NUMBER_OF_PORT_PINS              (Port_PinType)(8U)
#define PORT_B_NUMBER_OF_PORT_PINS              (Port_PinType)(8U)
#define PORT_C_NUMBER_OF_PORT_PINS              (Port_PinType)(8U)
#define PORT_D_NUMBER_OF_PORT_PINS              (Port_PinType)(8U)
#define PORT_E_NUMBER_OF_PORT_PINS              (Port_PinType)(6U)
#define PORT_F_NUMBER_OF_PORT_PINS              (Port_PinType)(5U)

/*Pre-Compile option for indicies of port pins in PORT Module Configuration*/
#define PA_0                                    (Port_PinType)(0U)
#define PA_1                                    (Port_PinType)(1U)
#define PA_2                                    (Port_PinType)(2U)
#define PA_3                                    (Port_PinType)(3U)
#define PA_4                                    (Port_PinType)(4U)
#define PA_5                                    (Port_PinType)(5U)
#define PA_6                                    (Port_PinType)(6U)
#define PA_7                                    (Port_PinType)(7U)
#define PB_0                                    (Port_PinType)(8U)
#define PB_1                                    (Port_PinType)(9U)
#define PB_2                                    (Port_PinType)(10U)
#define PB_3                                    (Port_PinType)(11U)
#define PB_4                                    (Port_PinType)(12U)
#define PB_5                                    (Port_PinType)(13U)
#define PB_6                                    (Port_PinType)(14U)
#define PB_7                                    (Port_PinType)(15U)
#define PC_0                                    (Port_PinType)(16U)
#define PC_1                                    (Port_PinType)(17U)
#define PC_2                                    (Port_PinType)(18U)
#define PC_3                                    (Port_PinType)(19U)
#define PC_4                                    (Port_PinType)(20U)
#define PC_5                                    (Port_PinType)(21U)
#define PC_6                                    (Port_PinType)(22U)
#define PC_7                                    (Port_PinType)(23U)
#define PD_0                                    (Port_PinType)(24U)
#define PD_1                                    (Port_PinType)(25U)
#define PD_2                                    (Port_PinType)(26U)
#define PD_3                                    (Port_PinType)(27U)
#define PD_4                                    (Port_PinType)(28U)
#define PD_5                                    (Port_PinType)(29U)
#define PD_6                                    (Port_PinType)(30U)
#define PD_7                                    (Port_PinType)(31U)
#define PE_0                                    (Port_PinType)(32U)
#define PE_1                                    (Port_PinType)(33U)
#define PE_2                                    (Port_PinType)(34U)
#define PE_3                                    (Port_PinType)(35U)
#define PE_4                                    (Port_PinType)(36U)
#define PE_5                                    (Port_PinType)(37U)
#define PF_0                                    (Port_PinType)(38U)
#define PF_1                                    (Port_PinType)(39U)
#define PF_2                                    (Port_PinType)(40U)
#define PF_3                                    (Port_PinType)(41U)
#define PF_4                                    (Port_PinType)(42U)

/******************************************************************************
 *              Configuration Options & Parameters for default mode           *
 ******************************************************************************/

  
/* Option for default pin level value */
#define PORT_DEFAULT_PIN_LEVEL_VALUE                    (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW

/* Option for default pin direction */
#define PORT_DEFAULT_PIN_DIRECTION                      (Port_PinDirectionType)PORT_PIN_IN

/* Option for default pin mode */
#define PORT_DEFAULT_PIN_MODE                           (Port_PinModeType)PORT_PIN_MODE_DIO

/* Option for default direction changeable option */
#define PORT_DEFAULT_PIN_DIRECTION_CHANGEABLE_VALUE     (Port_DirectionChangeableType)PORT_PIN_DIRECTION_NOT_CHANGEABLE

/* Option for default mode changeable option */
#define PORT_DEFAULT_PIN_MODE_CHANGEABLE_VALUE          (Port_ModeChangeableType)PORT_PIN_MODE_NOT_CHANGEABLE

/* Option for default Internal resistor mode */
#define PORT_DEFAULT_INTERNAL_RESISTOR_MODE             (Port_InternalResistorType)OFF




#endif /* PORT_CFG_H */