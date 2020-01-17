/*
 * SysTick.c
 *
 *  Created on: Jan 15, 2020
 *      Author: AhmedShaban
 */


#include "SysTick.h"
#include "SysTick_Callback.h"


volatile VAR(uint32, DATA_CLASS)	SysTick_u32eCounter = 0;



FUNC(void, CODE_FLASH_CLASS)		SysTick_vidInit(void)
{
	SysTick_Config(SysTick_U8PRESCALER);
}



FUNC(void, CODE_FLASH_CLASS)		SysTick_vidDelay(
											VAR(uint32,AUTOMATIC)	u32Delay)
{
	VAR(uint32, AUTOMARIC)	u32LocalCurrTick;
	u32LocalCurrTick = SysTick_u32GetCurrentTick();

	while( ( SysTick_u32eCounter - u32LocalCurrTick ) < (u32Delay));
}



FUNC(uint32, CODE_FLASH_CLASS)	SysTick_u32GetCurrentTick(void)
{
	return (SysTick_u32eCounter);
}
