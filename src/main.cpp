#include <ncurses.h>


int main()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    printw("Roguelike Init - Press any key to exit.");
    refresh();

    getch();

    endwin();

    return 0;
}