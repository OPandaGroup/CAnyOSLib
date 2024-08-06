#ifndef __PWIDGETS_H__
#define __PWIDGETS_H__

//内存管理
#include <stdio.h>
#include <stdlib.h>
#include "./PDataTypeDefine.h"

Bool Pfree(void* ptr);
void *PMalloc(size_t size);
Bool PDilatation(void* ptr, size_t size);
Bool PShrink(void* ptr, size_t size);
void *new(size_t size) ;
void delet(size_t size) ;

#endif