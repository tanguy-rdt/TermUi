#ifndef ABSTRACT_MENU_H
#define ABSTRACT_MENU_H

class AbstractMenu {
    public:
        virtual ~AbstractMenu() {}

        virtual void draw() = 0;
        virtual void highlight(bool enable) = 0;
        virtual void goToNext() = 0;
        virtual void goToPrevious() = 0;

    private:

};

#endif // ABSTRACT_MENU_H