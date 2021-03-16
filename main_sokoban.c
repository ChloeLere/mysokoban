/*
** EPITECH PROJECT, 2021
** main
** File description:
** main of my_sokoban
*/

#include "lib/my/my.h"

int display_h(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_printf("USAGE\n");
        my_printf("\t./my_sokoban [map]\n");
        my_printf("DESCRIPTION\n");
        my_printf("\tmap file representing ");
        my_printf("the warehouse map, containing ‘#’ for walls,\n");
        my_printf("\t\t‘P’ for the player, ‘X’ for");
        my_printf(" boxes and ‘O’ for storage locations.\n");
        return (-1);
    }
    return (0);
}

int my_sokoban(char *map, inventory_t data)
{
    perso_t co = create_struct(map, data);
    WINDOW *win = create_window(co);

    my_sokoban_game(map, co, win);
    endwin();
    free(co);
    if (co->lose == 1)
        return (1);
    return (0);
}

inventory_t create_invetory(void)
{
    inventory_t data = malloc(sizeof(*data));

    data->nbr_box = 0;
    data->nbr_win = 0;
    data->nbr_block = 0;
    data->nb_bw = 0;
    return (data);
}

int main(int argc, char **argv)
{
    char *map = NULL;
    inventory_t data = create_invetory();

    if (argc < 2 || argc > 2) {
        my_putstr_error("not enough / too many arguments\n");
        return (84);
    }
    if (display_h(argv) < 0)
        return (0);
    if (open_file_int(argv[1]) == 84)
        return (84);
    map = open_file(argv[1]);
    if (error_map(map, data) < 0)
        return (84);
    return (my_sokoban(map, data));
}