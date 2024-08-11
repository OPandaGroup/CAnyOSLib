#include "./include/PMemory.h"

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

void delet(void *ptr){
    Pfree(ptr);
}

void MemorySet(void *ptr, size_t size, char c){
    __INT8 *p = (__INT8 *)ptr;
    for(size_t i = 0; i < size; i++)
        p[i] = c;
    return;
}

void MemorySets(void *ptr, size_t start, size_t end, char *c){
    __INT8 *p = (__INT8 *)ptr;
    for(size_t i = start; i < end; i++)
        p[i] = c[i];
    return;
}