#include "termUi.h"
#include "term_ui_conf_internal.h"

TermUi::TermUi() {
    _navCtrl = std::make_unique<NavCtrl>();

    initscr();          

    cbreak();   
    noecho();
    keypad(stdscr, TRUE); 

    initColor();
}

TermUi::~TermUi() {

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
    _pages.push_back(std::make_unique<Page>(_navCtrl.get()));
    return _pages.back().get();
}

Page* TermUi::addPage(int height, int width) {
    _pages.push_back(std::make_unique<Page>(_navCtrl.get(), height, width));
    return _pages.back().get();
}

void TermUi::showPage(Page* page) {
    _navCtrl->setCurrentPage(page);
}

void TermUi::showPage(int idx) {
    _navCtrl->setCurrentPage(idx);
}

void TermUi::run() {
    int ch;
    while ((ch = getch()) != 'q') { 
        switch (ch) {
            case KEY_UP:
                _navCtrl->getCurrentPage()->goToUpperLine();
                break;
            case KEY_DOWN:
                _navCtrl->getCurrentPage()->goToLowerLine();
                break;
            case KEY_LEFT:
                _navCtrl->getCurrentPage()->goToLeft();
                break;
            case KEY_RIGHT:
                _navCtrl->getCurrentPage()->goToRight();
                break;
            case 9: // tab
                _navCtrl->getCurrentPage()->switchBtwLineMenu();
                break;
            case 10: // enter
                _navCtrl->getCurrentPage()->interactWithLine();
                break;
        }
    }
}