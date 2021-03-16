/*
** EPITECH PROJECT, 2021
** next_case
** File description:
** next pos
*/

#include "lib/my/my.h"

int move_box_up(perso_t co, WINDOW *win)
{
    if (co->map[co->posy - 2][co->posx] == ' '
    || co->origin_map[co->posy - 2][co->posx] == 'O') {
        if (co->origin_map[co->posy - 2][co->posx] == 'O') {
            co->inv->nbr_win--;
            co->inv->nb_bw++;
        }
        if (co->origin_map[co->posy - 1][co->posx] == 'O') {
            co->inv->nbr_win++;
            co->inv->nb_bw--;
        }
        mvwaddch(win, co->posy - 2, co->posx, 'X');
        mvwaddch(win, co->posy - 1, co->posx, ' ');
        co->map[co->posy - 1][co->posx] = ' ';
        co->map[co->posy - 2][co->posx] = 'X';
        if (co->origin_map[co->posy - 2][co->posx] != 'O')
            is_lose(co, win, 0);
        return (0);
    }
    return (-1);
}

int move_box_down(perso_t co, WINDOW *win)
{
    if (co->map[co->posy + 2][co->posx] == ' '
    || co->origin_map[co->posy + 2][co->posx] == 'O') {
        if (co->origin_map[co->posy + 2][co->posx] == 'O') {
            co->inv->nbr_win--;
            co->inv->nb_bw++;
        }
        if (co->origin_map[co->posy + 1][co->posx] == 'O') {
            co->inv->nbr_win++;
            co->inv->nb_bw--;
        }
        mvwaddch(win, co->posy + 2, co->posx, 'X');
        mvwaddch(win, co->posy + 1, co->posx, ' ');
        co->map[co->posy + 1][co->posx] = ' ';
        co->map[co->posy + 2][co->posx] = 'X';
        if (co->origin_map[co->posy + 2][co->posx] != 'O')
            is_lose(co, win, 1);
        return (0);
    }
    return (-1);
}

int move_box_left(perso_t co, WINDOW *win)
{
    if (co->map[co->posy][co->posx - 2] == ' '
    || co->origin_map[co->posy][co->posx - 2] == 'O') {
        if (co->origin_map[co->posy][co->posx - 2] == 'O') {
            co->inv->nbr_win--;
            co->inv->nb_bw++;
        }
        if (co->origin_map[co->posy][co->posx - 1] == 'O') {
            co->inv->nbr_win++;
            co->inv->nb_bw--;
        }
        mvwaddch(win, co->posy, co->posx - 2, 'X');
        mvwaddch(win, co->posy, co->posx - 1, ' ');
        co->map[co->posy][co->posx - 1] = ' ';
        co->map[co->posy][co->posx - 2] = 'X';
        if (co->origin_map[co->posy][co->posx - 2] != 'O')
            is_lose(co, win, 2);
        return (0);
    }
    return (-1);
}

int move_box_right(perso_t co, WINDOW *win)
{
    if (co->map[co->posy][co->posx + 2] == ' '
    || co->origin_map[co->posy][co->posx + 2] == 'O') {
        if (co->origin_map[co->posy][co->posx + 2] == 'O') {
            co->inv->nb_bw++;
            co->inv->nbr_win--;
        }
        if (co->origin_map[co->posy][co->posx + 1] == 'O') {
            co->inv->nb_bw--;
            co->inv->nbr_win++;
        }
        mvwaddch(win, co->posy, co->posx + 2, 'X');
        mvwaddch(win, co->posy, co->posx + 1, ' ');
        co->map[co->posy][co->posx + 1] = ' ';
        co->map[co->posy][co->posx + 2] = 'X';
        if (co->origin_map[co->posy][co->posx + 2] != 'O')
            is_lose(co, win, 3);
        return (0);
    }
    return (-1);
}

int move_box(perso_t co, int s, WINDOW *win)
{
    if (s == 0 && co->map[co->posy - 1][co->posx] == 'X') {
        return (move_box_up(co, win));
    }
    if (s == 1 && co->map[co->posy + 1][co->posx] == 'X') {
        return (move_box_down(co, win));
    }
    if (s == 2 && co->map[co->posy][co->posx - 1] == 'X') {
        return (move_box_left(co, win));
    }
    if (s == 3 && co->map[co->posy][co->posx + 1] == 'X') {
        return (move_box_right(co, win));
    }
    return (0);
}