/*
** EPITECH PROJECT, 2021
** create_win
** File description:
** set window & box
*/

#include "lib/my/my.h"

WINDOW *create_window(perso_t co)
{
    WINDOW *win = initscr();
    noecho();
    cbreak();
    curs_set(0);
    int touch = 0;
    while (LINES < co->wsizey || COLS < co->wsizex) {
        mvprintw(LINES / 2, COLS / 2 - 11, "Terminal is too small");
        touch = getch();
        if (touch == KEY_RESIZE)
            clear();
        refresh();
        if (touch == 27)
            end_win(co);
    }
    return (win);
}

void end_win(perso_t co)
{
    free (co);
    endwin();
    exit(0);
}