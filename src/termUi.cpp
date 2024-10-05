#include "termUi.h"
#include "term_ui_conf_internal.h"

TermUi::TermUi() {

}

TermUi::~TermUi() {

}

void TermUi::init() {
    initscr();          

    cbreak();   
    noecho();
    keypad(stdscr, TRUE); 

    initColor();
}

void TermUi::initColor() {
    #ifdef USE_COLOR
        start_color();
        init_pair(TUI_BACKGROUND_COLOR_IDX,     TUI_BACKGROUND_COLOR); 
        init_pair(TUI_WIN_BACKGROUND_COLOR_IDX, TUI_WIN_BACKGROUND_COLOR); 
        init_pair(TUI_HIGHLIGHT_COLOR_IDX,      TUI_HIGHLIGHT_COLOR);

        bkgd(COLOR_PAIR(TUI_BACKGROUND_COLOR_IDX)); 
        refresh();
    #endif 
}


Page* TermUi::addPage() {
    _pages.push_back(std::make_unique<Page>());
    return _pages.back().get();
}

Page* TermUi::addPage(int height, int width) {
    _pages.push_back(std::make_unique<Page>(height, width));
    return _pages.back().get();
}

void TermUi::showPage(int idx) {
    _pages[_currentPage]->hide();
    _currentPage = idx;
    _pages[_currentPage]->show();
    _pages[_currentPage]->goToFirstFocusableLine();
}

void TermUi::showMainPage() {
    showPage(0);
}

void TermUi::run() {
    int ch;
    while ((ch = getch()) != 'q') { 
        switch (ch) {
            case KEY_UP:
                _pages[_currentPage]->goToUpperLine();
                break;
            case KEY_DOWN:
                _pages[_currentPage]->goToLowerLine();
                break;
            case KEY_LEFT:
                _pages[_currentPage]->goToLeft();
                break;
            case KEY_RIGHT:
                _pages[_currentPage]->goToRight();
                break;
            case 9:
                _pages[_currentPage]->switchBtwLineMenu();
                break;
            case 10:
                _pages[_currentPage]->interactWithLine();
                break;
        }
    }
}