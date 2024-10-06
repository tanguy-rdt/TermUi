#ifndef EMBEDDED_PAGE_LINE_H
#define EMBEDDED_PAGE_LINE_H

#include <string>
#include <ncurses.h>

#include "abstract_line.h"

class Page;
class NavCtrl;

class EmbeddedPageLine: public AbstractLine {
    public:
        EmbeddedPageLine(WINDOW* win, int line, std::string txt, Page* page, NavCtrl* navCtrl);
        ~EmbeddedPageLine();

        void highlight(bool enable);
        void toggle();
        void draw();

    private:

        WINDOW* _win;
        int _line;
        std::string _txt;

        Page* _page;
        NavCtrl* _navCtrl;
};
#endif // EMBEDDED_PAGE_LINE_H