#ifndef MCAL_NVIC_INTERFACE_H_
#define MCAL_NVIC_INTERFACE_H_

#include "STD.h"
#include "BitMath.h"

#define NVIC_GPIO_PORT_A           0
#define NVIC_GPIO_PORT_B           1
#define NVIC_GPIO_PORT_C           2
#define NVIC_GPIO_PORT_D           3
#define NVIC_GPIO_PORT_E           4
#define NVIC_UART0                 5
#define NVIC_UART1                 6
#define NVIC_TIMER0A               19
#define NVIC_TIMER0B               20
#define NVIC_TIMER1A               21
#define NVIC_TIMER1B               22
#define NVIC_TIMER2A               23
#define NVIC_TIMER2B               24
#define NVIC_GPIO_PORT_F           30
#define NVIC_TIMER3A               35
#define NVIC_TIMER3B               36

void M_NVIC_Void_EnableInterrupt (u8);
void M_NVIC_Void_DisableInterrupt (u8);
void M_NVIC_Void_SetPriority(u8,u8);
void M_NVIC_Void_Pending (u8);
void M_NVIC_Void_UnPending (u8);
u8   M_NVIC_u8_ActiveRead(u8);

#endif
