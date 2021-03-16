/*
** EPITECH PROJECT, 2021
** resize
** File description:
** if resize
*/

#include "lib/my/my.h"

void reprint_win(perso_t co, WINDOW *win)
{
    wclear(win);
    wrefresh(win);
    if (too_small(co, win) < 0)
        return;
    for (int x = 0; x < co->wsizey; x++)
        wprintw(win, "%s", co->map[x]);
    wrefresh(win);
}

int too_small(perso_t co, WINDOW *win)
{
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
    return (0);
}