#ifndef PBITSETW_H
#define PBITSETW_H

#include <stdio.h>
#include <stdlib.h>
#include "./PStringw.h"
#include "../PSystem.h"
#include "./PDataTypeDefine.h"

typedef struct PBitset_32 {
	long bits;
    _Bool symbol;
    _Bool *store;
    long size;
} PBitset32;

typedef struct PBitset_64 {
	long long bits;
    _Bool *store;
    long size;
} PBitset64;

PBitset32 *Bitset(long number) ;
PBitset64 *Bitset64(long long number) ;
long GetLowBitset(PBitset32 *bitset) ;
long GetHighBitset(PBitset32 *bitset) ;
long GetLowBitset64(PBitset64 *bitset) ;
long GetHighBitset64(PBitset64 *bitset) ;
void upDateBitset(PBitset32 *bitset) ;
bool setBit(PBitset32 *bitset, long number) ;
bool setBit64(PBitset64 *bitset, long long number) ;
bool setOneBit(PBitset32 *bitset, bool value) ;
bool printBitsetln(PBitset32 *bitset, unsigned int status) ;
bool FreeBitset(PBitset32 *bitset) ;
bool FreeBitset64(PBitset64 *bitset) ;

//macro defines
#define __PRINT_BITSET_FORMAT_FTO 0x01
#define __PRINT_BITSET_FORMAT_OTO 0x02
#define __PRINT_BITSET_SYMBOL_ONESELF 0x04
#define __PRINT_BITSET_SYMBOL_NONE 0x08

#endif