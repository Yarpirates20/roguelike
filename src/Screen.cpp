#include "Screen.hpp"
#include <ncurses.h>

/** @copydoc Screen::Screen() */
Screen::Screen()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}

/** @copydoc Screen::~Screen() */
Screen::~Screen()/*  */
{
    endwin();
}

/** @copydoc Screen::add(const char *message) */
void Screen::add(const char *message)
{
    printw(message);
}


/** @copydoc Screen::height() */
int Screen::height()
{
    return m_height;
}

/** @copydoc Screen::width() */
int Screen::width()
{
    return m_width;
}