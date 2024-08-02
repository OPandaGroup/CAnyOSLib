#include "../include/PBitsetw.h"

PBitset32 *Bitset(unsigned long number) {
    PBitset32 *bitset = malloc(sizeof(PBitset32));
    bitset->bits = number;
    bitset->store = malloc(sizeof(char *));
    return bitset;
}

PBitset64 *Bitset64(unsigned long long number) {
    PBitset64 *bitset = malloc(sizeof(PBitset64));
    bitset->bits = number;
    bitset->store = malloc(sizeof(char *));
    return bitset;
}

unsigned long GetLowBitset(PBitset32 *bitset) { //The low is 0
    unsigned long i = 0;
    unsigned long cp = bitset->bits;
    bitset->size = 1;
    bitset->store = realloc(bitset->store, bitset->size*sizeof(_Bool)) ;
    while (cp != 0) {
        bitset->store[bitset->size - 1] = cp & 1;
        if(cp & 1 == 0)
            i++;
        cp = cp >> 1;
        bitset->size++;
        bitset->store = realloc(bitset->store, bitset->size*sizeof(_Bool)) ;
    }
    bitset->store = realloc(bitset->store, (--bitset->size)*sizeof(_Bool));
    return i;
}
unsigned long GetHighBitset(PBitset32 *bitset) { // The high is 1
    unsigned long i = 0;
    unsigned long cp = bitset->bits;
    while (cp != 0) {
        bitset->store[bitset->size - 1] = cp & 1;
        if(cp & 1 == 1)
            i++;
        cp = cp >> 1;
        bitset->size++;
        bitset->store = realloc(bitset->store, bitset->size*sizeof(_Bool)) ;
    }
    bitset->store = realloc(bitset->store, (--bitset->size)*sizeof(_Bool));
    return i;
}

unsigned long GetLowBitset64(PBitset64 *bitset) {
    unsigned long long i = 0;
    unsigned long long cp = bitset->bits;
    while (cp != 0) {
        bitset->store[bitset->size - 1] = cp & 1;
        if(cp & 1 == 0)
            i++;
        cp = cp >> 1;
        bitset->size++;
        bitset->store = realloc(bitset->store, bitset->size*sizeof(_Bool)) ;
    }
    bitset->store = realloc(bitset->store, (--bitset->size)*sizeof(_Bool));
    return i;
}
unsigned long GetHighBitset64(PBitset64 *bitset) {
    unsigned long long i = 0;
    unsigned long long cp = bitset->bits;
    while (cp != 0) {
        bitset->store[bitset->size - 1] = cp & 1;
        if(cp & 1 == 0)
            i++;
        cp = cp >> 1;
        bitset->size++;
        bitset->store = realloc(bitset->store, bitset->size*sizeof(_Bool)) ;
    }
    bitset->store = realloc(bitset->store, (--bitset->size)*sizeof(_Bool));
}

bool setBit(PBitset32 *bitset, unsigned long number) {

    return true;
}

bool setBit64(PBitset64 *bitset, unsigned long long number) {
    return true;
}

bool setOneBit(PBitset32 *bitset, bool value){

}

void printBitsetln(PBitset32 *bitset, unsigned int status) {
    setBit(bitset, bitset->bits); //保证数据是最新的
    if(status == __PRINT_BIT_FTO){
        printf("%llu\n", GetLowBitset(bitset));
    }else if(status == __PRINT_BIT_OTO){
        printf("%s\n", bitset->store);
    }else{
        printf("Error: Invalid status\n");
    }
}

bool FreeBitset(PBitset32 *bitset) {
    free(bitset);
    return true;
}

bool FreeBitset64(PBitset64 *bitset) {
    free(bitset);
    return true;
}