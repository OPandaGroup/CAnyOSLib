#include "../inc/PWindow.h"

void PCreateWindow(wchar_t *windowName){
    WNDCLASS wc = {} ;
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
}