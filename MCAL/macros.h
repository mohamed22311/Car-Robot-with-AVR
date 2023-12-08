/*
 * macros.h
 *
 *  Created on: Jun 12, 2023
 *      Author: Mohamed
 */

#ifndef BASE_MACROS_H_
#define BASE_MACROS_H_



#define SET_BIT(REG,BIT)	REG |= (1<<BIT)
#define CLR_BIT(REG,BIT)	REG &= ~(1<<BIT)
#define TOGGLE_BIT(REG,BIT)	REG ^= (1<<BIT)
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num))
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )
#define BIT_IS_CLR(REG,BIT) ( !(REG & (1<<BIT)) )
#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )


#define NULL_PTR    ((void*)0)


#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif


#define HIGH        (1u)
#define LOW         (0u)


typedef unsigned char 		  bool;			  /* 	0 1 TRUE FALSE HIGH LOW      */
typedef unsigned char         u8;          /*           0 .. 255              */
typedef signed char           s8;          /*        -128 .. +127             */
typedef unsigned short        u16;         /*           0 .. 65535            */
typedef signed short          s16;         /*      -32768 .. +32767           */
typedef unsigned long         u32;         /*           0 .. 4294967295       */
typedef signed long           s32;         /* -2147483648 .. +2147483647      */
typedef unsigned long long    u64;         /*       0 .. 18446744073709551615  */
typedef signed long long      s64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float                 f32;
typedef double                f64;
typedef long double 		  f128;

#endif /* BASE_MACROS_H_ */
