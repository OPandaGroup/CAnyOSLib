// 
// @date : 2024/08
// @author : writing 
// @copyright : GPL
// @brief : 一个表格结构
//


// @bug : 这段文件中有bug
#include "./include/PLogw.h"
#include "./include/PFormw.h"

PLines *PLines_new(size_t length){
    PLog *log = Log(__LOG_PRINT_CLASS_INFO, "ROOT");
    PLines *lines = malloc(sizeof(PLines));
    lines->length = length;
    lines->lines = malloc(sizeof(string) * length);
    SetLogColor(log, __LOG_PRINT_CLASS_DEBUG, GREEN_COLOR);
    print_Debug(log, "PLines_new()");
    return lines;
}

bool SetLines(PLines *lines, size_t line){
    realloc(lines->lines, sizeof(string) * line) ;
    if(lines->lines == NULL)
        return false;
    lines->length = line;
    return true;
}

bool PLines_add(PLines *lines, string line){
    if(PDilatation(lines->lines, sizeof(string))){
        lines->lines[lines->length] = line;
        return true;
    }else{
        return false;
    }
}

bool SetLines_Value(PLines *lines, size_t index, string Value){
    if(lines->length > index || index < 0)
        return false;
    else 
        lines->lines[index] = Value;
    return true;
}

void PLines_free(PLines *lines){
    for(size_t i = 0; i < lines->length; i++){
        free(lines->lines[i]);
    }
    free(lines) ;
}

PForm *PForm_new(string title, size_t width){
    PForm *form = malloc(sizeof(PForm));
    form->title = title;
    form->width = width;
    form->lines[0] = PLines_new(width);
    return form;
}

void SetPFormTitle(PForm *form, string title){
    form->title = title; 
}

bool SetPFormTitles(PForm *form, size_t index, string title){
    if(index >= form->height || index < 0)
        return false;
    form->lines[index]->lines[0] = title;
    return false;
}

void SetPFormLines(PForm *form, size_t lines, size_t index, string line){
    if(index >= form->height || index < 0)
        return;
    SetLines(form->lines[index], lines);
}