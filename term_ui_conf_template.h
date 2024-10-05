//
// COPY THIS FILE AS term_ui_conf.h
//

#ifndef TERM_UI_CONF_H
#define TERM_UI_CONF_H


//
// WINDOWS SIZE
//

#define RATIO_WIN_SIZED 1
#if RATIO_WIN_SIZED == 1
    #define CONF_TUI_WIN_HEIGHT 0.66
    #define CONF_TUI_WIN_WIDTH 0.5
#else 
    #define EXACT_WIN_SIZED
    #define CONF_TUI_WIN_HEIGHT 10
    #define CONF_TUI_WIN_WIDTH  30
#endif


//
// COLORS
//

#define USE_COLOR 1
#if USE_COLOR == 1
    #define BLACK COLOR_WHITE, COLOR_BLACK
    #define GREY COLOR_BLACK, COLOR_WHITE
    #define BLUE COLOR_WHITE, COLOR_BLUE
    #define RED COLOR_WHITE, COLOR_RED
    #define GREEN COLOR_WHITE, COLOR_GREEN

    #define CONF_TUI_BACKGROUND_COLOR BLACK
    #define CONF_TUI_WIN_BACKGROUND_COLOR GREY
    #define CONF_TUI_HIGHLIGHT_COLOR RED
#endif

#endif  /*TERM_UI_CONF_H*/

