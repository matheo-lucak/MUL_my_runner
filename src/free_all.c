/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void free_map_data(char **map)
{
    int i = 0;

    if (map == NULL || map[0] == NULL)
        return ;
    while (map[i] != NULL) {
        free(map[i]);
        i++;
    }
    free(map);
}

void destroy_map_data(map_t *map_data)
{
    if (map_data != NULL) {
        if (map_data->next != NULL)
            destroy_map_data(map_data->next);
        free_map_data(map_data->map);
        free(map_data);
        map_data = NULL;
    }
}

void free_win(win_t *win)
{
    sfRenderWindow_destroy(win->window);
    sfClock_destroy(win->game_time);
    sfMusic_destroy(win->music);
    destroy_map_data(win->map_data);
}