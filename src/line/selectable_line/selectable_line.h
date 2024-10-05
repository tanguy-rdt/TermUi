#ifndef SELECTABLE_LINE_H
#define SELECTABLE_LINE_H

#include <string>
#include <ncurses.h>

#include "abstract_line.h"

class SelectableLine: public AbstractLine {
    public:
        SelectableLine(WINDOW* win, int line, std::string txt);
        ~SelectableLine();

        void highlight(bool enable);
        void toggle();
        void draw();
        
    private:
        void drawCheckedLine();
        void drawUncheckedLine();
        
        WINDOW* _win;
        int _line;
        std::string _txt;
        const std::string _txtChecked = "    [x] ";
        const std::string _txtUnchecked = "    [ ] ";
        bool _checked = false;
};
#endif // SELECTABLE_LINE_H