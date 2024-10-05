cmake_minimum_required(VERSION 3.20)

project(termUi VERSION 1.0
               DESCRIPTION "Terminal Ui using ncurses"
               LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)


#
# ADD THIRD_PARTY
# 

add_subdirectory(third-party/sigslot)


#
# ADD .cpp & .h
# 

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE SRC
    ${SRC_DIR}/*.cpp
    ${SRC_DIR}/*.c
)

file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
set(INCLUDE_DIRS "")
foreach(HEADER_FILE ${HEADER_FILES})
    get_filename_component(HEADER_DIR ${HEADER_FILE} PATH)
    list(APPEND INCLUDE_DIRS ${HEADER_DIR})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)


#
# CHECK CONFIG FILE (term_ui_conf.h)
#

set(TERM_UI_CONF_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(TERM_UI_CONF_FILE "${CMAKE_CURRENT_SOURCE_DIR}/../term_ui_conf.h")

if(NOT EXISTS ${TERM_UI_CONF_FILE})
    message(WARNING "term_ui_conf.h not found in parent directory, using template.")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/term_ui_conf_template.h ${TERM_UI_CONF_FILE} COPYONLY)
endif()


#
# Link
# 

add_library(termUi STATIC ${SRC} ${HEADER_FILES})
target_include_directories(termUi PUBLIC ${SRC_DIR} ${INCLUDE_DIRS} ${TERM_UI_CONF_PATH})
target_link_libraries(termUi PUBLIC ncurses Pal::Sigslot)