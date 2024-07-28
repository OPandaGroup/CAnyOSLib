//
// @date:2024/07/16
// @file:PWindows.h
// @author:Writing 
// @copyright: Panda, 2024
//
#ifndef __Windows_Panda__ //windows攀达扩展库
#define __Windows_Panda__

#include <stdio.h>
#include <stdlib.h>
#include "./Pprint.h" //方便调用PrintError
#include <Windows.h>

void ShellToUTF8();
void gotoXY(int x, int y);
HANDLE createNamePipe(char *name, DWORD mode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut);
_Bool writeNamePipe(HANDLE hPipe, char *buffer) ;
char *readNamePipe(HANDLE hPipe, DWORD length) ;
HANDLE connectNamePipe(char *name) ;

#endif