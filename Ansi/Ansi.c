#include "Ansi.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void set_terminal_cursor(int row, int column){
    printf("\33[%d;%dH", row, column);
}
void clear_terminal(){
    printf(ANSI_ERASE_WHOLE_SCREEN);
    set_terminal_cursor(0, 0);
}


void terminal_set_text_color(int color){
    printf(ANSI_ESCAPE "%d" "m", color);
}
void terminal_set_background_color(int color){
    printf(ANSI_ESCAPE "%d" "m", color+10);
}
void terminal_set_rgb_text(int r, int g, int b){
    printf("\033[38;2;%d;%d;%dm", r, g, b);
}

void terminal_set_rgb_background(int r, int g, int b){
    printf("\033[48;2;%d;%d;%dm", r, g, b);
}

void terminal_reset_color(){
    printf("\33[0m");
}

void terminal_set_size(int h, int w){
    printf("\033[8;%d;%dt", h, w);
}

void terminal_set_font(int size){
    printf("\033[%dm", size);
}

char* terminal_return_bcg_string(int r, int g, int b){
    char* str=calloc(strlen("\033[48;2;255;255;255m")+2, sizeof(char));
    sprintf(str, "\033[48;2;%d;%d;%dm", r, g, b);
    return str;
}
