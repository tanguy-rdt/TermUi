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

Page* NavCtrl::getPageFromIdx(int idx) {
    return _pages[idx];
}

int NavCtrl::getPageIdx(Page* page) {
    for (int idx = 0; idx < _pages.size(); idx++) {
        if (_pages[idx] == page) {
            return idx; 
        }
    }

    return -1;
}

void NavCtrl::setCurrentPage(int idx) {
    if (idx >= 0 && idx < _pages.size()) {
        if (_pages[_currentPage]->menuIsFocused())
            _pages[_currentPage]->switchBtwLineMenu();

        _pagesHistory.push_back(getCurrentPage());
        _pagesHistoryIdx.push_back(_currentPage);
        _pages[_currentPage]->hide();
        _currentPage = idx;
        _pages[_currentPage]->show();
        _pages[_currentPage]->goToFirstFocusableLine();
    }
}

void NavCtrl::setCurrentPage(Page* page) {
    setCurrentPage(getPageIdx(page));
}

void NavCtrl::setPreviousPage() {
    if (!_pagesHistory.empty()) {
        Page* lastPage = _pagesHistory.back();
        _pagesHistory.pop_back();
        _pagesHistoryIdx.pop_back();

        setCurrentPage(lastPage);
    }
}