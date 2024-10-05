#include "category_line.h"

CategoryLine::CategoryLine(WINDOW* win, int line, std::string txt)
    : _win(win), _line(line), _txt(txt) {

    addInteraction(AbstractLine::LineInteraction::UNFOCUSABLE);
    draw();
}

CategoryLine::~CategoryLine(){

}

void CategoryLine::highlight(bool enable) { }

void CategoryLine::toggle() { }

void CategoryLine::draw() {
    wattron(_win, A_BOLD);
    mvwprintw(_win, _line, 3, "-- %s", _txt.c_str());
    wattroff(_win, A_BOLD);
    wrefresh(_win);
}