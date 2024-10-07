#ifndef TERM_UI_H
#define TERM_UI_H

#include <vector>
#include <string>
#include <memory>

#include <ncurses.h>

#include "page.h"
#include "naviguation_controller.h"

class TermUi {
    public:
        TermUi();
        ~TermUi();

        Page* addPage();
        Page* addPage(int height, int width);
        void showPage(Page* page);
        void showPage(int idx);
        void showMainPage();
        void showPreviousPage();
        int run();
        void quit(int ret);

    private:
        void initColor();

        std::unique_ptr<NavCtrl> _navCtrl;

        std::vector<std::unique_ptr<Page>> _pages;
        int _currentPage = 0;
        bool _running = false;
        int _returnValue = 0;
};
#endif // TERM_UI_H