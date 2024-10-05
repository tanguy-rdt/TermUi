#include "page.h"

#include "term_ui_conf_internal.h"

#include "selectable_line.h"
#include "title_line.h"

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

    init();
}

Page::Page(int height, int width) :
    _height(height), _width(width) {
    
    init();
}

Page::~Page(){
    delwin(_win);
    endwin();
}

void Page::init(){
    int startx = (COLS - _width) / 2; 
    int starty = (LINES - _height) / 2; 
    _win = newwin(_height, _width, starty, startx);
}

void Page::draw(){
    box(_win, 0, 0); 

    #ifdef USE_COLOR
        wbkgd(_win, COLOR_PAIR(TUI_WIN_BACKGROUND_COLOR_IDX)); 
    #endif 

    for (const auto& line: _lines) {
        line->draw();
    }
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

void Page::addSelectableLine(std::string txt){
    _lines.push_back(std::make_unique<SelectableLine>(_win, (_lines.size() + 1), txt));
}

void Page::addTitle(std::string txt){
    _lines.push_back(std::make_unique<TitleLine>(_win, (_lines.size() + 1), txt));
}