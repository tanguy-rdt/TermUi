#include "naviguation_controller.h"

#include "page.h"

NavCtrl::NavCtrl() {

}

NavCtrl::~NavCtrl() {

}

void NavCtrl::registerNewPage(Page* page) {
    _pages.push_back(page);
}

Page* NavCtrl::getCurrentPage() {
    return _pages[_currentPage];
}

void NavCtrl::setCurrentPage(int idx) {
    _currentPage = idx;
}

void NavCtrl::setCurrentPage(Page* page) {
    _currentPage = getPageIdx(page);
}

int NavCtrl::getPageIdx(Page* page) {
    for (int idx = 0; idx < _pages.size(); idx++) {
        if (_pages[idx] == page) {
            return idx; 
        }
    }

    return -1;
}
