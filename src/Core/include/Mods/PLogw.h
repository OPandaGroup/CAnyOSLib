#ifndef PLOGWidgets_H
#define PLOGWidgets_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "./PDataTypeDefine.h"
#include "../PColor.h"
#include "./PTimew.h"

//format 
#define __LOG__TIME_USER 0x00001 //format : [XX:XX:XX] : [USER] : [LOG] : [MESSAGE] 
#define __LOG_USER 0x00002 //format : [XX:XX:XX] : [SYSTEM] : [LOG] : [MESSAGE]
#define __LOG__MESSAGE 0x00004 //format : [LOG] :[MESSAGE]
//print class
#define __LOG_PRINT_CLASS_DEBUG 0x00001
#define __LOG_PRINT_CLASS_INFO 0x00002
#define __LOG_PRINT_CLASS_WARNING 0x00004
#define __LOG_PRINT_CLASS_ERROR 0x00008
#define __LOG_PRINT_CLASS_FATAL 0x00010
#define __LOG_PRINT_CLASS_CLOSE 0xfffff
//print redirect 
#define __LOG_PRINT_REDIRECT_FILE 0x00001
#define __LOG_PRINT_REDIRECT_CONSOLE 0x00002
#define __LOG_PRINT_REDIRECT_BOTH 0x00004
#define __LOG_PRINT_REDIRECT_NONE 0x00008 //关闭所有输出
#define __LOG_PRINT_REDIRECT_NULL 0x00000 //没有指定数据
//Color Config
#define __LOG_COLOR_CONF_1 0x00001
typedef struct PLogwidgets{
    int max_print_class;
    int format;
    char *user ;
    //输出重定向
    int info_redirect, debug_redirect, warning_redirect, error_redirect, fatal_redirect;
    PColor info_color, debug_color, warning_color, error_color, fatal_color;
    FILE *log_file; 
}PLog;

PLog *Log(int, string) ;
void SetLogMaxClass(PLog*, int) ;
void SetLogFormat(PLog *, int) ;
void RedirectLogFile(PLog*, string, string) ;
void RedirectLogFile_F(PLog*, FILE *);
void RedirectLog(PLog *, int, int) ;
void print_Info(PLog *log, char *message);
void print_Debug(PLog *log, char *message);
void print_Warning(PLog *log, char *message);
void print_Error(PLog *log, char *message);
void print_Fatal(PLog *log, char *message);
void print_Close(PLog *log);
void SetLogColor(PLog *log, int, PColor) ;
void UseLogColorConfig(PLog *log, int) ;
#endif 