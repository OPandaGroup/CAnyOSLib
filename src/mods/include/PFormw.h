#ifndef __PFORM___
#define __PFORM___

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./PMemory.h"
#include "./PDataTypeDefine.h"   


typedef struct PLine{
    string *lines;
    size_t length;
}PLines;
PLines *PLines_new(size_t length);
bool SetLines(PLines *lines, size_t length) ;
bool SetLines_Value(PLines *lines, size_t index, string Value);
bool PLines_add(PLines *lines, string line);
void PLines_free(PLines *lines);

typedef struct PForm {
    size_t width, height;
    string title; // Form title
    PLines *titles; //这一行是专门用与存储表头信息的
    struct PLine **lines; //这一行是表头下面实际的数据
}PForm;
PForm *PForm_new(string title, size_t width);
void SetPFormTitle(PForm *form, string title);
bool SetPFormTitles(PForm *form, size_t index, string title);
void SetPFormLines(PForm *form, size_t lines, size_t index, string line);
bool PForm_add(PForm *form, size_t lines, string line);
#endif