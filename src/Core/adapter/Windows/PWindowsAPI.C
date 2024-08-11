//
// @date:2024/07/16
// @file:PWindows.c
// @author:Writing 
// @copyright: Panda, 2024
//

#include  "../../../include/PWindows.h"

void ShellToUTF8(){
    SetConsoleOutputCP(65001) ;
}

void gotoXY(int x, int y) {
	COORD pos = {x,y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}

HANDLE createNamePipe(char *name, DWORD mode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut){
	LPCSTR pipeName = name;
	HANDLE hPipe = CreateNamedPipeA(
		pipeName,
		mode,
		dwPipeMode,
		nMaxInstances,
		nOutBufferSize,
    	nInBufferSize,
    	nDefaultTimeOut,
		NULL
	);
	if(hPipe == INVALID_HANDLE_VALUE){
		printError("System Call", "create named Pipe", "System Error, create named Pipe time Error, Please try again") ;
		return NULL ;
	}
	return hPipe ;
}

_Bool writeNamePipe(HANDLE hPipe, char *buffer){
	DWORD nBytesWritten = 0;
	if(!WriteFile(hPipe, buffer, strlen(buffer), &nBytesWritten, NULL))
		return FALSE;
	return TRUE;
}

char *readNamePipe(HANDLE hPipe, DWORD length){
    char *buffer = malloc(length + 1);
    if (buffer == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }
    memset(buffer, 0, length + 1);
    DWORD dw = 0;
    if (hPipe == INVALID_HANDLE_VALUE) {
        free(buffer);
        return NULL;
    }
    if (ReadFile(hPipe, buffer, length, &dw, NULL)) {
        buffer[dw] = '\0';
        // Return the buffer but remember to free it after use.
        return buffer;
    } else {
        printf("Read File Error");
        free(buffer);
        return NULL;
    }
}

HANDLE connectNamePipe(char *name){
	return CreateFile(name, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL) ;
}