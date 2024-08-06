#include "../include/Widgets/PBitsetw.h"

PBitset *Bitset(long number) {
    PBitset *bitset = malloc(sizeof(PBitset));
    bitset->size = 1;
    bitset->store = NULL ;
    setBitsetNumber(bitset, number) ;
    return bitset;
}

long GetLowBitset(PBitset *bitset) { //The low is 0
    long i = 0;
    for(long long i = 0; i < bitset->size; i++)
        if(bitset->store[i] == 1)
            i++;
    return i;
}
long GetHighBitset(PBitset *bitset) { // The high is 1
    long i = 0;
    for(long long i = 0; i < bitset->size; i++)
        if(bitset->store[i] == 1)
            i++;
    return i;
}


bool setBit(PBitset *bitset, unsigned long index, bool value){
    if(index >= bitset->size || index < 0)
        return false;
    bitset->store[index] = value;
    return true;
}

bool setBitsetNumber(PBitset *bitset, long number) {
    bitset->symbol = number >= 0 ? false : true;
    bitset->size = 0;
    free(bitset->store);
    bitset->store = malloc(sizeof(_Bool)) ;
    long cp = abs(number);
    while(cp){
        bitset->size++;
        bitset->store = realloc(bitset->store, bitset->size*sizeof(_Bool)) ;
        if(!setBit(bitset, bitset->size - 1, cp & 1))
            return false;
        cp = cp >> 1;
    }
    return true;
}
bool printBitsetln(PBitset *bitset, unsigned int status) {
    switch (status) {
        case __PRINT_BITSET_FORMAT_FTO:
            printBitsetln(bitset, __PRINT_BITSET_FORMAT_FTO | __PRINT_BITSET_SYMBOL_NONE);
            break;
        case __PRINT_BITSET_FORMAT_OTO:
            printBitsetln(bitset, __PRINT_BITSET_FORMAT_OTO | __PRINT_BITSET_SYMBOL_NONE);
            break;
        case __PRINT_BITSET_FORMAT_OTO | __PRINT_BITSET_SYMBOL_NONE:
            printf("symbol :%d\n", bitset->symbol) ;
            for(long long i = bitset->size - 1; i >= 0; i--)
                printf("%d", bitset->store[i]==0 ? 0 : 1);
            break;
        case __PRINT_BITSET_FORMAT_OTO | __PRINT_BITSET_SYMBOL_ONESELF:
            printf("symbol :%d\n", bitset->symbol) ;
            for(long long i = bitset->size - 1; i >= 0; i--)
                printf("%d", bitset->store[i]);
            break;
        case __PRINT_BITSET_FORMAT_FTO | __PRINT_BITSET_SYMBOL_NONE:
            if(bitset->size % 4 == 0){
                for(long long i = bitset->size - 1; i >= 0; i--){
                    if(i % 4 == 0)
                        printf(" ");
                    printf("%d", bitset->store[i]==0 ? 0 : 1);
                }
            }else{
                int df = 4 - bitset->size % 4;
                for(int index = 0; index < df; index++)
                    printf(" ");
                for(long long i = bitset->size - 1; i >= 0; i--){
                    printf("%d", bitset->store[i]==0 ? 0 : 1);
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
                    printf("%d", bitset->store[i]==0 ? 0 : 1);
                }
            }else{
                int df = 4 - bitset->size % 4;
                for(int index = 0; index < df; index++)
                    printf(" ");
                for(long long i = bitset->size - 1; i >= 0; i--){
                    printf("%d", bitset->store[i]==0 ? 0 : 1);
                    if((i + df - 1) % 4 == 0)
                        printf(" ");
                }
            } 
            printf("\n");
            break;
        default:
            printf("error status\n");
            return false;
            break;
    }
    return true;
}

bool FreeBitset(PBitset *bitset) {
    free(bitset);
    return true;
}

long long getBitsetNumber(PBitset *bitset){
    long long data = 0;
    if(bitset->symbol){
        for(long long i = 0; i < bitset->size; i++){
            data *= 2;
            data += (bitset->store[i]==0 ? 0 : 1);
        }
    }
    return data;
}

bool clearBitset(PBitset *bitset) {
    bitset->size = 0;
    free(bitset->store);
    bitset->store = malloc(sizeof(_Bool)) ;
    return true;
}