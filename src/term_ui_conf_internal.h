#ifndef TERM_UI_CONF_INTERNAL_H

#ifdef __has_include
    #if __has_include("term_ui_conf.h")
        #include "term_ui_conf.h"
    #else
        #error "term_ui_conf.h is missing"
    #endif
#endif

#endif // TERM_UI_CONF_INTERNAL_H


//
// WINDOWS SIZE
//

#if RATIO_WIN_SIZED == 0
    #undef RATIO_WIN_SIZED
#endif

#ifdef CONF_TUI_WIN_HEIGHT
    #define TUI_WIN_HEIGHT CONF_TUI_WIN_HEIGHT
#else
    #error "term_ui_conf.h: CONF_TUI_WIN_HEIGHT is missing"
#endif

#ifdef CONF_TUI_WIN_WIDTH
    #define TUI_WIN_WIDTH CONF_TUI_WIN_WIDTH
#else
    #error "term_ui_conf.h: CONF_TUI_WIN_WIDTH is missing"
#endif


//
// COLORS
//

#if USE_COLOR == 1
    #ifdef CONF_TUI_BACKGROUND_COLOR
        #define TUI_BACKGROUND_COLOR     CONF_TUI_BACKGROUND_COLOR
        #define TUI_BACKGROUND_COLOR_IDX 1
    #endif

    #ifdef CONF_TUI_WIN_BACKGROUND_COLOR
        #define TUI_WIN_BACKGROUND_COLOR     CONF_TUI_WIN_BACKGROUND_COLOR
        #define TUI_WIN_BACKGROUND_COLOR_IDX 2
    #endif

    #ifdef CONF_TUI_HIGHLIGHT_COLOR
        #define TUI_HIGHLIGHT_COLOR     CONF_TUI_HIGHLIGHT_COLOR
        #define TUI_HIGHLIGHT_COLOR_IDX 3
    #endif
#else
    #undef USE_COLOR
#endif // USE_COLOR == 1


//
// CUSTOM LINES
//

#if USE_CUSTOM_LINES == 1
    #define TUI_PREFIX_TITLE_LINE CONF_TUI_PREFIX_TITLE_LINE
    #define TUI_SUFIX_TITLE_LINE  CONF_TUI_SUFIX_TITLE_LINE

    #define TUI_PREFIX_CATEGORY_LINE CONF_TUI_PREFIX_CATEGORY_LINE
    #define TUI_SUFIX_CATEGORY_LINE  CONF_TUI_SUFIX_CATEGORY_LINE

    #define TUI_CHECKED_SELECTABLE_LINE   CONF_TUI_CHECKED_SELECTABLE_LINE
    #define TUI_UNCHECKED_SELECTABLE_LINE CONF_TUI_UNCHECKED_SELECTABLE_LINE
#else
    #undef USE_CUSTOM_LINES

    #define TUI_PREFIX_TITLE_LINE ""
    #define TUI_SUFIX_TITLE_LINE  ""

    #define TUI_PREFIX_CATEGORY_LINE "-- "
    #define TUI_SUFIX_CATEGORY_LINE  ""

    #define TUI_CHECKED_SELECTABLE_LINE   "  [x] "
    #define TUI_UNCHECKED_SELECTABLE_LINE "  [ ] "
#endif



