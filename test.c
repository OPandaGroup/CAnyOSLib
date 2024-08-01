#include "./src/Core/include/PBitsetw.h"

int main() {
    PBitset32 *bitset = Bitset(0);
    setBit(bitset, 100000);
    printBitsetln(bitset, __PRINT_BIT_FTO);
}