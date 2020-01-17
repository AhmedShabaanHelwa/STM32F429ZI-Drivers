/*
 * GPIO_Type.h
 *
 *  Created on: Jan 16, 2020
 *      Author: AhmedShaban
 */

#ifndef _GPIO_TYPE_H_
#define _GPIO_TYPE_H_

#include "compiler.h"

/* 1 - Direction Type */
typedef enum{
	GPIO_enuInput = 0x00,
	GPIO_enuGpOutput = 0x01,
	GPIO_enuAlterFunction = 0x02,
	GPIO_enuAnalog = 0x03
}GPIO_tenuDirection;

/* 2 - Output Type */
typedef enum{
	GPIO_enuPushPull = 0x00,
	GPIO_enuOpenDrain = 0x01
}GPIO_tenuOutputType;

/* 3 - Output speed */
typedef enum{
	GPIO_enuLowSpeed = 0x00,
	GPIO_enuMediumSpeed = 0x01,
	GPIO_enuHighSpeed = 0x02,
	GPIO_enuVeryHighSpeed = 0x03
}GPIO_tenuOutputSpeed;

/* 4 - Pull Resistance */
typedef enum{
	GPIO_enuNoPUPD = 0x00,
	GPIO_enuPullUp = 0x01,
	GPIO_enuPullDown = 0x02
}GPIO_tenuPullResistance;

/* 5 - Configuration Type */
typedef struct{
	GPIO_tenuDirection		enuDirection;
	GPIO_tenuOutputType		enuOutputType;
	GPIO_tenuOutputSpeed	enuOutputSpeed;
	GPIO_tenuPullResistance	enuPullResistance;
	VAR(uint8, CONST_CFG_CLASS)	u8AlternateFunction;
}GPIO_tstrConfig;

#endif /* MCAL_GPIO_INCLUDE_GPIO_TYPE_H_ */
