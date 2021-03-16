/*
** EPITECH PROJECT, 2021
** space.c
** File description:
** restart game
*/

#include "lib/my/my.h"

void my_space(perso_t p, WINDOW *win)
{
    wclear(win);
    wrefresh(win);
    p->map = char_2d_map(p->buffer, p->wsizex, p->wsizey);
    p->posy = find_pos_y(p->buffer);
    p->posx = find_pos_x(p->buffer, p->posy);
    p->map[p->posy][p->posx] = ' ';
    p->lose = 0;
    p->inv->nbr_block = 0;
    p->inv->nb_bw = 0;
    wprintw(win, "%s", p->buffer);
    wrefresh(win);
    p->inv->nbr_win = p->inv->nbr_box;
}