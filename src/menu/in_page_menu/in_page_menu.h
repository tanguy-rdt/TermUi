#ifndef IN_PAGE_MENU_H
#define IN_PAGE_MENU_H

#include <string>
#include <vector>
#include <ncurses.h>

#include "sigslot/signal.hpp"

#include "abstract_menu.h"

class InPageMenu: public AbstractMenu {
    public:
        InPageMenu(WINDOW* win, std::vector<std::string> btnTxt, std::vector<void (*)()> callbacks);
        InPageMenu(WINDOW* win);
        ~InPageMenu();
        
        void draw();
        void addBtn(std::string txt, void (*callback)());
        void highlight(bool enable);
        void goToNext();
        void goToPrevious();
        void select();

    private:
        void calcBtnPosX();

        std::vector<std::unique_ptr<sigslot::signal<>>> sigs;

        WINDOW* _win;
        std::vector<std::string> _btn;
        std::vector<int> _btnPosX;
        int _currentBtn = 0;
        int _line = 0;
};
#endif // IN_PAGE_MENU_H