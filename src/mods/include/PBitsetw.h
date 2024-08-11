#ifndef PBITSETW_H
#define PBITSETW_H

#include <stdio.h>
#include <stdlib.h>
#include "./PStringw.h"
// #include "..PSystem.h"
#include "./PDataTypeDefine.h"

typedef struct PBitset {
	// long bits;  //用于数据备份
    _Bool symbol;
    _Bool *store;
    long size;
} PBitset;

PBitset *Bitset(long number) ;
long GetLowBitset(PBitset *bitset) ;
long GetHighBitset(PBitset *bitset) ;
bool setBit(PBitset *bitset, unsigned long index, bool value) ;
bool setBitsetNumber(PBitset *bitset, long number) ;
long long getBitsetNumber(PBitset *bitset) ;
bool printBitsetln(PBitset *bitset, unsigned int status) ;
bool FreeBitset(PBitset *bitset) ;
bool clearBitset(PBitset *bitset) ;

//macro defines
#define __PRINT_BITSET_FORMAT_FTO 0x01
#define __PRINT_BITSET_FORMAT_OTO 0x02
#define __PRINT_BITSET_SYMBOL_ONESELF 0x04
#define __PRINT_BITSET_SYMBOL_NONE 0x08

#endif