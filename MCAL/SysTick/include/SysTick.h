/*
 * SysTick.h
 *
 *  Created on: Jan 15, 2020
 *      Author: AhmedShaban
 */

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "stm32f4xx.h"
#include "Compiler.h"
#include "SysTick_PCfg.h"

#define SysTick_U8RELEASE_MAJOR_VERSION			0x00U
#define SysTick_U8RELEASE_MINOR_VERSION			0x00U
#define SysTick_U8RELEASE_PATCH_VERSION			0x00U


extern FUNC(void, CODE_FLASH_CLASS)		SysTick_vidInit(void);
extern FUNC(void, CODE_FLASH_CLASS)		SysTick_vidDelay(
											VAR(uint32,AUTOMATIC)	u32Delay);
extern FUNC(uint32, CODE_FLASH_CLASS)	SysTick_u32GetCurrentTick(void);

#endif /* MCAL_SYSTICK_INCLUDE_SYSTICK_H_ */
