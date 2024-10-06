#ifndef ABSTRACT_MENU_H
#define ABSTRACT_MENU_H

#include <functional>

class AbstractMenu {
    public:
        virtual ~AbstractMenu() {}

        virtual void draw() = 0;
        virtual void addBtn(std::string txt, std::function<void()> callback) = 0;
        virtual void highlight(bool enable) = 0;
        virtual void goToNext() = 0;
        virtual void goToPrevious() = 0;
        virtual void select() = 0;

    private:

};

#endif // ABSTRACT_MENU_H