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

unsigned long GetLowBitset(PBitset32 *bitset) {
    unsigned long i = 0;
    unsigned long cp = bitset->bits;
    unsigned long number = 0;
    while (cp != 0) {
        bitset->store[number] = '0' + (cp & 1);
        if(cp & 1 == 0)
            i++;
        cp = cp >> 1;
        number++;
    }
    bitset->store[number] = '\0';
    bitset->store = stringFlip(bitset->store);
    return i;
}
unsigned long GetHighBitset(PBitset32 *bitset) {
    unsigned long i = 0;
    unsigned long number = 0;
    unsigned long cp = bitset->bits;
    while (cp != 0) {
        bitset->store[number] = '0' + (cp & 1);
        if(cp & 1 == 1)
            i++;
        cp = cp >> 1;
        number++;
    }
    bitset->store[number] = '\0';
    bitset->store = stringFlip(bitset->store);
    return i;
}

unsigned long GetLowBitset64(PBitset64 *bitset) {
    unsigned long long i = 0;
    unsigned long long cp = bitset->bits;
    unsigned long long number = 0;
    while (cp != 0) {
        bitset->store[number] = '0' + (cp & 1);
        if(cp & 1 == 0)
            i++;
        cp = cp >> 1;
        number++;
    }
    bitset->store[number] = '\0';
    bitset->store = stringFlip(bitset->store);
    return i;
}
unsigned long GetHighBitset64(PBitset64 *bitset) {
    unsigned long long i = 0;
    unsigned long long number = 0;
    unsigned long long cp = bitset->bits;
    while (cp != 0) {
        bitset->store[number] = '0' + (cp & 1);
        if(cp & 1 == 1)
            i++;
        cp = cp >> 1;
        number++;
    }
    bitset->store[number] = '\0';
    bitset->store = stringFlip(bitset->store);
    return i;
}

bool setBit(PBitset32 *bitset, unsigned long number) {
    bitset->bits = number;
    unsigned long num = 0;
    unsigned long cp = bitset->bits;
    while (cp != 0) {
        bitset->store[num] = '0' + (cp & 1);
        cp = cp >> 1;
        num++;
    }
    bitset->store[num] = '\0';
    bitset->store = stringFlip(bitset->store);
    return true;
}

bool setBit64(PBitset64 *bitset, unsigned long long number) {
    bitset->bits = number;
    unsigned long long num = 0;
    unsigned long long cp = bitset->bits;
    while (cp != 0) {
        bitset->store[num] = '0' + (cp & 1);
        cp = cp >> 1;
        num++;
    }
    bitset->store[num] = '\0';
    bitset->store = stringFlip(bitset->store);
    return true;
}

bool setOneBit(PBitset32 *bitset, bool value){

}

void printBitsetln(PBitset32 *bitset, unsigned int status) {
    setBit(bitset, bitset->bits); //保证数据是最新的
    if(status == __PRINT_BIT_FTO){
        if(bitset->bits % 4 == 0){
            for(unsigned int i = 0; i < strlen(bitset->store); i++){
                printf("%c", bitset->store[i]);
                if(i % 4 == 3)
                    printf(" ");
            }
        }else{
            for(unsigned int i = 0; i < strlen(bitset->store); i++){
                printf("%c", bitset->store[i]);
                if(i % 4 == 0)
                    printf(" ");
            }
        }
    }
    printf("%s\n", bitset->store);
}

bool FreeBitset(PBitset32 *bitset) {
    free(bitset);
    return true;
}

bool FreeBitset64(PBitset64 *bitset) {
    free(bitset);
    return true;
}