#include "./include/PLogw.h"

//format : [XX:XX:XX] : [USER] : [LOG] : [MESSAGE] 
//format : [XX:XX:XX] : [SYSTEM] : [LOG] : [MESSAGE]
//format : [LOG] :[MESSAGE]
void PLogPrint(string user, string message, string Log_Mode, int format, FILE* file){
    switch(format){
        case __LOG__MESSAGE:
            fprintf(file, "[%s] : %s", Log_Mode, message) ;
            break ;
        case __LOG__TIME_USER:
            fprintf(file, "[%s] : [%s] : [%s] : %s", getTime_c(getTimeStamp()), user, Log_Mode, message) ;
            break ;
        case __LOG_USER:
            fprintf(file, "[%s] : [%s] : %s", user, Log_Mode, message) ;
            break;
        default:
            PLogPrint(user, message, Log_Mode, __LOG__TIME_USER, file);
            break;
    }
}

void print_Debug(PLog *log, char *message){
    if(log->max_print_class < __LOG_PRINT_CLASS_DEBUG){
        return ;
    }
    Termianl_Color(log->debug_color) ;
    FILE *stream = NULL;
    switch (log->debug_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            PLogPrint(log->user, message, "DEBUG", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            PLogPrint(log->user, message, "DEBUG", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            PLogPrint(log->user, message, "DEBUG", log->format, stream) ;
            stream = log->log_file ;
            PLogPrint(log->user, message, "DEBUG", log->format, stream) ;
            break;
        default:
            break;
    }
    Termianl_Reset(log->debug_color) ;
    return ;
}

void print_Info(PLog *log, char *message){
    if(log->max_print_class < __LOG_PRINT_CLASS_INFO){
        return  ;
    }
    Termianl_Color(log->info_color) ;
    FILE *stream = NULL;
    switch (log->info_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            PLogPrint(log->user, message, "INFO", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            PLogPrint(log->user, message, "INFO", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            PLogPrint(log->user, message, "INFO", log->format, stream) ;
            stream = log->log_file ;
            PLogPrint(log->user, message, "INFO", log->format, stream) ;
            break;
        default:
            break;
    }
    Termianl_Reset(log->info_color) ;
}

void print_Warning(PLog *log, char *message){
    FILE *stream = NULL ;
    if(log->max_print_class < __LOG_PRINT_CLASS_WARNING){
        return  ;
    }
    Termianl_Color(log->warning_color) ;
    switch (log->warning_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            PLogPrint(log->user, message, "WARNING", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            PLogPrint(log->user, message, "WARNING", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            PLogPrint(log->user, message, "WARNING", log->format, stream) ;
            stream = log->log_file ;
            PLogPrint(log->user, message, "WARNING", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_NONE :
            return  ;
            break ;
        case __LOG_PRINT_REDIRECT_NULL :
            return  ;
            break;
        default:
            break;
    }
    Termianl_Reset(log->warning_color) ;
}

void print_Error(PLog *log, char *message){
    FILE *stream = NULL ;
    if(log->max_print_class < __LOG_PRINT_CLASS_ERROR){
        return  ;
    }
    Termianl_Color(log->error_color) ;
    switch (log->error_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            PLogPrint(log->user, message, "ERROR", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            PLogPrint(log->user, message, "ERROR", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            PLogPrint(log->user, message, "ERROR", log->format, stream) ;
            stream = log->log_file ;
            PLogPrint(log->user, message, "ERROR", log->format, stream) ;
            break;
        default:
            break;
    }
    Termianl_Reset(log->error_color) ;
    return  ;
}

void print_Fatal(PLog *log, char *message){
    FILE *stream = NULL ;
    if(log->max_print_class < __LOG_PRINT_CLASS_FATAL){
        return  ;
    }
    Termianl_Color(log->fatal_color) ;
    switch (log->fatal_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            PLogPrint(log->user, message, "FATAL", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            PLogPrint(log->user, message, "FATAL", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            PLogPrint(log->user, message, "FATAL", log->format, stream) ;
            stream = log->log_file ;
            PLogPrint(log->user, message, "FATAL", log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_NONE :
            return  ;
            break ;
        case __LOG_PRINT_REDIRECT_NULL :
            return  ;
            break;
        default:
            break;
    }
    Termianl_Reset(log->fatal_color) ;
    exit(-1) ;
}

void print_Close(PLog *log){
    free(log) ;
}

PLog *Log(int maxClass, string user){
    PLog *log = malloc(sizeof(struct PLogwidgets)) ;
    log->max_print_class = maxClass ;
    log->user = user;
    log->log_file = NULL ;
    log->info_redirect = __LOG_PRINT_REDIRECT_CONSOLE;
    log->debug_redirect = __LOG_PRINT_REDIRECT_CONSOLE;
    log->warning_redirect = __LOG_PRINT_REDIRECT_CONSOLE; 
    log->error_redirect = __LOG_PRINT_REDIRECT_CONSOLE ;
    log->fatal_redirect = __LOG_PRINT_REDIRECT_CONSOLE;
    return log ;
}

void SetLogMaxClass(PLog *log, int Class){
    log->max_print_class = Class ;
    return ;
}

void SetLogFormat(PLog *log, int format){
    log->format = format ;
    return ;
}

void RedirectLogFile(PLog *log, string file, string mode){
    FILE *fp = fopen(file, mode) ;
    log->log_file = fp;
    return ;
}

void RedirectLogFile_F(PLog *log, FILE *file){
    log->log_file = file ;
    return ;
}

void RedirectLog(PLog *log, int class, int red){
    switch(class){
        case __LOG_PRINT_CLASS_INFO:
            log->info_redirect = red; 
            break ;
        case __LOG_PRINT_CLASS_DEBUG:
            log->debug_redirect = red; 
            break ;
        case __LOG_PRINT_CLASS_WARNING:
            log->warning_redirect = red; 
            break ;
        case __LOG_PRINT_CLASS_ERROR:
            log->error_redirect = red; 
            break ;
        case __LOG_PRINT_CLASS_FATAL:
            log->fatal_redirect = red; 
            break ;
    }
    return ;
}

void SetLogColor(PLog *log, int logClass, PColor color){
    switch(logClass){
        case __LOG_PRINT_CLASS_INFO:
            log->info_color = color ;
            break ;
        case __LOG_PRINT_CLASS_DEBUG:
            log->debug_color = color ;
            break ;
        case __LOG_PRINT_CLASS_WARNING:
            log->warning_color = color ;
            break ;
        case __LOG_PRINT_CLASS_ERROR:
            log->error_color = color ;
            break ;
        case __LOG_PRINT_CLASS_FATAL:
            log->fatal_color = color ;
            break ;
        default :
            log->fatal_color = RED_COLOR;
            Termianl_Color(RED_COLOR) ;
            printf("[TATAL ERROR] : Unknown Log Class, please check your code\n") ;
            break;
    }
}   

void UseLogColorConfig(PLog *log, int config){
    switch (config){
        case __LOG_COLOR_CONF_1:
            SetLogColor(log, __LOG_PRINT_CLASS_INFO, GREEN_COLOR) ;
            SetLogColor(log, __LOG_PRINT_CLASS_DEBUG, BLUE_COLOR) ;
            SetLogColor(log, __LOG_PRINT_CLASS_WARNING, YELLOW_COLOR) ;
            SetLogColor(log, __LOG_PRINT_CLASS_ERROR, RED_COLOR) ;
            SetLogColor(log, __LOG_PRINT_CLASS_FATAL, BOLD_COLOR) ;
            break;
        
        default:
        log->fatal_color = RED_COLOR;
            Termianl_Color(RED_COLOR) ;
            printf("[TATAL ERROR] : Unknown Log Class, please check your code\n") ;
            break;
    }
}