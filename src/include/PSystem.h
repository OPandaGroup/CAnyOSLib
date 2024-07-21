//
// @date:2024/07/16
// @file:PSystem.h
// @author:Writing 
// @copyright: Panda, 2024
//

#include <stdio.h>
#include <stdlib.h>
#include "./PString.h"
#include "./PFile.h"

// 完成系统重定向,函数实现在so文件中,所以,链接在build中实现
#ifdef Win_NT
    #include "./PWindows.h"
#endif
#ifdef Linux 
    #include "./PLinux.h"
#endif
//有_表示可以自动重定向到当前系统所对应的函数, 无_表示需要手动重定向
void _ShellToUTF8();
void _gotoXY(int x, int y);
char *_getSystem() ;
char *_runShell(char *cmd) ;
char *_getFilePath(char *path) ;//获取文件所在文件夹 比如 /home/user/file.txt 返回/home/user/
