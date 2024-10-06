#ifndef PAGE_H
#define PAGE_H

#include <vector>
#include <string>
#include <memory>
#include <functional> 

#include <ncurses.h>

#include "abstract_line.h"
#include "abstract_menu.h"
#include "naviguation_controller.h"

class Page {
    public:
        Page(NavCtrl* navCtrl);
        Page(NavCtrl* navCtrl, int height, int width);
        ~Page();

        void show();
        void hide();
        void addTitle(std::string txt);
        void addCategoryLine(std::string txt);
        void addSelectableLine(std::string txt, std::function<void(bool)> callback);
        void addSelectableLine(std::string txt);
        void addEmbeddedPageLine(std::string txt, Page* page);
        AbstractMenu* addMenu();
        void addMenu(std::vector<std::string> btn, std::vector<std::function<void()>> callbacks);
        void goToFirstFocusableLine();
        void goToUpperLine();
        void goToLowerLine();
        void goToLeft();
        void goToRight();
        void switchBtwLineMenu();
        bool menuIsFocused();
        bool linesIsFocused();
        void interactWithLine();

    private:
        void draw();
        void init();

        NavCtrl* _navCtrl;

        int _height;
        int _width;
        WINDOW* _win;

        std::vector<std::unique_ptr<AbstractLine>> _lines;
        int _currentLine = 0;

        std::unique_ptr<AbstractMenu> _menu;
        bool _menuIsFocused = false;
};
#endif // PAGE_H