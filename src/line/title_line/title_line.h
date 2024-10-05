#ifndef TITLE_LINE_H
#define TITLE_LINE_H

#include <string>
#include <ncurses.h>

#include "abstract_line.h"

class TitleLine: public AbstractLine {
    public:
        TitleLine(WINDOW* win, int line, std::string txt);
        ~TitleLine();

        void highlight(bool enable);
        void toggle();
        void draw();
        
    private:
        WINDOW* _win;
        int _line;
        std::string _txt;
};
#endif // TITLE_LINE_H