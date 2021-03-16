/*
** EPITECH PROJECT, 2021
** move_perso
** File description:
** handling move perso
*/

#include "lib/my/my.h"

void move_up(perso_t co, WINDOW *win, char **map)
{
    if (co->map[co->posy - 1][co->posx] == '#'
    || co->posy - 1 <= 0)
        return;
    if (move_box(co, 0, win) < 0)
        return;
    mvwaddch(win, co->posy, co->posx, ' ');
    co->map[co->posy][co->posx] = ' ';
    if (map[co->posy][co->posx] == 'O')
        mvwaddch(win, co->posy, co->posx, 'O');
    co->posy -= 1;
    mvwaddch(win, co->posy, co->posx, 'P');
    co->map[co->posy][co->posx] = ' ';
}

void move_down(perso_t co, WINDOW *win, char **map)
{
    if (co->map[co->posy + 1][co->posx] == '#'
    || co->posy + 1 > co->wsizey - 2)
        return;
    if (move_box(co, 1, win) < 0)
        return;
    mvwaddch(win, co->posy, co->posx, ' ');
    co->map[co->posy][co->posx] = ' ';
    if (map[co->posy][co->posx] == 'O')
        mvwaddch(win, co->posy, co->posx, 'O');
    co->posy += 1;
    mvwaddch(win, co->posy, co->posx, 'P');
    co->map[co->posy][co->posx] = 'P';
}

void move_left(perso_t co, WINDOW *win, char **map)
{
    if (co->map[co->posy][co->posx - 1] == '#'
    || co->posx - 1 <= 0)
        return;
    if (move_box(co, 2, win) < 0)
        return;
    mvwaddch(win, co->posy, co->posx, ' ');
    co->map[co->posy][co->posx] = ' ';
    if (map[co->posy][co->posx] == 'O')
        mvwaddch(win, co->posy, co->posx, 'O');
    co->posx -= 1;
    mvwaddch(win, co->posy, co->posx, 'P');
    co->map[co->posy][co->posx] = 'P';
}

void move_right(perso_t co, WINDOW *win, char **map)
{
    if (co->map[co->posy][co->posx + 1] == '#'
    || co->posx + 1 >= co->wsizex)
        return;
    if (move_box(co, 3, win) < 0)
        return;
    mvwaddch(win, co->posy, co->posx, ' ');
    co->map[co->posy][co->posx] = ' ';
    if (map[co->posy][co->posx] == 'O')
        mvwaddch(win, co->posy, co->posx, 'O');
    co->posx += 1;
    mvwaddch(win, co->posy, co->posx, 'P');
    co->map[co->posy][co->posx] = 'P';
}

void move_perso(WINDOW *win, perso_t co, char **map)
{
    int touch = 0;
    keypad(win, true);
    while (1) {
        touch = wgetch(win);
        mvperso(win, co, map, touch);
        if (co->inv->nbr_block == (co->inv->nbr_box - co->inv->nb_bw)
        && co->inv->nbr_block > 0)
            co->lose = 1;
        if (co->inv->nbr_win == 0 || touch == 27 || co->lose == 1)
            return;
    }
}