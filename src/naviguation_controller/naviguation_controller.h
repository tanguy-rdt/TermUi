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
        Page* getPageFromIdx(int idx);
        int getPageIdx(Page* page);
        void setCurrentPage(int idx);
        void setCurrentPage(Page* page);
        void setPreviousPage();

    private:
        std::vector<Page*> _pages;
        std::vector<Page*> _pagesHistory;
        std::vector<int> _pagesHistoryIdx;
        int _currentPage = 0;
};
#endif // NAVIGUATION_CONTROLLER_H