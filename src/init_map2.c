/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "runner.h"

float get_tail_x_pos(game_obj_t *prop)
{
    if (prop == NULL)
        return (0);
    while (prop->next != NULL)
        prop = prop->next;
    return (prop->pos.x);
}

int get_map_nb(map_t *map_data)
{
    int i = 0;

    while (map_data != NULL) {
        map_data = map_data->next;
        i++;
    }
    return (i);
}

int generate_inf_map(win_t *win, obj_t *obj)
{
    map_t *map_data = win->map_data;
    float last_x_pos = get_tail_x_pos(obj->prop);
    int map_i = get_randnb(0, get_map_nb(win->map_data));
    int i = 0;

    if (obj->prop == NULL)
        last_x_pos = 1500;
    if (win->gm != PLAY_INF || last_x_pos > 2000)
        return (84);
    while (i + 1 < map_i) {
        map_data = map_data->next;
        i++;
    }
    create_map(map_data->map, obj, last_x_pos + 250);
    return (0);
}