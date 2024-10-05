#ifndef CATEGORY_LINE_H
#define CATEGORY_LINE_H

#include <string>
#include <ncurses.h>

#include "abstract_line.h"

class CategoryLine: public AbstractLine {
    public:
        CategoryLine(WINDOW* win, int line, std::string txt);
        ~CategoryLine();

        void highlight(bool enable);
        void toggle();
        void draw();
        
    private:
        WINDOW* _win;
        int _line;
        std::string _txt;
};
#endif // CATEGORY_LINE_H