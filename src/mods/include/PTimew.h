#ifndef __PTIEW_H__
#define __PTIEW_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./PDataTypeConversionw.h"
#include "./PStringw.h"
#include "./PDataTypeDefine.h"

time_t getTimeStamp();
string getTime_c(time_t timestamp) ;
string getDate_c(time_t timestamp) ;
typedef struct CLOCK{
    time_t start ;
    time_t end ;
    bool Pattern ;
}CLOCK ;
time_t get_Gap(CLOCK clock) ;
CLOCK new_CLOCK() ;
void Start_CLOCK(CLOCK clock) ;
void Pause_CLOCK(CLOCK clock) ;
void THROW_CLOCK(CLOCK clock) ;

#endif