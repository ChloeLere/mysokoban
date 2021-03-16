/*
** EPITECH PROJECT, 2021
** error_map
** File description:
** handling error map
*/

#include "lib/my/my.h"

int check_char_map(char map)
{
    if (map != 'O' && map != 'X' && map != 'P'
    && map != '#' && map != ' ' && map != '\n')
        return (-1);
    return (0);
}

int error_map(char *map, inventory_t data)
{
    int nbr_p = 0;
    for (int c = 0; map[c] != '\0'; c++) {
        if (map[c] == 'O')
            data->nbr_win++;
        if (map[c] == 'X')
            data->nbr_box++;
        if (map[c] == 'P')
            nbr_p++;
        if (check_char_map(map[c]) == -1) {
            my_putstr_error("Error\n");
            return (-1);
        }
    }
    if (data->nbr_box != data->nbr_win || nbr_p != 1 || data->nbr_box == 0) {
        my_putstr_error("Error\n");
        return (-1);
    }
    return (0);
}