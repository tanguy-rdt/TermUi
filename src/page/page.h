#ifndef PAGE_H
#define PAGE_H

#include <vector>
#include <string>
#include <memory>
#include <ncurses.h>

#include "abstract_line.h"

class Page {
    public:
        Page();
        Page(int height, int width);
        ~Page();

        void show();
        void hide();
        void addTitle(std::string txt);
        void addCategoryLine(std::string txt);
        void addSelectableLine(std::string txt);
        void goToFirstFocusableLine();
        void goToUpperLine();
        void goToLowerLine();
        void interactWithLine();

    private:
        void draw();
        void init();

        int _height;
        int _width;
        WINDOW* _win;

        std::vector<std::unique_ptr<AbstractLine>> _lines;
        int _currentLine = 0;
};
#endif // PAGE_H