#include "Game.hpp"
#include <ncurses.h>

/** @copydoc Game::Game() */
Game::Game()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    is_running = true;
    player_x = 10;
    player_y = 10;
}

/** @copydoc Game::~Game() */
Game::~Game()
{
    endwin();
}

/** @copydoc void Game::run() */
void Game::run()
{
    while (is_running)
    {
        render();
        process_input();
    }
}

/** @copydoc Game::process_input() */
void Game::process_input()
{
    int ch = getch();

    switch (ch)
    {
    case 'q':
    case 'Q':
        is_running = false;
        break;
    case KEY_UP:
        player_y--;
        break;
    case KEY_DOWN:
        player_y++;
        break;
    case KEY_LEFT:
        player_x--;
        break;
    case KEY_RIGHT:
        player_x++;
        break;
    default:
        break;
    }
}

/** @copydoc Game::render() */
void Game::render()
{
    clear();

    mvaddch(player_y, player_x, '@');

    mvprintw(0, 0, "Use Arrow Keys to move. Press 'q' to quit.");

    refresh();
}
