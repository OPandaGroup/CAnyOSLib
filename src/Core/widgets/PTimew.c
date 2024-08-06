#include "../include/Widgets/PTimew.h"

time_t getTimeStamp(){
    time_t timestamp = time(NULL);
    return timestamp;
}
string getTime_c(time_t timestamp){
    struct tm *t = localtime(&timestamp);
    char *buf = (char*)malloc(sizeof(char) * 100);
    sprintf(buf, "%2d:%2d:%2d", t->tm_hour, t->tm_min, t->tm_sec);
    return buf;
}

string getDate_c(time_t timestamp){
    struct tm *t = localtime(&timestamp);
    char *buf = (char*)malloc(sizeof(char) * 100);
    sprintf(buf, "%d-%d-%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
    return buf;
}

time_t get_Gap(CLOCK aclock){
    if(aclock.Pattern)
        return clock() - aclock.start;
    else
        return aclock.end - aclock.start;
}


CLOCK new_CLOCK(){
    printf("CLOCK is created\n") ;
    CLOCK clock = { .start = 0, .end = 0, .Pattern = false } ;
    return clock;
}

void Start_CLOCK(CLOCK aclock){
    aclock.start = clock();
    aclock.Pattern = true;
    aclock.end = 0;
}

void Pause_CLOCK(CLOCK aclock){
    aclock.end = clock();
    aclock.Pattern = false;
}

void THROW_CLOCK(CLOCK clock){
    clock.start = 0 ;
    clock.end = 0 ;
    clock.Pattern = false ;
}