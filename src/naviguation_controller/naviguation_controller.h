#ifndef NAVIGUATION_CONTROLLER_H
#define NAVIGUATION_CONTROLLER_H

#include <vector>

class Page;

class NavCtrl {
    public:
        NavCtrl();
        ~NavCtrl();

        void registerNewPage(Page* page);
        Page* getCurrentPage();
        void setCurrentPage(int idx);
        void setCurrentPage(Page* page);
        int getPageIdx(Page* page);

    private:
        std::vector<Page*> _pages;
        int _currentPage = 0;


};
#endif // NAVIGUATION_CONTROLLER_H