#include "./src/Core/include/Widgets/Plogw.h"
#include "./src/Core/include/Widgets/PBitsetw.h"
#include "./src/Core/include/Widgets/PFormw.h"

int main(void){
    printf("strat") ;
    PForm *p = PForm_new("Test", 2, 0);
    printf("HELLO") ;
    SetPFormTitles(p, 0, "Test") ;
    printf("HELLO ", p->titles[0]);
}
