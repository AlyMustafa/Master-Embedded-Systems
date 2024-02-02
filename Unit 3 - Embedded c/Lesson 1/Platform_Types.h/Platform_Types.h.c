#ifndef AUTOSAR_PLATFORM_TYPES_H_
#define AUTOSAR_PLATFORM_TYPES_H_

/*------------bool definition---------------*/
#include <stdbool.h>
#ifndef _Bool
#define _Bool unsigned char
#endif

/*------------SYMPOLES---------------*/
#define CPU_TYPE                 CPU_TYPE_32
#define CPU_BIT_ORDER            MSB_FIRST
#define CPU_BYTE_ORDER           HIGH_BYTE_FIRST

/*------boolean(TRUE OR FALSE)PLATFORM------*/
#ifndef FALSE
#define FALSE         (boolean)false
#endif
#ifndef TURE
#define TRUE          (boolean)TRUE
#endif

/*----------------------------------------*-

/*   boolean   */
typedef _Bool                    boolean;

/*-------UnSigned DATA TYPES--------*/
typedef unsigned char            uint8;
typedef unsigned short           uint16;
typedef unsigned int             uint32;
typedef unsigned float           uint32;
typedef unsigned double          uint64;
typedef unsigned long long       uint64;
typedef unsigned long double     uint80;

/*-------Signed DATA TYPES--------*/
typedef signed char            sint8;
typedef signed short           sint16;
typedef signed int             sint32;
typedef signed float           sint32;
typedef signed double          sint64;
typedef signed long long       sint64;
typedef signed long double     sint80;

/*-------Volatile UnSigned DATA TYPES--------*/
typedef volatile unsigned char            vuint8;
typedef volatile unsigned short           vuint16;
typedef volatile unsigned int             vuint32;
typedef volatile unsigned float           vuint32;
typedef volatile unsigned double          vuint64;
typedef volatile unsigned long long       vuint64;
typedef volatile unsigned long double     vuint80;

/*-------Volatile Signed DATA TYPES--------*/
typedef volatile signed char            vsint8;
typedef volatile signed short           vsint16;
typedef volatile signed int             vsint32;
typedef volatile signed float           vsint32;
typedef volatile signed double          vsint64;
typedef volatile signed long long       vsint64;
typedef volatile signed long double     vsint80;

#endif




