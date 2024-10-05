#ifndef TERM_UI_H
#define TERM_UI_H

#include <ncurses.h>

class TermUi {
    public:
        TermUi();
        ~TermUi();

        void init();

    private:
        void initColor();
        void initWin();

        WINDOW* _win;
};
#endif // TERM_UI_H