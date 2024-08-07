#ifndef CLASS_FOR_C
#define CLASS_FOR_C

#include <stdio.h>
#include <stdlib.h>
#include "./PDataStructure.h"
typedef size_t HANDLE;

HANDLE Fun(char *fun_name); 
HANDLE INT(char *Var, int value) ;
HANDLE FLOAT(char *Var, float value) ;
HANDLE CHAR(char *Var, char value) ;
HANDLE STRING(char *Var, char *value) ;
HANDLE VOID(char *Var) ;
typedef struct __CLASS__{
    char *name;
    void *Constructor ;
    void *Fiction ;
    void *HANDLE; 
    dirt *__VAR__;
}class;

class *Class(char *name, void *Constructor, void *Fiction, ...);

#endif