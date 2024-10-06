#include "embedded_page_line.h"

#include "term_ui_conf_internal.h"
#include "naviguation_controller.h"


EmbeddedPageLine::EmbeddedPageLine(WINDOW* win, int line, std::string txt, Page* page, NavCtrl* navCtrl)
    : _win(win), _line(line), _txt(txt),  _page(page), _navCtrl(navCtrl) {

    addInteraction(AbstractLine::LineInteraction::FOCUSABLE);
    addInteraction(AbstractLine::LineInteraction::SELECTABLE);
    addInteraction(AbstractLine::LineInteraction::EMBEDDED_PAGE);

}

EmbeddedPageLine::~EmbeddedPageLine(){

}

void EmbeddedPageLine::highlight(bool enable) {
    enable ? wattron(_win, COLOR_PAIR(TUI_HIGHLIGHT_COLOR_IDX)) : wattroff(_win, COLOR_PAIR(TUI_HIGHLIGHT_COLOR_IDX));
    draw();
}

void EmbeddedPageLine::toggle() {
    _navCtrl->setCurrentPage(_page);
}

void EmbeddedPageLine::draw() {
    std::string txt = TUI_PREFIX_EMBEDDED_PAGE_LINE + _txt + TUI_SUFIX_EMBEDDED_PAGE_LINE;
    mvwprintw(_win, _line, 3, "%s", txt.c_str());
    wrefresh(_win);
}