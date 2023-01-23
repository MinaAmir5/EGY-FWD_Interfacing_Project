/*
 * main.c
 *
 *  Created on: 2/10/2022
 *      Author: Mina AMir Girgis
 */
/*************************************************-INLUDED_DRIVERS-*************************************************/
#include "SysTick_Interface.h"
#include "NVIC_Interface.h"
#include "GPIO_Interface.h"
#define   RCGCGPIO_REG    *(volatile u32*)0x400FE608
/*************************************************-FUNCTIONS_PROTOTYPES-********************************************/
void A_Timer0_Execution(void);
/*************************************************-GLOBAL_VARIABLES-************************************************/
u16 Global_A_U16_TimeOn=1;
u16 Global_A_U16_TimeOff=1;
u16 Global_A_U16_CounterOn=0;
u16 Global_A_U16_CounterOff=0;
/*************************************************-MAIN_FUNCTION-**************************************************/
int main()
{
	M_SysTick_Void_SysTickInit(1000);
	M_SysTick_Void_SetCallBack(A_Timer0_Execution);
	u16 Local_A_U16_InputTimeOn=0;
	u16 Local_A_U16_InputTimeOff=0;

	RCGCGPIO_REG |= 0x21;
	M_GPIO_Void_SetPinDirection(PF0_PIN,GPIO_OUTPUT);
	M_GPIO_Void_SetPinDirection(PA0_PIN,GPIO_INPUT);
	M_GPIO_Void_SetPinDirection(PA1_PIN,GPIO_INPUT);
	M_GPIO_Void_SetPinDirection(PA2_PIN,GPIO_INPUT);

	while(1)
	{

		if(M_GPIO_U8_GetPinValue(PA0_PIN)==1)
			Local_A_U16_InputTimeOn++;
		if(M_GPIO_U8_GetPinValue(PA1_PIN)==1)
			Local_A_U16_InputTimeOff++;
		if(M_GPIO_U8_GetPinValue(PA2_PIN)==1)
		{
			Global_A_U16_TimeOn=Local_A_U16_InputTimeOn;
			Global_A_U16_TimeOff=Local_A_U16_InputTimeOff;
			Local_A_U16_InputTimeOn=0;
			Local_A_U16_InputTimeOff=0;
		}
	}

}
/*************************************************-TIMERS_ISR-*************************************************/
void A_Timer0_Execution(void)
{
	if(M_GPIO_U8_GetPinValue(PF0_PIN)==1)
	{
		Global_A_U16_CounterOn++;
		if(Global_A_U16_CounterOn==Global_A_U16_TimeOn)
		{
			Global_A_U16_CounterOn=0;
			M_GPIO_Void_SetPinValue(PF0_PIN,GPIO_LOW);
		}
	}

	else if(M_GPIO_U8_GetPinValue(PF0_PIN)==0)
		{
			Global_A_U16_CounterOff++;
			if(Global_A_U16_CounterOff==Global_A_U16_TimeOff)
			{
				Global_A_U16_CounterOff=0;
			M_GPIO_Void_SetPinValue(PF0_PIN,GPIO_HIGH);
			}
		}
}



