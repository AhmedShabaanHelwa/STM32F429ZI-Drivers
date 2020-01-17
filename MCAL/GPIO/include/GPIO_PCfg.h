/*
 * GPIO_PCfg.h
 *
 *  Created on: Jan 16, 2020
 *      Author: AhmedShaban
 */

#ifndef _GPIO_PCFG_H_
#define _GPIO_PCFG_H_

#include "Compiler.h"
#include "GPIO_Type.h"

#define GPIO_BPORTA_AVAILABLE			STD_OFF
#define GPIO_BPORTB_AVAILABLE			STD_OFF
#define GPIO_BPORTC_AVAILABLE			STD_OFF
#define GPIO_BPORTD_AVAILABLE			STD_OFF
#define GPIO_BPORTE_AVAILABLE			STD_OFF
#define GPIO_BPORTF_AVAILABLE			STD_OFF
#define GPIO_BPORTG_AVAILABLE			STD_ON

#define GPIO_U8NUM_PINS_PER_PORT		(uint8)0x10U /* !Comment: 16 pin per port */



#if(GPIO_BPORTA_AVAILABLE == STD_ON)
	extern const VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortA[];
#endif
#if(GPIO_BPORTB_AVAILABLE == STD_ON)
	extern const VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortB[];
#endif
#if(GPIO_BPORTC_AVAILABLE == STD_ON)
	extern const VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortC[];
#endif
#if(GPIO_BPORTD_AVAILABLE == STD_ON)
	extern const VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortD[];
#endif
#if(GPIO_BPORTE_AVAILABLE == STD_ON)
	extern const VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortE[];
#endif
#if(GPIO_BPORTF_AVAILABLE == STD_ON)
	extern const VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortF[];
#endif
#if(GPIO_BPORTG_AVAILABLE == STD_ON)
	extern const VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortG[];
#endif

#endif /* MCAL_GPIO_INCLUDE_GPIO_PCFG_H_ */
