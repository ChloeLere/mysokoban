/*
** EPITECH PROJECT, 2021
** convert_map
** File description:
** conver map char * to char **
*/

#include "lib/my/my.h"

char **char_2d_map(char *map, int lng, int larg)
{
    char **new_map = malloc(sizeof(char *) * larg);
    int i = 0;

    for (int x = 0; x < larg; x++) {
        new_map[x] = malloc(sizeof(char) * lng);
        for (int y = 0; y < lng; y++, i++) {
            new_map[x][y] = map[i];
        }
    }
    return (new_map);
}