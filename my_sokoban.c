/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** handling game
*/

#include "lib/my/my.h"

void my_sokoban_game(char *map, perso_t co, WINDOW *win)
{
    wprintw(win, map);
    move_perso(win, co, char_2d_map(map, co->wsizex, co->wsizey));
}