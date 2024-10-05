#include "title_line.h"

TitleLine::TitleLine(WINDOW* win, int line, std::string txt)
    : _win(win), _line(line), _txt(txt) {

    addInteraction(AbstractLine::LineInteraction::UNFOCUSABLE);
    draw();
}

TitleLine::~TitleLine(){

}

void TitleLine::highlight(bool enable) { }

void TitleLine::toggle() { }

void TitleLine::draw() {
    int winHeight, winWidth;
    getmaxyx(_win, winHeight, winWidth);

    int posX = (winWidth - _txt.size())/2;
    wattron(_win, A_BOLD);
    mvwprintw(_win, _line, posX, "%s", _txt.c_str());
    wattroff(_win, A_BOLD);
    wrefresh(_win);
}