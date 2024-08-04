#include "./src/Core/include/Widgets/PBitsetw.h"

int main() {
    PBitset32 *bitset = Bitset(-2147483647);
    system("chcp 65001") ;
    upDateBitset(bitset) ;
    printf("is _ debug") ;
    if(printBitsetln(bitset, __PRINT_BITSET_FORMAT_FTO | __PRINT_BITSET_SYMBOL_ONESELF))
        printf("is _ debug") ;
}