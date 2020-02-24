/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** player
*/

#include "navy.h"

int player_1(char **map_enemy, char **game_map)
{
    vector_t v = {0};

    while (!check_end(game_map) || check_end(map_enemy)) {
        print_2_map(game_map, map_enemy);
        if (check_end(game_map) || check_end(map_enemy))
            break;
        if (!write_attack(&v))
            return EXIT_ERROR;
        send_response(v, map_enemy);
        if (check_end(map_enemy)) {
            print_2_map(game_map, map_enemy);
            break;
        }
        my_putstr("waiting for enemy's attack...\n");
        v = receive_response(game_map);
    }
    free_2d_array(map_enemy);
    return 0;
}

int player_2(char **map_enemy, char **game_map)
{
    vector_t v = {0};

    s.signal_usr2 = 0;
    my_putstr("successfully connected\n\n");
    while (!check_end(game_map) || check_end(map_enemy)) {
        print_2_map(game_map, map_enemy);
        if (check_end(game_map) || check_end(map_enemy))
            break;
        my_putstr("waiting for enemy's attack...\n");
        v = receive_response(game_map);
        if (check_end(game_map)) {
            print_2_map(game_map, map_enemy);
            break;
        }
        if (!write_attack(&v))
            return EXIT_ERROR;
        send_response(v, map_enemy);
    }
    free_2d_array(map_enemy);
    return 0;
}