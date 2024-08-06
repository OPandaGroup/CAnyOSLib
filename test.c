#include "./src/Core/include/Widgets/Plogw.h"
#include "./src/Core/include/Widgets/PBitsetw.h"

int main(void){
    FILE *file = fopen("Log.txt", "wb") ;
    // fprintf(file, "Hello World !\n") ;
    fwrite("Hello World !\n", 1, 13, file) ;
    fclose(file) ;
}
