#include "in_page_menu.h"
#include "term_ui_conf_internal.h"

InPageMenu::InPageMenu(WINDOW* win, std::vector<std::string> btnTxt)
    : _win(win), _btn(btnTxt) {

    int winHeight, winWidth;
    getmaxyx(_win, winHeight, winWidth);
    _line = winHeight - 2;
    
    calcBtnPosX();
    draw();
}

InPageMenu::~InPageMenu(){

}

void InPageMenu::draw() {
    if (_btn.size() != _btnPosX.size())
        return;

    for (int idx = 0; idx < _btn.size(); idx++) {
        mvwprintw(_win, _line, _btnPosX[idx], "%s", _btn[idx].c_str());
    }
    wrefresh(_win);  
}


void InPageMenu::highlight(bool enable) {
    if (_btn.size() != _btnPosX.size())
        return;

    for (int idx = 0; idx < _btn.size(); idx++) {
        if (enable && _currentBtn == idx) {
            wattron(_win, COLOR_PAIR(TUI_HIGHLIGHT_COLOR_IDX));
            mvwprintw(_win, _line, _btnPosX[idx], "%s", _btn[idx].c_str());
            wattroff(_win, COLOR_PAIR(TUI_HIGHLIGHT_COLOR_IDX));
        } else {
            wattroff(_win, COLOR_PAIR(TUI_HIGHLIGHT_COLOR_IDX));
            mvwprintw(_win, _line, _btnPosX[idx], "%s", _btn[idx].c_str());
        }
    }
    wrefresh(_win);  
}

void InPageMenu::goToPrevious() {
    if (_currentBtn > 0) {
        _currentBtn--;
        highlight(true);
    }
}

void InPageMenu::goToNext() {
    if (_currentBtn < _btn.size() - 1) {
        _currentBtn++;
        highlight(true);
    }
}

void InPageMenu::calcBtnPosX() {
    int totalBtnLength = 0;
    for (const auto& el : _btn) {
        totalBtnLength += el.size();
    }

    int winHeight, winWidth;
    getmaxyx(_win, winHeight, winWidth);

    int availableSpace = winWidth - totalBtnLength;
    int gapBetweenBtns = 0;
    if (_btn.size() > 1) {
        gapBetweenBtns = availableSpace / (_btn.size() + 1);
    } else {
        gapBetweenBtns = availableSpace / 2;
    }

    int currentPosX = gapBetweenBtns;
    _btnPosX.clear();
    for (const auto& el : _btn) {
        _btnPosX.push_back(currentPosX);
        currentPosX += el.size() + gapBetweenBtns;
    }
}