#include "./include/PColor.h"

void Termianl_Color(PColor color){
    switch(color){
        case NONE_COLOR:
            SetColor(NONE) ;
            break;
        case BLACK_COLOR:
            SetColor(BLACK) ;
            break;
        case GRAY_COLOR:
            SetColor(GRAY) ;
            break;
        case RED_COLOR:
            SetColor(RED) ;
            break;
        case GREEN_COLOR:
            SetColor(GREEN) ;
            break;
        case YELLOW_COLOR:
            SetColor(YELLOW) ;
            break;
        case BLUE_COLOR:
            SetColor(BLUE) ;
            break;
        case PURPLE_COLOR:
            SetColor(PURPLE) ;
            break;
        case CYAN_COLOR:
            SetColor(CYAN) ;
            break;
        case WHITE_COLOR:
            SetColor(WHITE) ;
            break;
        case BOLD_COLOR:
            SetColor(BOLD) ;
            break;
        case UNDERLINE_COLOR:
            SetColor(UNDERLINE) ;
            break;
        case REVERSE_COLOR:
            SetColor(REVERSE) ;
            break;
        case BLINK_COLOR:
            SetColor(BLINK) ;
            break;
        case CLEAR_COLOR:
            SetColor(CLEAR) ;
            break;
        default:
            SetColor(NONE) ;
            break;
    }
    return ;
}

void Termianl_Reset(PColor color){
    Termianl_Color(NONE_COLOR) ;
}