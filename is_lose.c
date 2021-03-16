/*
** EPITECH PROJECT, 2021
** is_lose
** File description:
** find if boxes are block
*/

#include "lib/my/my.h"

void is_lose_u(perso_t co, WINDOW *win)
{
    int wall = 0;
    int wallc = 0;
    if (co->origin_map[co->posy - 2][co->posx + 1] == '#'
    || co->map[co->posy - 2][co->posx + 1] == 'X')
        wall++;
    if (co->origin_map[co->posy - 2][co->posx - 1] == '#'
    || co->map[co->posy - 2][co->posx - 1] == 'X')
        wall++;
    if (co->origin_map[co->posy - 1][co->posx] == '#'
    || co->map[co->posy - 1][co->posx] == 'X')
        wallc++;
    if (co->origin_map[co->posy - 3][co->posx] == '#'
    || co->map[co->posy - 3][co->posx] == 'X')
        wallc++;
    if (wall >= 1 && wallc >= 1)
        co->inv->nbr_block++;
    if (co->inv->nbr_block == (co->inv->nbr_box - co->inv->nb_bw)
    && co->inv->nbr_block > 0)
        co->lose = 1;
}

void is_lose_d(perso_t co, WINDOW *win)
{
    int wall = 0;
    int wallc = 0;
    if (co->origin_map[co->posy + 2][co->posx + 1] == '#'
    || co->map[co->posy + 2][co->posx + 1] == 'X')
        wall++;
    if (co->origin_map[co->posy + 2][co->posx - 1] == '#'
    || co->map[co->posy + 2][co->posx - 1] == 'X')
        wall++;
    if (co->origin_map[co->posy + 1][co->posx] == '#'
    || co->map[co->posy + 1][co->posx] == 'X')
        wallc++;
    if (co->origin_map[co->posy + 3][co->posx] == '#'
    || co->map[co->posy + 3][co->posx] == 'X')
        wallc++;
    if (wall >= 1 && wallc >= 1)
        co->inv->nbr_block++;
    if (co->inv->nbr_block == (co->inv->nbr_box - co->inv->nb_bw)
    && co->inv->nbr_block > 0)
        co->lose = 1;
}

void is_lose_l(perso_t co, WINDOW *win)
{
    int wall = 0;
    int wallc = 0;
    if (co->origin_map[co->posy][co->posx - 1] == '#'
    || co->map[co->posy][co->posx - 1] == 'X')
        wall++;
    if (co->origin_map[co->posy][co->posx - 3] == '#'
    || co->map[co->posy][co->posx - 3] == 'X')
        wall++;
    if (co->origin_map[co->posy + 1][co->posx - 2] == '#'
    || co->map[co->posy + 1][co->posx - 2] == 'X')
        wallc++;
    if (co->origin_map[co->posy - 1][co->posx - 2] == '#'
    || co->map[co->posy - 1][co->posx - 2] == 'X')
        wallc++;
    if (wall >= 1 && wallc >= 1)
        co->inv->nbr_block++;
    if (co->inv->nbr_block == (co->inv->nbr_box - co->inv->nb_bw)
    && co->inv->nbr_block > 0)
        co->lose = 1;
}

void is_lose_r(perso_t co, WINDOW *win)
{
    int wall = 0;
    int wallc = 0;
    if (co->origin_map[co->posy][co->posx + 3] == '#'
    || co->map[co->posy][co->posx + 3] == 'X')
        wall++;
    if (co->origin_map[co->posy][co->posx + 1] == '#'
    || co->map[co->posy][co->posx + 1] == 'X')
        wall++;
    if (co->origin_map[co->posy + 1][co->posx + 2] == '#'
    || co->map[co->posy + 1][co->posx + 2] == 'X')
        wallc++;
    if (co->origin_map[co->posy - 1][co->posx + 2] == '#'
    || co->map[co->posy - 1][co->posx + 2] == 'X')
        wallc++;
    if (wall >= 1 && wallc >= 1)
        co->inv->nbr_block++;
    if (co->inv->nbr_block == (co->inv->nbr_box - co->inv->nb_bw)
    && co->inv->nbr_block > 0)
        co->lose = 1;
}

void is_lose(perso_t co, WINDOW *win, int x)
{
    if (x == 0)
        is_lose_u(co, win);
    if (x == 1)
        is_lose_d(co, win);
    if (x == 2)
        is_lose_l(co, win);
    if (x == 3)
        is_lose_r(co, win);
}