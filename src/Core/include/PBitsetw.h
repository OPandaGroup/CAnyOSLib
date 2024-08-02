#define PBITSETW_H

#include <stdio.h>
#include <stdlib.h>
#define __PRINT_BIT_FTO 0x01
#define __PRINT_BIT_OTO 0x02
#include "./PString.h"
#include "./PDataTypeDefine.h"

typedef struct PBitset_32 {
	unsigned long bits;
    _Bool *store;
    unsigned long size;
} PBitset32;

typedef struct PBitset_64 {
	unsigned long long bits;
    _Bool *store;
    unsigned long size;
} PBitset64;

PBitset32 *Bitset(unsigned long number) ;
PBitset64 *Bitset64(unsigned long long number) ;
unsigned long GetLowBitset(PBitset32 *bitset) ;
unsigned long GetHighBitset(PBitset32 *bitset) ;
unsigned long GetLowBitset64(PBitset64 *bitset) ;
unsigned long GetHighBitset64(PBitset64 *bitset) ;
bool setBit(PBitset32 *bitset, unsigned long number) ;
bool setBit64(PBitset64 *bitset, unsigned long long number) ;
bool setOneBit(PBitset32 *bitset, bool value) ;
void printBitsetln(PBitset32 *bitset, unsigned int status) ;
bool FreeBitset(PBitset32 *bitset) ;
bool FreeBitset64(PBitset64 *bitset) ;