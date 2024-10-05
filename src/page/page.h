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
        void addSelectableLine(std::string txt);
        void addTitle(std::string txt);

    private:
        void draw();
        void init();

        int _height;
        int _width;
        WINDOW* _win;

        std::vector<std::unique_ptr<AbstractLine>> _lines;
};
#endif // PAGE_H