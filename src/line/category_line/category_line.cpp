#include "category_line.h"
#include "term_ui_conf_internal.h"

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
    std::string txt = TUI_PREFIX_CATEGORY_LINE + _txt + TUI_SUFIX_CATEGORY_LINE;

    wattron(_win, A_BOLD);
    mvwprintw(_win, _line, 3, "%s", txt.c_str());
    wattroff(_win, A_BOLD);
    wrefresh(_win);
}