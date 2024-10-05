#include "page.h"

#include "term_ui_conf_internal.h"

#include "title_line.h"
#include "category_line.h"
#include "selectable_line.h"
#include "in_page_menu.h"

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

    _menu->draw();
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

void Page::addTitle(std::string txt){
    _lines.push_back(std::make_unique<TitleLine>(_win, (_lines.size() + 1), txt));
}

void Page::addCategoryLine(std::string txt){
    _lines.push_back(std::make_unique<CategoryLine>(_win, (_lines.size() + 1), txt));
}

void Page::addSelectableLine(std::string txt){
    _lines.push_back(std::make_unique<SelectableLine>(_win, (_lines.size() + 1), txt));
}

void Page::addMenu(std::vector<std::string> btn) {
    _menu = std::make_unique<InPageMenu>(_win, btn);
}

void Page::goToFirstFocusableLine() {
    int oldCurrentLine = _currentLine;
    _currentLine = 0;

    while ( _lines[_currentLine]->hasInteraction(AbstractLine::LineInteraction::UNFOCUSABLE) ) {
        _currentLine ++;
    }

    if ( _lines[_currentLine]->hasInteraction(AbstractLine::LineInteraction::FOCUSABLE) ) {
        _lines[oldCurrentLine]->highlight(false);
        _lines[_currentLine]->highlight(true);
    } else {
        _currentLine = oldCurrentLine;
    }
}

void Page::goToUpperLine() {
    if ( _currentLine > 0 && !_menuIsFocused ) {
        int oldCurrentLine = _currentLine;

        do {
            _currentLine --;
        } while( _lines[_currentLine]->hasInteraction(AbstractLine::LineInteraction::UNFOCUSABLE) && _currentLine > 0 );

        if ( _lines[_currentLine]->hasInteraction(AbstractLine::LineInteraction::UNFOCUSABLE) ) {
            _currentLine = oldCurrentLine;
        } else {
            _lines[oldCurrentLine]->highlight(false);
            _lines[_currentLine]->highlight(true);
        }
    }
}

void Page::goToLowerLine() {
    if ( _currentLine < (_lines.size() - 1) && !_menuIsFocused ) {
        int oldCurrentLine = _currentLine;

        do {
            _currentLine ++;
        } while( _lines[_currentLine]->hasInteraction(AbstractLine::LineInteraction::UNFOCUSABLE) && _currentLine < (_lines.size() - 1) );

        if ( _lines[_currentLine]->hasInteraction(AbstractLine::LineInteraction::UNFOCUSABLE) ) {
                _currentLine = oldCurrentLine;
        } else {
            _lines[oldCurrentLine]->highlight(false);
            _lines[_currentLine]->highlight(true);
        }
    }
}

void Page::goToLeft() {
    if ( _menuIsFocused ) {
        _menu->goToPrevious();
    }
}

void Page::goToRight() {
    if ( _menuIsFocused ) {
        _menu->goToNext();
    }
}

void Page::switchBtwLineMenu() {
    _menuIsFocused = !_menuIsFocused;

    if (_menuIsFocused) {
        _lines[_currentLine]->highlight(false);
        _menu->highlight(true);
    } else {
        _lines[_currentLine]->highlight(true);
        _menu->highlight(false);
    }
}

void Page::interactWithLine() {
    if ( _lines[_currentLine]->hasInteraction(AbstractLine::LineInteraction::SELECTABLE) )
        _lines[_currentLine]->toggle();
}