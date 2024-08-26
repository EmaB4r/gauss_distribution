#ifndef ANSI_H
#define ANSI_H
#include <stdio.h>
#define ANSI_ESCAPE "\33["
#define ANSI_BELL "\07"
#define ANSI_ENDCODE "m"
#define ANSI_ERASE_VISIBLE_SCREEN ANSI_ESCAPE "2J"
#define ANSI_ERASE_CACHED_SCREEN ANSI_ESCAPE "3J"
#define ANSI_ERASE_WHOLE_SCREEN ANSI_ERASE_VISIBLE_SCREEN ANSI_ERASE_CACHED_SCREEN
#define ANSI_BLACK_COLOR	30
#define ANSI_RED_COLOR	31
#define ANSI_GREEN_COLOR	32
#define ANSI_YELLOW_COLOR	33
#define ANSI_BLUE_COLOR	34
#define ANSI_MAGENTA_COLOR	35
#define ANSI_CYAN_COLOR	36
#define ANSI_WHYTE_COLOR	37
#define ANSI_DEFAULT_COLOR	39
#define ANSI_RESET_COLOR	"\33[0m"

void set_terminal_cursor(int row, int column);
void clear_terminal();
void terminal_set_size(int h, int w);
void terminal_set_text_color(int color);
void terminal_set_background_color(int color);
void terminal_set_rgb_text(int r, int g, int b);
void terminal_set_rgb_background(int r, int g, int b);
void terminal_reset_color();
void terminal_set_font(int size);
//dynamic string
char* terminal_return_bcg_string(int r, int g, int b);
#endif