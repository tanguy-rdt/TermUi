#ifndef SELECTABLE_LINE_H
#define SELECTABLE_LINE_H

#include <string>
#include <functional>
#include <ncurses.h>

#include "sigslot/signal.hpp"

#include "abstract_line.h"

class SelectableLine: public AbstractLine {
    public:
        SelectableLine(WINDOW* win, int line, std::string txt, void (*callback)(bool));
        ~SelectableLine();

        void highlight(bool enable);
        void toggle();
        void draw();

    private:
        void drawCheckedLine();
        void drawUncheckedLine();

        sigslot::signal<bool> onToggle;
        
        WINDOW* _win;
        int _line;
        std::string _txt;
        bool _checked = false;
};
#endif // SELECTABLE_LINE_H