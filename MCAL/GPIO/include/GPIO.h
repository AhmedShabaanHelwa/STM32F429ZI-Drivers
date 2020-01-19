/*
 * GPIO.h
 *
 *  Created on: Jan 16, 2020
 *      Author: AhmedShaban
 */

#ifndef _GPIO_H_
#define _GPIO_H_

#include "Compiler.h"
#include "stm32f4xx.h"
#include "GPIO_PCfg.h"

/****************************************************************************/
/* !Comment: Public Types 													*/
/****************************************************************************/
typedef enum{
	GPIO_ChannelLow = 0x00,
	GPIO_ChannelHigh = 0x01
}GPIO_tenuChannelState;

/* 1 - Ports */
#define GPIO_U8PORTA				(uint8)0x00
#define GPIO_U8PORTB				(uint8)0x01
#define GPIO_U8PORTC				(uint8)0x02
#define GPIO_U8PORTD				(uint8)0x03
#define GPIO_U8PORTE				(uint8)0x04
#define GPIO_U8PORTF				(uint8)0x05
#define GPIO_U8PORTG				(uint8)0x06

/* 2 - Channels */
/* Port A Channels */
#define GPIO_U8CHANNEL_0			(uint8)0x00
#define GPIO_U8CHANNEL_1			(uint8)0x01
#define GPIO_U8CHANNEL_2			(uint8)0x02
#define GPIO_U8CHANNEL_3			(uint8)0x03
#define GPIO_U8CHANNEL_4			(uint8)0x04
#define GPIO_U8CHANNEL_5			(uint8)0x05
#define GPIO_U8CHANNEL_6			(uint8)0x06
#define GPIO_U8CHANNEL_7			(uint8)0x07
#define GPIO_U8CHANNEL_8			(uint8)0x08
#define GPIO_U8CHANNEL_9			(uint8)0x09
#define GPIO_U8CHANNEL_10			(uint8)0x0A
#define GPIO_U8CHANNEL_11			(uint8)0x0B
#define GPIO_U8CHANNEL_12			(uint8)0x0C
#define GPIO_U8CHANNEL_13			(uint8)0x0D
#define GPIO_U8CHANNEL_14			(uint8)0x0E
#define GPIO_U8CHANNEL_15			(uint8)0x0F

/* Port G Channels */
#define GPIO_U8CHANNEL_96			(uint8)0x60
#define GPIO_U8CHANNEL_97			(uint8)0x61
#define GPIO_U8CHANNEL_98			(uint8)0x62
#define GPIO_U8CHANNEL_99			(uint8)0x63
#define GPIO_U8CHANNEL_100			(uint8)0x64
#define GPIO_U8CHANNEL_101			(uint8)0x65
#define GPIO_U8CHANNEL_102			(uint8)0x66
#define GPIO_U8CHANNEL_103			(uint8)0x67
#define GPIO_U8CHANNEL_104			(uint8)0x68
#define GPIO_U8CHANNEL_105			(uint8)0x69
#define GPIO_U8CHANNEL_106			(uint8)0x6A
#define GPIO_U8CHANNEL_107			(uint8)0x6B
#define GPIO_U8CHANNEL_108			(uint8)0x6C
#define GPIO_U8CHANNEL_109			(uint8)0x6D	/*GREEN LED*/
#define GPIO_U8CHANNEL_110			(uint8)0x6E /*RED LED*/
#define GPIO_U8CHANNEL_111			(uint8)0x6F

#define GPIO_U8MAX_NUM_CHANNELS		(uint8)0x6F


/****************************************************************************/
/* !Comment: Public APIs 													*/
/****************************************************************************/
extern FUNC(void, CODE_FLASH_CLASS)		GPIO_vidInit(void);

extern FUNC(void, CODE_FLASH_CLASS)		GPIO_vidWriteChannel(
											VAR(uint8, AUTOMATIC) u8Channel,
							VAR(GPIO_tenuChannelState, AUTOMATIC) enuValue);

extern FUNC(GPIO_tenuChannelState, CODE_FLASH_CLASS)	GPIO_enuReadChannel(
											VAR(uint8, AUTOMATIC) u8Channel);

extern FUNC(void, CODE_FLASH_CLASS)		GPIO_vidToggleChannel(
											VAR(uint8, AUTOMATIC) u8Channel);

extern FUNC(void, CODE_FLASH_CLASS)		GPIO_vidSetChannelHigh(
											VAR(uint8, AUTOMATIC) u8Channel);

extern FUNC(void, CODE_FLASH_CLASS)		GPIO_vidSetChannelLow(
											VAR(uint8, AUTOMATIC) u8Channel);


extern FUNC(void, CODE_FLASH_CLASS)		GPIO_vidWritePort(
											VAR(uint8, AUTOMATIC) u8Port,
											VAR(uint32, AUTOMATIC) enuValue);

extern FUNC(uint32, CODE_FLASH_CLASS)	GPIO_u32ReadPort(
											VAR(uint8, AUTOMATIC) u8Port);

extern FUNC(void, CODE_FLASH_CLASS)		GPIO_vidTogglePort(
											VAR(uint8, AUTOMATIC) u8Port);

#endif /* MCAL_GPIO_INCLUDE_GPIO_H_ */
