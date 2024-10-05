#ifndef IN_PAGE_MENU_H
#define IN_PAGE_MENU_H

#include <string>
#include <vector>
#include <ncurses.h>

#include "abstract_menu.h"

class InPageMenu: public AbstractMenu {
    public:
        InPageMenu(WINDOW* win, std::vector<std::string> btnTxt);
        ~InPageMenu();
        
        void draw();
        void highlight(bool enable);
        void goToNext();
        void goToPrevious();

    private:
        void calcBtnPosX();

        WINDOW* _win;
        std::vector<std::string> _btn;
        std::vector<int> _btnPosX;
        int _currentBtn = 0;
        int _line = 0;
};
#endif // IN_PAGE_MENU_H