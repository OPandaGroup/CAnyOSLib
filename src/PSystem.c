//
// @date:2024/07/16
// @file:PSystem.c
// @author:Writing 
// @copyright: Panda, 2024
//
#include "./include/PSystem.h"

#ifndef Sys
#define Sys "Windows"
#endif

void _ShellToUTF8() {
    ShellToUTF8();
}

void _gotoXY(int x, int y) {
    gotoXY(x, y);
}

char *_getSystem() {
    #ifdef Win_NT
        return "Windows";
    #endif
    #ifdef Linux
        return "Linux";
    #endif
}

char *_runShell(char *cmd){
    system(splice_String(cmd, " > ./run/tmp.txt"));
    return readfile(fopen("./run/tmp.txt", "r"), fileSize(fopen("./run/tmp.txt", "r")));
}

char *_getFilePath(char *path){
    Replace(path, '\\', '/') ;
    for(int i = strlen(path) - 1; i >= 0; i--){
        if(path[i] == '/'){
            return stringcut(path, 0, i);
        }
    }
    return path;
}