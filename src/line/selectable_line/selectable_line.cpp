#include "selectable_line.h"
#include "term_ui_conf_internal.h"

SelectableLine::SelectableLine(WINDOW* win, int line, std::string txt, void (*callback)(bool))
    : _win(win), _line(line), _txt(txt) {

    addInteraction(AbstractLine::LineInteraction::FOCUSABLE);
    addInteraction(AbstractLine::LineInteraction::SELECTABLE);

    onToggle.connect(callback);

    drawUncheckedLine();
}

SelectableLine::~SelectableLine(){

}

void SelectableLine::highlight(bool enable) {
    enable ? wattron(_win, COLOR_PAIR(TUI_HIGHLIGHT_COLOR_IDX)) : wattroff(_win, COLOR_PAIR(TUI_HIGHLIGHT_COLOR_IDX));
    _checked ? drawCheckedLine() : drawUncheckedLine();
}

void SelectableLine::toggle() {
    _checked = !_checked;
    _checked ? drawCheckedLine() : drawUncheckedLine();
    onToggle(_checked);
}

void SelectableLine::draw() {
    _checked ? drawCheckedLine() : drawUncheckedLine();
}

void SelectableLine::drawCheckedLine() {
    std::string txt = _txtChecked + _txt;
    mvwprintw(_win, _line, 3, "%s", txt.c_str());
    wrefresh(_win);
}

void SelectableLine::drawUncheckedLine() {
    std::string txt = _txtUnchecked + _txt;
    mvwprintw(_win, _line, 3, "%s", txt.c_str());
    wrefresh(_win);
}