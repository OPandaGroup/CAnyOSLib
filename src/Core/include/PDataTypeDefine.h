//DataType Definition
//这个文件是方便跨平台使用的数据类型定义文件
//
// @date:2024/07/16
// @file:PDataTypeConversion.h
// @author:Writing 
// @copyright: Panda, 2024
//

#ifndef PDataType
#define PDataType

//值定义 
#define None "None"
#define IS_NONE_Pointer NULL
#define IS_NONE_STR ""
#define SIZE_STRING sizeof(char *)
#define INT64_MAX 9223372036854775807
#define INT64_MIN -9223372036854775808
#define INT32_MAX 2147483647
#define INT32_MIN -2147483648
#define INT16_MAX 32767
#define INT16_MIN -32768
#define INT8_MAX 127
#define INT8_MIN -128

//类型定义
typedef char* STRING;
typedef double __DOUBLE;
typedef float __FLOAT;
typedef unsigned long long __UINT64;
typedef unsigned int __UINT32;
typedef unsigned short __UINT16;
typedef unsigned char __UINT8;
typedef long long __INT64;
typedef int __INT32;
typedef short __INT16;
typedef char __INT8;
typedef unsigned long long ULLONG;
typedef unsigned char UCHAR;
typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef unsigned long UL;
typedef unsigned long long ULL;
typedef long long Size_T;
typedef int INT;
typedef unsigned long long POPTION;
typedef char CHAR;
typedef enum {
    false,
    true
}Bool;
typedef char * string;
typedef ULL ull;
typedef Bool bool;

#endif