#include "./src/Core/include/Mods/Plogw.h"
#include "./src/Core/include/Mods/PBitsetw.h"
#include "./src/Core/include/Mods/PFormw.h"

int main(void){
    printf("strat") ;
    PForm *p = PForm_new("Test", 2);
    printf("HELLO") ;
    SetPFormTitles(p, 0, "Test") ;
    printf("HELLO ", p->titles[0]);
}
