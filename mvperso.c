/*
** EPITECH PROJECT, 2021
** mvperso
** File description:
** move perso
*/

#include "lib/my/my.h"

void mvperso(WINDOW *win, perso_t co, char **map, int touch)
{
    if (touch == KEY_UP)
        move_up(co, win, map);
    if (touch == KEY_DOWN)
        move_down(co, win, map);
    if (touch == KEY_LEFT)
        move_left(co, win, map);
    if (touch == KEY_RIGHT)
        move_right(co, win, map);
    if (touch == ' ')
        my_space(co, win);
    if (touch == KEY_RESIZE)
        reprint_win(co, win);
}