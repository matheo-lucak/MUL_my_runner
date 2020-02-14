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

sfVector2i get_map_size(game_obj_t *prop)
{
    sfVector2i pos;

    pos.x = 0;
    pos.y = 0;

    while (prop != NULL) {
        if ((int)prop->pos.x > pos.x)
            pos.x = (int)prop->pos.x;
        if ((int)prop->pos.y > pos.y)
            pos.y = (int)prop->pos.y;
        prop = prop->next;
    }
    return (pos);
}

char check_char_from_type(elem_t type)
{
    char *char_pattern = "BCHW1234P";
    elem_t pattern[9] = {BARREL, CRATE, HAY_WAGON, WELL, WOOD_T, WOOD_B,
        WOOD_L, WOOD_R, SPIKE};
    int i = 0;

    while (char_pattern[i] != '\0') {
        if (pattern[i] == type) {
            return (char_pattern[i]);
        }
        i++;
    }
    return (' ');
}

char **set_new_map(char **map, game_obj_t *prop)
{
    sfVector2i pos;

    while (prop != NULL) {
        pos.x = (int)(prop->pos.x / SCALE);
        pos.y = (int)(prop->pos.y / SCALE);
        map[pos.y][pos.x] = check_char_from_type(prop->type);
        prop = prop->next;
    }
    return (map);
}

char **create_new_map(game_obj_t *prop, sfVector2i size)
{
    int line = 1080 / SCALE;
    int collumn = size.x / SCALE;
    char **map = malloc(sizeof(char *) * (line + 2));
    int y = 0;

    if (map == NULL)
        return (NULL);
    while (y < line) {
        map[y] = malloc(sizeof(char) * (collumn + 2));
        if (map[y] == NULL)
            return (NULL);
        my_memset(map[y], '\0', collumn + 2);
        my_memset(map[y], ' ', collumn + 1);
        y++;
    }
    map[y] = NULL;
    map = set_new_map(map, prop);
    return (map);
}

int write_new_map(char **map, char *path)
{
    FILE *fptr = NULL;
    int i = 0;
    char bck_n = '\n';

    if (path != NULL)
        fptr = fopen(path, "w");
    if (fptr == NULL || path == NULL || map == NULL)
        return (84);
    while (i < 1080 / SCALE) {
        fwrite(map[i], my_strlen(map[i]), sizeof(char), fptr);
        fwrite(&bck_n, 1, 1, fptr);
        i++;
    }
    fclose(fptr);
    return (0);
}