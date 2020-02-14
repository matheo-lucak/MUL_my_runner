/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

void map_name_field_gesture(win_t *win, game_obj_t *obj)
{
    sfVector2f pos;

    pos.x = 510;
    pos.y = 600;
    disp_obj(win, obj);
    sfText_setString
        (obj->comp[find_comp(obj, TEXT)]->text, win->map_data->path);
    sfText_setPosition(obj->comp[find_comp(obj, TEXT)]->text, pos);
    sfRenderWindow_drawText
        (win->window, obj->comp[find_comp(obj, TEXT)]->text, NULL);
    sfRenderWindow_display(win->window);
}

void check_alph(char *name, int *i)
{
    char *alph_num = "abcdefghijklmnopqrstuvwxyz0123456789";
    int letter = 0;

    while (letter < 36) {
        if (sfKeyboard_isKeyPressed((sfKeyCode)letter) && *i < 30) {
            name[(*i)++] = alph_num[letter];
            while (sfKeyboard_isKeyPressed((sfKeyCode)letter));
        }
        letter++;
    }
    if (sfKeyboard_isKeyPressed(sfKeyBack) && *i > 0) {
        *i = *i - 1;
        name[*i] = '\0';
        while (sfKeyboard_isKeyPressed(sfKeyBack));
    }
}

char *get_file_name(win_t *win)
{
    game_obj_t *map_name_field = create_game_obj(MAP_NAME_FIELD);
    char *name = malloc(sizeof(char) * 30);
    int i = 0;

    if (name == NULL || map_name_field == NULL)
        return (NULL);
    my_memset(name, '\0', 20);
    while (sfKeyboard_isKeyPressed(sfKeyEnter));
    while (!sfKeyboard_isKeyPressed(sfKeyEnter)) {
        check_alph(name, &i);
        win->map_data->path = name;
        map_name_field_gesture(win, map_name_field);
    }
    name[i] = '\0';
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        free(name);
        return (NULL);
    }
    return (name);
}

void close_edit_mode(win_t *win, obj_t *obj)
{
    char **map = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        map = create_new_map(obj->prop, get_map_size(obj->prop));
        win->map_data->path = get_file_name(win);
        sfRenderWindow_close(win->window);
    }
    if (map != NULL)
        write_new_map(map, win->map_data->path);
}