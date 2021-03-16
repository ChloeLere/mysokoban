/*
** EPITECH PROJECT, 2021
** struct
** File description:
** init struct co
*/

#include "lib/my/my.h"

int find_max_x(char *map)
{
    int c = 0;

    for (; map[c] != '\n'; c++);
    return (c + 1);
}

int find_max_y(char *map)
{
    int x = 0;

    for (int c = 0; map[c] != '\0'; c++) {
        if (map[c] == '\n')
            x++;
    }
    return (x + 1);
}

int find_pos_y(char *map)
{
    int x = 0;

    for (int c = 0; map[c] != 'P'; c++) {
        if (map[c] == '\n')
            x++;
    }
    return (x);
}

int find_pos_x(char *map, int pos_p)
{
    int c = 0;
    int i = 0;

    for (int x = 0; pos_p > x; i++) {
        if (map[i] == '\n')
            pos_p--;
    }
    for (; map[i] != 'P'; i++, c++);
    return (c);
}

perso_t create_struct(char *map, inventory_t data)
{
    perso_t p = malloc(sizeof(*p));

    p->wsizex = find_max_x(map);
    p->wsizey = find_max_y(map);
    p->posy = find_pos_y(map);
    p->posx = find_pos_x(map, p->posy);
    p->map = char_2d_map(map, p->wsizex, p->wsizey);
    p->buffer = map;
    p->inv = data;
    p->origin_map = char_2d_map(map, p->wsizex, p->wsizey);
    p->lose = 0;
    return (p);
}