#ifndef MCAL_NVIC_PRIVATE_H_
#define MCAL_NVIC_PRIVATE_H_

#include "STD.h"
#include "BitMath.h"

typedef struct{

	volatile u32 EN        [ 32 ];
	volatile u32 DIS       [ 32 ];
	volatile u32 PEND      [ 32 ];
	volatile u32 UNPEND    [ 32 ];
	volatile u32 ACTIVE    [ 32 ];
	volatile u32 RESERVED  [ 32 ];
	volatile u8  PRI       [128 ];

}NVIC_REG;

#define NVIC_REGs ((volatile NVIC_REG *)0xE000E100)























/*#define EN0_REG          *(volatile u32*)0xE000E100
#define EN1_REG          *(volatile u32*)0xE000E104
#define EN2_REG          *(volatile u32*)0xE000E108
#define EN3_REG          *(volatile u32*)0xE000E10C
#define EN4_REG          *(volatile u32*)0xE000E110

#define DIS0_REG         *(volatile u32*)0xE000E180
#define DIS1_REG         *(volatile u32*)0xE000E184
#define DIS2_REG         *(volatile u32*)0xE000E188
#define DIS3_REG         *(volatile u32*)0xE000E18C
#define DIS4_REG         *(volatile u32*)0xE000E190
	
#define PEND0_REG        *(volatile u32*)0xE000E200
#define PEND1_REG        *(volatile u32*)0xE000E204
#define PEND2_REG        *(volatile u32*)0xE000E208
#define PEND3_REG        *(volatile u32*)0xE000E20C
#define PEND4_REG        *(volatile u32*)0xE000E210
	
#define UNPEND0_REG      *(volatile u32*)0xE000E280
#define UNPEND1_REG      *(volatile u32*)0xE000E284
#define UNPEND2_REG      *(volatile u32*)0xE000E288
#define UNPEND3_REG      *(volatile u32*)0xE000E28C
#define UNPEND4_REG      *(volatile u32*)0xE000E290
	
#define ACTIVE0_REG      *(volatile u32*)0xE000E300
#define ACTIVE1_REG      *(volatile u32*)0xE000E304
#define ACTIVE2_REG      *(volatile u32*)0xE000E308
#define ACTIVE3_REG      *(volatile u32*)0xE000E30C
#define ACTIVE4_REG      *(volatile u32*)0xE000E310
	
#define PRI0_REG         *(volatile u32*)0xE000E400
#define PRI1_REG         *(volatile u32*)0xE000E404
#define PRI2_REG         *(volatile u32*)0xE000E408
#define PRI3_REG         *(volatile u32*)0xE000E40C
#define PRI4_REG         *(volatile u32*)0xE000E410
#define PRI5_REG         *(volatile u32*)0xE000E414
#define PRI6_REG         *(volatile u32*)0xE000E418
#define PRI7_REG         *(volatile u32*)0xE000E41C
#define PRI8_REG         *(volatile u32*)0xE000E420
#define PRI9_REG         *(volatile u32*)0xE000E424
#define PRI10_REG        *(volatile u32*)0xE000E428
#define PRI11_REG        *(volatile u32*)0xE000E42C
#define PRI12_REG        *(volatile u32*)0xE000E430
#define PRI13_REG        *(volatile u32*)0xE000E434
#define PRI14_REG        *(volatile u32*)0xE000E438
#define PRI15_REG        *(volatile u32*)0xE000E43C
*/
#endif