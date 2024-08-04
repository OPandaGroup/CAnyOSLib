#include "../include/Widgets/PBitsetw.h"

PBitset32 *Bitset(long number) {
    PBitset32 *bitset = malloc(sizeof(PBitset32));
    bitset->bits = number;
    bitset->size = 1;
    bitset->store = NULL ;
    upDateBitset(bitset) ;
    return bitset;
}

PBitset64 *Bitset64(long long number) {
    PBitset64 *bitset = malloc(sizeof(PBitset64));
    bitset->bits = number;
    bitset->store = malloc(sizeof(char *));
    return bitset;
}

void upDateBitset(PBitset32 *bitset) {
    bitset->symbol = bitset->bits >= 0 ? false : true;
    long cp = abs(bitset->bits);
    bitset->size = 1;
    bitset->store = realloc(bitset->store, bitset->size*sizeof(_Bool)) ;
    while (cp != 0) {
        bitset->store[bitset->size - 1] = cp & 1;
        cp = cp >> 1;
        bitset->size++;
        bitset->store = realloc(bitset->store, bitset->size*sizeof(_Bool)) ;
    }
    bitset->store = realloc(bitset->store, (--bitset->size)*sizeof(_Bool));
    return ;
}

long GetLowBitset(PBitset32 *bitset) { //The low is 0
    long i = 0;
    long cp = bitset->bits;
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
long GetHighBitset(PBitset32 *bitset) { // The high is 1
    long i = 0;
    long cp = bitset->bits;
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

long GetLowBitset64(PBitset64 *bitset) {
    long long i = 0;
    long long cp = bitset->bits;
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
long GetHighBitset64(PBitset64 *bitset) {
    long long i = 0;
    long long cp = bitset->bits;
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

bool setBit(PBitset32 *bitset, long number) {

    return true;
}

bool setBit64(PBitset64 *bitset, long long number) {
    return true;
}

bool setOneBit(PBitset32 *bitset, bool value){

}

bool printBitsetln(PBitset32 *bitset, unsigned int status) {
    upDateBitset(bitset); //保证数据是最新的
    switch (status) {
        case __PRINT_BITSET_FORMAT_FTO:
            printBitsetln(bitset, __PRINT_BITSET_FORMAT_FTO | __PRINT_BITSET_SYMBOL_NONE);
            break;
        case __PRINT_BITSET_FORMAT_OTO:
            printBitsetln(bitset, __PRINT_BITSET_FORMAT_FTO | __PRINT_BITSET_SYMBOL_NONE);
            break;
        case __PRINT_BITSET_FORMAT_OTO | __PRINT_BITSET_SYMBOL_NONE:
            for(long long i = bitset->size - 1; i >= 0; i++)
                printf("%d", bitset->store[i]);
            break;
        case __PRINT_BITSET_FORMAT_OTO | __PRINT_BITSET_SYMBOL_ONESELF:
            printf("symbol :%d\n", bitset->symbol) ;
            for(long long i = bitset->size - 1; i >= 0; i++)
                printf("%d", bitset->store[i]);
            break;
        case __PRINT_BITSET_FORMAT_FTO | __PRINT_BITSET_SYMBOL_NONE:
            if(bitset->size % 4 == 0){
                for(long long i = bitset->size - 1; i >= 0; i--){
                    if(i % 4 == 0)
                        printf(" ");
                    printf("%d", bitset->store[i]);
                }
            }else{
                int df = 4 - bitset->size % 4;
                for(int index = 0; index < df; index++)
                    printf(" ");
                for(long long i = bitset->size - 1; i >= 0; i--){
                    printf("%d", bitset->store[i]);
                    if((i + df - 1) % 4 == 0)
                        printf(" ");
                }
            }
            break;
        case __PRINT_BITSET_FORMAT_FTO | __PRINT_BITSET_SYMBOL_ONESELF:
            printf("symbol :%d\n", bitset->symbol) ;
            if(bitset->size % 4 == 0){
                for(long long i = bitset->size - 1; i >= 0; i--){
                    if(i % 4 == 0)
                        printf(" ");
                    printf("%d", bitset->store[i]);
                }
            }else{
                int df = 4 - bitset->size % 4;
                for(int index = 0; index < df; index++)
                    printf(" ");
                for(long long i = bitset->size - 1; i >= 0; i--){
                    printf("%d", bitset->store[i]);
                    if((i + df - 1) % 4 == 0)
                        printf(" ");
                }
            } 
            break;
        default:
            printf("error status\n");
            return false;
            break;
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