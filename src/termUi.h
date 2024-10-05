#ifndef TERM_UI_H
#define TERM_UI_H

#include <vector>
#include <string>
#include <memory>

#include <ncurses.h>

#include <page.h>

class TermUi {
    public:
        TermUi();
        ~TermUi();

        void init();
        void addPage();
        void addPage(int height, int width);
        void showPage(int idx);
        void showMainPage();

    private:
        void initColor();

        std::vector<std::unique_ptr<Page>> _pages;
        int _currentPage = 0;
};
#endif // TERM_UI_H