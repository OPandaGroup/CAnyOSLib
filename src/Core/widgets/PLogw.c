#include "../include/Widgets/PLogw.h"

//format : [XX:XX:XX] : [USER] : [LOG] : [MESSAGE] 
//format : [XX:XX:XX] : [SYSTEM] : [LOG] : [MESSAGE]
//format : [LOG] :[MESSAGE]
void PPrint(string user, string message, int format, FILE* file){
    switch(format){
        case __LOG__MESSAGE:
            fprintf(file, "[DEBUG] : %s", message) ;
            break ;
        case __LOG__TIME_USER:
            fprintf(file, "[%s] : [%s] : [DEBUG] : %s", getTime_c(getTimeStamp()), user, message) ;
            break ;
        case __LOG_USER:
            fprintf(file, "[%s] : [DEBUG] : %s", user, message) ;
            break;
        default:
            fprintf(file, "DEBUG ERROR") ;
            break;
    }
}

void print_Debug(PLog *log, char *message){
    if(log->max_print_class < __LOG_PRINT_CLASS_DEBUG){
        return ;
    }
    FILE *stream = NULL;
    switch (log->debug_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            PPrint(log->user, message, log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            PPrint(log->user, message, log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            PPrint(log->user, message, log->format, stream) ;
            stream = log->log_file ;
            PPrint(log->user, message, log->format, stream) ;
            break;
        case __LOG_PRINT_REDIRECT_NONE :
            return;
            break ;
        case __LOG_PRINT_REDIRECT_NULL :
            return ;
            break;
        default:
            break;
    }
    return ;
}

void print_Info(PLog *log, char *message){
    FILE *stream = NULL ;
    if(log->max_print_class < __LOG_PRINT_CLASS_INFO){
        return  ;
    }
    switch (log->info_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            goto PRINT ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            goto PRINT ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            goto PRINT ;
            stream = log->log_file ;
            goto PRINT ;
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
PRINT:
    switch(log->format){
        case __LOG__MESSAGE:
            fprintf(stream, "[INFO] : %s", message) ;
            break ;
        case __LOG__TIME_USER:
            fprintf(stream, "[%s] : [%s] : [INFO] : %s", getTime_c(getTimeStamp()), log->user, message) ;
            break ;
        case __LOG_USER:
            fprintf(stream, "[%s] : [INFO] : %s", log->user, message) ;
            break;
        default:
            fprintf(stream, "INFO ERROR") ;
            break;
    }
    return  ;
}

void print_Warning(PLog *log, char *message){
    FILE *stream = NULL ;
    if(log->max_print_class < __LOG_PRINT_CLASS_WARNING){
        return  ;
    }
    switch (log->warning_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            goto PRINT ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            goto PRINT ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            goto PRINT ;
            stream = log->log_file ;
            goto PRINT ;
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
PRINT:
    switch(log->format){
        case __LOG__MESSAGE:
            fprintf(stream, "[WARNING] : %s", message) ;
            break ;
        case __LOG__TIME_USER:
            fprintf(stream, "[%s] : [%s] : [WARNING] : %s", getTime_c(getTimeStamp()), log->user, message) ;
            break ;
        case __LOG_USER:
            fprintf(stream, "[%s] : [WARNING] : %s", log->user, message) ;
            break;
        default:
            fprintf(stream, "WARNING ERROR") ;
            break;
    }
    return ;
}

void print_Error(PLog *log, char *message){
    FILE *stream = NULL ;
    if(log->max_print_class < __LOG_PRINT_CLASS_ERROR){
        return  ;
    }
    switch (log->error_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            goto PRINT ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            goto PRINT ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            goto PRINT ;
            stream = log->log_file ;
            goto PRINT ;
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
PRINT:
    switch(log->format){
        case __LOG__MESSAGE:
            fprintf(stream, "[ERROR] : %s", message) ;
            break ;
        case __LOG__TIME_USER:
            fprintf(stream, "[%s] : [%s] : [ERROR] : %s", getTime_c(getTimeStamp()), log->user, message) ;
            break ;
        case __LOG_USER:
            fprintf(stream, "[%s] : [ERROR] : %s", log->user, message) ;
            break;
        default:
            fprintf(stream, "ERROR PRINT ERROR") ;
            break;
    }
    return  ;
}

void print_Fatal(PLog *log, char *message){
    FILE *stream = NULL ;
    if(log->max_print_class < __LOG_PRINT_CLASS_FATAL){
        return  ;
    }
    switch (log->fatal_redirect){
        case __LOG_PRINT_REDIRECT_FILE:
            stream = log->log_file ;
            goto PRINT ;
            break;
        case __LOG_PRINT_REDIRECT_CONSOLE:
            stream = stdout ;
            goto PRINT ;
            break;
        case __LOG_PRINT_REDIRECT_BOTH:
            stream = stdout ;
            goto PRINT ;
            stream = log->log_file ;
            goto PRINT ;
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
PRINT:
    switch(log->format){
        case __LOG__MESSAGE:
            fprintf(stream, "[FATAL] : %s", message) ;
            break ;
        case __LOG__TIME_USER:
            fprintf(stream, "[%s] : [%s] : [FATAL] : %s", getTime_c(getTimeStamp()), log->user, message) ;
            break ;
        case __LOG_USER:
            fprintf(stream, "[%s] : [FATAL] : %s", log->user, message) ;
            break;
        default:
            fprintf(stream, "FATAL ERROR") ;
            break;
    }
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