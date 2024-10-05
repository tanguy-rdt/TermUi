#include "page.h"
#include "term_ui_conf_internal.h"

Page::Page(){
    #if defined(RATIO_WIN_SIZED)
        _height = LINES * TUI_WIN_HEIGHT;
        _width  = COLS  * TUI_WIN_WIDTH;
    #elif defined(EXACT_WIN_SIZED)
        _height = TUI_WIN_HEIGHT;
        _width  = TUI_WIN_WIDTH;
    #else 
        _height = LINES * 0.66;
        _width  = COLS  * 0.50;
    #endif
}

Page::Page(int height, int width) :
    _height(height), _width(width) {
}

Page::~Page(){
    delwin(_win);
    endwin();
}

void Page::draw(){
    int startx = (COLS - _width) / 2; 
    int starty = (LINES - _height) / 2; 
    _win = newwin(_height, _width, starty, startx);
    box(_win, 0, 0); 

    #ifdef USE_COLOR
        wbkgd(_win, COLOR_PAIR(TUI_WIN_BACKGROUND_COLOR_IDX)); 
    #endif 
}

void Page::show() {
    draw();
    wrefresh(_win);
}

void Page::hide() {
    werase(_win);
    
    #ifdef USE_COLOR
        wbkgd(_win, COLOR_PAIR(0));
    #endif

    wrefresh(_win);
}