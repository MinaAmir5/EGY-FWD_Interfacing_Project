#include "NVIC_Interface.h"
#include "NVIC_Private.h"

void M_NVIC_Void_EnableInterrupt (u8 Copy_U8_VectorNumber)
{
	u8 Local_U8_RegNumber=Copy_U8_VectorNumber/32;
	u8 Local_U8_BitNumber=Copy_U8_VectorNumber%32;
	NVIC_REGs -> EN[Local_U8_RegNumber] = (1 << Local_U8_BitNumber);
}
void M_NVIC_Void_DisableInterrupt (u8 Copy_U8_VectorNumber)
{
	u8 Local_U8_RegNumber=Copy_U8_VectorNumber/32;
	u8 Local_U8_BitNumber=Copy_U8_VectorNumber%32;
	NVIC_REGs -> DIS[Local_U8_RegNumber] = 1 << Local_U8_BitNumber;
}
void M_NVIC_Void_SetPriority(u8 Copy_U8_VectorNumber,u8 Copy_U8_IntPriority)
{
	u8 Local_U8_RegNumber=Copy_U8_VectorNumber/32;
	NVIC_REGs -> PRI[Local_U8_RegNumber] = (Copy_U8_IntPriority << 5);
}
void M_NVIC_Void_Pending (u8 Copy_U8_VectorNumber)
{
	u8 Local_U8_RegNumber=Copy_U8_VectorNumber/32;
	u8 Local_U8_BitNumber=Copy_U8_VectorNumber%32;
	NVIC_REGs -> PEND[Local_U8_RegNumber] = 1 << Local_U8_BitNumber;
}
void M_NVIC_Void_UnPending (u8 Copy_U8_VectorNumber)
{
	u8 Local_U8_RegNumber=Copy_U8_VectorNumber/32;
	u8 Local_U8_BitNumber=Copy_U8_VectorNumber%32;
	NVIC_REGs -> UNPEND[Local_U8_RegNumber] = 1 << Local_U8_BitNumber;
}
u8   M_NVIC_u8_ActiveRead(u8 Copy_U8_VectorNumber)
{
	u8 Local_U8_RegNumber=Copy_U8_VectorNumber/32;
	u8 Local_U8_BitNumber=Copy_U8_VectorNumber%32;
	u8 Local_U8_ActiveRead = GET_BIT(NVIC_REGs -> ACTIVE[Local_U8_RegNumber] , (1 << Local_U8_BitNumber));
	return Local_U8_ActiveRead;
}
