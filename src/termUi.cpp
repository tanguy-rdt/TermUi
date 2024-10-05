#include "termUi.h"
#include "term_ui_conf_internal.h"

TermUi::TermUi(){

}

TermUi::~TermUi(){

}

void TermUi::init(){
    initscr();          

    cbreak();   
    noecho();
    keypad(stdscr, TRUE); 

    initWin();
    initColor();

    wrefresh(_win); 
    getch();
    delwin(_win);
    endwin();
}

void TermUi::initColor(){
    #ifdef USE_COLOR
        start_color();
        init_pair(TUI_BACKGROUND_COLOR_IDX,     TUI_BACKGROUND_COLOR); 
        init_pair(TUI_WIN_BACKGROUND_COLOR_IDX, TUI_WIN_BACKGROUND_COLOR); 
        init_pair(TUI_HIGHLIGHT_COLOR_IDX,      TUI_HIGHLIGHT_COLOR);

        bkgd(COLOR_PAIR(TUI_BACKGROUND_COLOR_IDX)); 
        refresh();
        wbkgd(_win, COLOR_PAIR(TUI_WIN_BACKGROUND_COLOR_IDX)); 
    #endif 
}

void TermUi::initWin(){
    clear();
    refresh();

    int win_height = 0;
    int win_width = 0;

    #if defined(RATIO_WIN_SIZED)
        win_height = LINES * TUI_WIN_HEIGHT;
        win_width  = COLS  * TUI_WIN_WIDTH;
    #elif defined(EXACT_WIN_SIZED)
        win_height = TUI_WIN_HEIGHT;
        win_width  = TUI_WIN_WIDTH;
    #else 
        win_height = LINES * 0.66;
        win_width  = COLS  * 0.50;
    #endif

    int startx = (COLS - win_width) / 2; 
    int starty = (LINES - win_height) / 2; 
    _win = newwin(win_height, win_width, starty, startx);

    box(_win, 0, 0); 
}