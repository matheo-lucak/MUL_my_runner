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

int get_map_lenght(char **map)
{
    int x = 0;

    while (map[0][x] != '\0')
        x++;
    return (x);
}

char **read_map(char *path)
{
    int fd = open(path, O_RDONLY);
    int  lines = 1080 / SCALE;
    int i = 0;
    char **map = malloc(sizeof(char *) * (lines + 1));

    if (map == NULL || fd == -1)
        return (NULL);
    while (i < lines) {
        map[i] = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    return (map);
}

elem_t check_type(char obj_type)
{
    char *char_pattern = "BCHW1234P";
    elem_t pattern[9] = {BARREL, CRATE, HAY_WAGON, WELL, WOOD_T, WOOD_B,
        WOOD_L, WOOD_R, SPIKE};
    int i = 0;

    while (char_pattern[i] != '\0') {
        if (char_pattern[i] == obj_type) {
            return (pattern[i]);
        }
        i++;
    }
    return (NONE);
}

int create_prop(obj_t *obj, elem_t type, sfVector2f coord, float x_shift)
{
    game_obj_t *prop = obj->prop;
    game_obj_t *tmp = obj->prop;

    if (type == NONE)
        return (0);
    if (obj->prop == NULL) {
        obj->prop = create_game_obj(type);
        if (obj->prop == NULL)
            return (84);
        set_pos(obj->prop, coord.x * SCALE + x_shift, coord.y * SCALE);
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = create_game_obj(type);
        if (tmp->next == NULL)
            return (84);
        set_pos(tmp->next, coord.x * SCALE + x_shift, coord.y * SCALE);
        obj->prop = prop;
    }
    return (0);
}

int create_map(char **map, obj_t *obj, float x_shift)
{
    sfVector2f coord;
    int error = 0;
    elem_t type;

    coord.x = 0;
    coord.y = 0;
    if (map == NULL)
        return (84);
    while (map[(int)coord.y][(int)coord.x] != '\0' && error == 0) {
        while (map[(int)coord.y] != NULL && error == 0) {
            type = check_type(map[(int)coord.y][(int)coord.x]);
            error = create_prop(obj, type, coord, x_shift);
            coord.y++;
        }
        coord.y = 0;
        coord.x++;
    }
    if (obj->prop == NULL || error == 84)
        return (84);
    return (0);
}