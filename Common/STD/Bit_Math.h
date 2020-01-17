/*
 * BIT_MATH.h
 *
 *  Created on: May 11, 2019
 *      Author: AhmedShaban
 */

#ifndef GENERIC_BIT_MATH_H_
#define GENERIC_BIT_MATH_H_

/* !Comment: 1- Basic bit operation */
#define SET_BIT(REG,BITNO)		( REG |= (1 << BITNO) )
#define CLEAR_BIT(REG,BITNO)	( REG &= ~(1 << BITNO) )
#define TOGGLE_BIT(REG,BITNO)	( REG ^= (1 << BITNO) )

/* !Comment: 2- Basic bit status operation */
#define IS_BIT_SET(REG,BITNO)	( REG & (1 << BITNO) )
#define IS_BIT_CLEAR(REG,BITNO)	( !(REG & (1 << BITNO) ) )

/* !Comment: 3- Advanced bit operation */
#define SET_BIT_VALUE(REG,BITNO,VAL)		do{\
												CLEAR_BIT(REG,BITNO);	\
												REG |= (VAL << BITNO); \
												}while(0);

#define GET_BIT_VALUE(REG,BITNO)			( ( REG & (1 << BITNO) ) >> BITNO )


/* !Comment: Concatenation operations */
#define CONC_BITS(B7,B6,B5,B4,B3,B2,B1,B0)		CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)		0b##B7##B6##B5##B4##B3##B2##B1##B0

#endif /* 01_COMMON_02_GENERIC_BIT_MATH_H_ */
