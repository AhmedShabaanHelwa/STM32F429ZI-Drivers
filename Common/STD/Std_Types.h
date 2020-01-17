/* Static Architecture
 * Component	: Common
 * Module		: STD_TYPES.h
 *
 * Created on	: May 11, 2019
 * Author		: AhmedShaban
 */

#ifndef STDTYPES_STD_TYPES_H_
#define STDTYPES_STD_TYPES_H_

/* !Comment: 1- Integral data types */

typedef unsigned char 	uint8;
typedef signed char 	sint8;

typedef unsigned short	uint16;
typedef signed short	sint16;

typedef unsigned long	uint32;
typedef signed long		sint32;

/* !Comment: 2- Floating point data types */
typedef float	f32;
typedef	double	f64;

/* !Comment: 3- Boolean data type */
typedef enum{
	flase = 0,
	true
}tBoolean;

#define STD_ON				1U
#define STD_OFF				0U

#define STD_HIGH			1U
#define STD_LOW				0U

typedef unsigned char Std_Return;

#endif /* 01_COMMON_01_STDTYPES_STD_TYPES_H_ */
