#ifndef PAGE_H
#define PAGE_H

#include <ncurses.h>

class Page {
    public:
        Page();
        Page(int height, int width);
        ~Page();

        void show();
        void hide();

    private:
        void draw();
        
        int _height;
        int _width;
        WINDOW* _win;
};
#endif // PAGE_H