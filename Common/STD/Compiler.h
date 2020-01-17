/*
 * Compiler.h
 *
 *  Created on: Dec 5, 2018
 *      Author: AhmedShaban
 */
 
#ifndef COMPILER_H
#define COMPILER_H

#include "Std_Types.h"
#include "Bit_Math.h"

/*
 * Compiler abstraction symbols
 */
#define LOCAL_INLINE static INLINE
#define INLINE  inline
#define STATIC  static
#define _STATIC_ static


#ifndef NULL_PTR
  #define NULL_PTR  ((void *)0)
#endif

#ifndef NULL
  #define NULL  ((void *)0)
#endif

/* AUTOMATIC used for the declaration of local pointers */
#define AUTOMATIC

/* TYPEDEF used for defining pointer types within type definitions */
#define TYPEDEF

/* Type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
   fctname     function name respectively name of the defined type
 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

/* The compiler abstraction shall define the FUNC macro for the declaration and
   definition of functions, that ensures correct syntax of function
   declarations as required by a specific compiler. - used for API functions
   rettype     return type of the function
   memclass    classification of the function itself
 */
#define FUNC(type, memclass) type

/* Pointer to constant data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define P2CONST(ptrtype, memclass, ptrclass)  const ptrtype *

/* Pointer to variable data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/* Const pointer to variable data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/* Const pointer to constant data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/* ROM constant
   type        type of the constant
   memclass    classification of the constant
 */
#define CONST(type, memclass) const type

/* RAM variables
   type        type of the variable
   memclass    classification of the variable
 */
#define VAR(type, memclass) type

#if (defined FUNC_P2CONST)
#error FUNC_P2CONST already defined
#endif


/** \brief abstraction for function declaration and definition
 **
 ** This macro abstracts the declaration and definition of functions
 ** returning a pointer to a constant and ensures the correct syntax
 ** of function declarations as required by a specific compiler.
 **
 ** \param[in] rettype return type of the function
 ** \param[in] ptrclass defines the classification of the pointers distance
 ** \param[in] memclass classification of the function itself */
/* Deviation MISRA-1 */
#define FUNC_P2CONST(rettype, ptrclass, memclass) const rettype * memclass


#define ENABLE_INTERRUPT()        (CPSIE i)
#define DISABLE_INTERRUPT()       (CPSID i)
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* COMPILER_H */
