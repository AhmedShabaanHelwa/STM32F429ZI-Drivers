/*
 * GPIO.c
 *
 *  Created on: Jan 16, 2020
 *      Author: AhmedShaban
 */
#include "GPIO.h"
/****************************************************************************/
/* !Comment: Private Symbols 												*/
/****************************************************************************/
#define u32LOC_1BIT_FIELD					(uint32)0x01UL
#define u32LOC_2BIT_FIELD					(uint32)0x03UL
/****************************************************************************/

/****************************************************************************/
/* !Comment: Public APIs 													*/
/****************************************************************************/

FUNC(void, CODE_FLASH_CLASS)		GPIO_vidInit(void)
{
	/* !Comment: Current Channel */
	VAR(uint8, AUTOMATIC) u8LocalChannel;
	/* !Comment: Number of pin associated to the current channel */
	VAR(uint8, AUTOMATIC) u8LocalPinNumber;
	/* !Comment: Number of port associated to the current channel */
	VAR(uint8, AUTOMATIC) u8LocalPortNumber;
	/* !Comment: Pointer to Physical Address of Port
	 *  		 associated to the current channel */
	P2VAR(GPIO_TypeDef, AUTOMATIC, SFR_CLASS)	pstrGPIOx;
	/* !Comment: Pointer to constant configuration array of the current port */
	P2CONST(GPIO_tstrConfig, AUTOMATIC, GPIO_CONST_CONST) pkastrCfg;



	/* !Comment: Temporary Configuration of Clock of Port G
	 * To be Generalized in later releases */
	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	/* !Comment: Temporary Configuration for Port G
	 * To be Generalized in later releases */
	for(	u8LocalChannel = 0x60;
			u8LocalChannel < GPIO_U8MAX_NUM_CHANNELS;
			u8LocalChannel++)
	{
		/* !Pseudo: Prepare pin number and port number */
		/* !Comment: To add check for valid channel number and report errors
		 * in later releases */
		u8LocalPinNumber = u8LocalChannel % GPIO_U8NUM_PINS_PER_PORT;
		u8LocalPortNumber = u8LocalChannel / GPIO_U8NUM_PINS_PER_PORT;

		/* !Pseudo: Map configuration of the current channel */
		switch(u8LocalPortNumber)
		{
		/* !Pseudo: Map number of port associated to the current channel,
		 * 			to physical address of current port */
		/* !Pseudo: Set the configuration array of the current channel */
#if(GPIO_BPORTA_AVAILABLE == STD_ON)
		case GPIO_U8PORTA:
			pstrGPIOx = GPIOA;
			pkastrCfg = &GPIO_akstreCfgPortA[0];
			break;
#endif
#if(GPIO_BPORTB_AVAILABLE == STD_ON)
		case GPIO_U8PORTB:
			pstrGPIOx = GPIOB;
			pkastrCfg = &GPIO_akstreCfgPortB[0];
			break;
#endif
#if(GPIO_BPORTC_AVAILABLE == STD_ON)
		case GPIO_U8PORTC:
			pstrGPIOx = GPIOC;
			pkastrCfg = &GPIO_akstreCfgPortC[0];
			break;
#endif
#if(GPIO_BPORTD_AVAILABLE == STD_ON)
		case GPIO_U8PORTD:
			pstrGPIOx = GPIOD;
			pkastrCfg = &GPIO_akstreCfgPortD[0];
			break;
#endif
#if(GPIO_BPORTE_AVAILABLE == STD_ON)
		case GPIO_U8PORTE:
			pstrGPIOx = GPIOE;
			pkastrCfg = &GPIO_akstreCfgPortE[0];
			break;
#endif
#if(GPIO_BPORTF_AVAILABLE == STD_ON)
		case GPIO_U8PORTF:
			pstrGPIOx = GPIOF;
			pkastrCfg = &GPIO_akstreCfgPortF[0];
			break;
#endif
#if(GPIO_BPORTG_AVAILABLE == STD_ON)
		case GPIO_U8PORTG:
			pstrGPIOx = GPIOG;
			pkastrCfg = &GPIO_akstreCfgPortG[0];
			break;
#endif
		default:
			/* !Comment: To report error in future releases */
			break;
		}

		/* !Pseudo: Set Channel Direction */
		/* !Pseudo: Clear Direction Field */
		pstrGPIOx -> MODER &= ~(u32LOC_2BIT_FIELD << (2 * u8LocalPinNumber));
		/* !Pseudo: Set Channel Direction */
		pstrGPIOx -> MODER |= ( (pkastrCfg[u8LocalPinNumber].enuDirection) \
									<< (2 * u8LocalPinNumber) );

		/* !Comment: Mode Dependencies */
		if( GPIO_enuInput == (pkastrCfg[u8LocalPinNumber].enuDirection) )
		{
			/* !Comment: Input track */
			/* !Pseudo: Pull Resistance Configuration */
			pstrGPIOx -> PUPDR &= ~(u32LOC_2BIT_FIELD << (2 * u8LocalPinNumber));
			pstrGPIOx -> PUPDR |= ( (pkastrCfg[u8LocalPinNumber].enuPullResistance) \
										<< (2 * u8LocalPinNumber) );
		}
		else if( GPIO_enuGpOutput == (pkastrCfg[u8LocalPinNumber].enuDirection) || \
				GPIO_enuAlterFunction == (pkastrCfg[u8LocalPinNumber].enuDirection))
		{
			/* !Comment: Input track */

			/* !Psuedo: Output Type Configuration */
			pstrGPIOx -> OTYPER &= ~(u32LOC_1BIT_FIELD << (u8LocalPinNumber));
			pstrGPIOx -> OTYPER |= ((pkastrCfg[u8LocalPinNumber].enuOutputType)\
										<< (u8LocalPinNumber));

			/* !Comment: To refactor and add support of System Configuration,
			 * Compensation Cell in next release */
			/* !Pseudo: Check High Speed output */
			if( GPIO_enuHighSpeed == (pkastrCfg[u8LocalPinNumber].enuOutputSpeed) || \
				GPIO_enuAlterFunction == (pkastrCfg[u8LocalPinNumber].enuOutputSpeed))
			{
				/* 1 - Enable SysCfg */
				RCC -> AHB2ENR |= RCC_APB2ENR_SYSCFGEN;
				/* 2 - Enable Compensation Cell */
				SYSCFG -> CMPCR |= SYSCFG_CMPCR_CMP_PD;
				/* 3 - Wait for compensation Cell to be ready */
				while( 0x00 == ((SYSCFG -> CMPCR) & SYSCFG_CMPCR_READY));
			}

			/* !Pseudo: Output Speed Configuration */
			pstrGPIOx -> OSPEEDR &= ~(u32LOC_2BIT_FIELD << (2*u8LocalPinNumber));
			pstrGPIOx -> OSPEEDR |= ( (pkastrCfg[u8LocalPinNumber].enuOutputSpeed) \
													<< (2 * u8LocalPinNumber) );

		}/* !Comment: End of else if of Mode Dependencies */
		else
		{
			/* !Comment: Do Nothing - Analog Mode */

		}/* !Comment: End of if-else of Mode Dependencies */


		/* !Pseudo: Alternate Function Configuration */

	}/* !Comment: End of for loop */
}
/****************************************************************************/
FUNC(void, CODE_FLASH_CLASS)		GPIO_vidWriteChannel(
											VAR(uint8, AUTOMATIC) u8Channel,
							VAR(GPIO_tenuChannelState, AUTOMATIC) enuValue)
{
	/* !Comment: Number of pin associated to the current channel */
	VAR(uint8, AUTOMATIC) u8LocalPinNumber;
	/* !Comment: Number of port associated to the current channel */
	VAR(uint8, AUTOMATIC) u8LocalPortNumber;
	/* !Comment: Pointer to Physical Address of Port
	 *  		 associated to the current channel */
	P2VAR(GPIO_TypeDef, AUTOMATIC, SFR_CLASS)	pstrGPIOx;



	/* !Pseudo: Prepare pin number and port number */
	/* !Comment: To add check for valid channel number and report errors
	 * in later releases */
	u8LocalPinNumber = u8Channel % GPIO_U8NUM_PINS_PER_PORT;
	u8LocalPortNumber = u8Channel / GPIO_U8NUM_PINS_PER_PORT;

	/* !Pseudo: Map configuration of the current channel */
	switch(u8LocalPortNumber)
	{
	/* !Pseudo: Map number of port associated to the current channel,
	 * 			to physical address of current port */
	/* !Pseudo: Set the configuration array of the current channel */
#if(GPIO_BPORTA_AVAILABLE == STD_ON)
	case GPIO_U8PORTA:
		pstrGPIOx = GPIOA;
		break;
#endif
#if(GPIO_BPORTB_AVAILABLE == STD_ON)
	case GPIO_U8PORTB:
		pstrGPIOx = GPIOB;
		break;
#endif
#if(GPIO_BPORTC_AVAILABLE == STD_ON)
	case GPIO_U8PORTC:
		pstrGPIOx = GPIOC;
		break;
#endif
#if(GPIO_BPORTD_AVAILABLE == STD_ON)
	case GPIO_U8PORTD:
		pstrGPIOx = GPIOD;
		break;
#endif
#if(GPIO_BPORTE_AVAILABLE == STD_ON)
	case GPIO_U8PORTE:
		pstrGPIOx = GPIOE;
		break;
#endif
#if(GPIO_BPORTF_AVAILABLE == STD_ON)
	case GPIO_U8PORTF:
		pstrGPIOx = GPIOF;
		break;
#endif
#if(GPIO_BPORTG_AVAILABLE == STD_ON)
	case GPIO_U8PORTG:
		pstrGPIOx = GPIOG;
		break;
#endif
	default:
		/* !Comment: To report error in future releases */
		break;
	}

	do{
	pstrGPIOx -> ODR &= ~(0x01 << u8LocalPinNumber);
	pstrGPIOx -> ODR |= ( (uint32)enuValue << u8LocalPinNumber );
	}while(0);
}
/****************************************************************************/
FUNC(GPIO_tenuChannelState, CODE_FLASH_CLASS)	GPIO_enuReadChannel(
											VAR(uint8, AUTOMATIC) u8Channel);
/****************************************************************************/
FUNC(void, CODE_FLASH_CLASS)		GPIO_vidToggleChannel(
											VAR(uint8, AUTOMATIC) u8Channel);
/****************************************************************************/
FUNC(void, CODE_FLASH_CLASS)		GPIO_vidSetChannelHigh(
											VAR(uint8, AUTOMATIC) u8Channel);
/****************************************************************************/
FUNC(void, CODE_FLASH_CLASS)		GPIO_vidSetChannelLow(
											VAR(uint8, AUTOMATIC) u8Channel);
/****************************************************************************/
FUNC(void, CODE_FLASH_CLASS)		GPIO_vidWritePort(
											VAR(uint8, AUTOMATIC) u8Port,
											VAR(uint32, AUTOMATIC) enuValue);
/****************************************************************************/
FUNC(uint32, CODE_FLASH_CLASS)	GPIO_u32ReadPort(
											VAR(uint8, AUTOMATIC) u8Port);
/****************************************************************************/
FUNC(void, CODE_FLASH_CLASS)		GPIO_vidTogglePort(
											VAR(uint8, AUTOMATIC) u8Port);
/****************************************************************************/
