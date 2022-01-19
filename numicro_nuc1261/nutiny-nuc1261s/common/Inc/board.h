#ifndef __BOARD_H
#define __BOARD_H

#include "numicro_hal.h"

#define DEF_ENABLE_HMCU_INDICTOR_BLINK      (1)
#define DEF_ENABLE_RESTORE_FACTORY_SETTING  (0)

#define WIFI_USE_UART2
#define DEBUG_USE_UART1

#ifdef DEBUG_USE_UART0
#define DEBUG_UART UART_0
#define DEBUG_TX PA_2 //UART0_TXD 
#define DEBUG_RX PA_3 //UART0_RXD 
#elif defined DEBUG_USE_UART1
#define DEBUG_UART UART_1
#define DEBUG_TX PA_0 //UART1_TXD 
#define DEBUG_RX PA_1 //UART1_RXD
#elif defined DEBUG_USE_UART2
#define DEBUG_UART UART_2
#define DEBUG_TX PC_2 //UART2_TXD 
#define DEBUG_RX PC_3 //UART2_RXD
#endif

#ifdef WIFI_USE_UART0
#define WIFI_UART UART_0
#define WIFI_TX PA_2 //UART0_TXD 
#define WIFI_RX PA_3 //UART0_RXD 
#elif defined WIFI_USE_UART1
#define WIFI_UART UART_1
#define WIFI_TX PA_0 //UART1_TXD 
#define WIFI_RX PA_1 //UART1_RXD
#elif defined WIFI_USE_UART2
#define WIFI_UART UART_2
#define WIFI_TX PC_2 //UART2_TXD 
#define WIFI_RX PC_3 //UART2_RXD
#endif
typedef enum
{
    // ACK connective pins
    P37 = WIFI_TX,
    P38 = WIFI_RX,

    P39 = PC_1,   //GPIO_INPUT, ACK_INTERRUPT
    P40 = PE_0,   //GPIO_OUTPUT, ACK_RESET

    P28 = PC_0,   //SmartLight
	P33 = PD_2, //Alexa light output


    P32 = PC_5,   //ACK indicator

    P31 = PD_1,   //Factory setting

    // Note: board-specific
    // UART naming
    VCOM_TXD = DEBUG_TX,
    VCOM_RXD = DEBUG_RX,
    STDIO_UART_TX   = VCOM_TXD,
    STDIO_UART_RX   = VCOM_RXD,
} Board_PinName;

typedef enum
{
    eUserGPIODev_HeartBeat,
    eUserGPIODev_RestoreFactorySetting,
    eUserGPIODev_ACK_LightPowerOn,
    eUserGPIODev_ACK_PowerEnable
} E_USERGPIODEV;

typedef enum
{
    eUartDev_DBG,
    eUartDev_ACK
} E_UARTDEV;

extern S_UARTDev    g_asBoardUartDev[];
extern S_GPIODev    g_asBoardGpioDev[];
extern S_GPIODev    g_asBoardUserGpioDev[];
extern S_PWMDev   g_asBoardPwmDev[];
extern S_CRCDev     g_sCrcDev;

void peripheral_init(void);

#endif /* __BOARD */

