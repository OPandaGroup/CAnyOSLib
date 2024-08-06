#include "../include/Widgets/PMemory.h"

void *PMalloc(size_t size){
    void *ptr = malloc(size);
    if(ptr == NULL)
        printf("Error: Memory allocation failed\n") ;
    return ptr;
}

Bool PDilatation(void* ptr, size_t size){
    ptr = realloc(ptr, sizeof(ptr) + size);
    if(ptr == NULL)
        return false;
    else
        return true;
}

Bool Pfree(void* ptr){
    free(ptr);
    return true;
}

Bool PShrink(void* ptr, size_t size){
    ptr = realloc(ptr, sizeof(ptr) - size) ;
    if(ptr == NULL)
        return false;
    else
        return true;
}

void *new(size_t size){
    void *mem = PMalloc(size);
    return mem;
}

void delet(size_t size){
    Pfree(size);
}