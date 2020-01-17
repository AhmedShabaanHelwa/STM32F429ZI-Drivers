/*
 * GPIO_LCfg.c
 *
 *  Created on: Jan 16, 2020
 *      Author: AhmedShaban
 */


#include "GPIO_PCfg.h"

#if(GPIO_BPORTA_AVAILABLE == STD_ON)
	VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortA[];
#endif
#if(GPIO_BPORTB_AVAILABLE == STD_ON)
	VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortB[];
#endif
#if(GPIO_BPORTC_AVAILABLE == STD_ON)
	VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortC[];
#endif
#if(GPIO_BPORTD_AVAILABLE == STD_ON)
	VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortD[];
#endif
#if(GPIO_BPORTE_AVAILABLE == STD_ON)
	VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortE[];
#endif
#if(GPIO_BPORTF_AVAILABLE == STD_ON)
	VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortF[];
#endif
#if(GPIO_BPORTG_AVAILABLE == STD_ON)
	const VAR(GPIO_tstrConfig, GPIO_CONST)	GPIO_akstreCfgPortG[16] =
	{
		/* Index 0 - Pin 0 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 1 - Pin 1 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 2 - Pin 2 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 3 - Pin 3 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 4 - Pin 4 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 5 - Pin 5 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 6 - Pin 6 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 7 - Pin 7 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 8 - Pin 8 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 9 - Pin 9 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 10 - Pin 10 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 11 - Pin 11 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 12 - Pin 12 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 13 - Pin 13 */
		{GPIO_enuGpOutput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 14 - Pin 14 */
		{GPIO_enuGpOutput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00},
		/* Index 15 - Pin 15 */
		{GPIO_enuInput, GPIO_enuPushPull, GPIO_enuLowSpeed, GPIO_enuNoPUPD, 0x00}
	};
#endif
