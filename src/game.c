/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void free_all_gobj(obj_t *obj)
{
    free_obj(obj->player);
    free_obj(obj->player2);
    free_obj(obj->background);
    free_obj(obj->middleground);
    free_obj(obj->ground);
    free_obj(obj->house);
    free_obj(obj->prop);
    free_obj(obj->health_bar);
    free_obj(obj->stamina_bar);
    free_obj(obj->item_bar);
    free_obj(obj->cursor);
    free_obj(obj->ghost);
    free_obj(obj->b_play);
    free_obj(obj->b_inf_play);
    free_obj(obj->b_edit);
    free_obj(obj->score_bar);
}

int set_null_obj(obj_t *obj)
{
    if (obj == NULL)
        return (84);
    obj->player = NULL;
    obj->player2 = NULL;
    obj->background = NULL;
    obj->middleground = NULL;
    obj->ground = NULL;
    obj->house = NULL;
    obj->prop = NULL;
    obj->health_bar = NULL;
    obj->stamina_bar = NULL;
    obj->item_bar = NULL;
    obj->cursor = NULL;
    obj->ghost = NULL;
    obj->b_play = NULL;
    obj->b_inf_play = NULL;
    obj->b_edit = NULL;
    obj->score_bar = NULL;
    return (0);
}

int put_map_data_in_list(map_t *map_data, char *path)
{
    map_t *elem = malloc(sizeof(map_t));

    if (elem == NULL)
        return (84);
    elem->path = path;
    elem->map = read_map(path);
    elem->next = NULL;
    if (elem->map == NULL)
        return (84);
    while (map_data->next != NULL) {
        map_data = map_data->next;
    }
    map_data->next = elem;
    return (0);
}

int init_map_data(win_t *win, char **path)
{
    int i = 1;

    if (win->map_data == NULL || path == NULL)
        return (84);
    win->map_data->path = path[0];
    win->map_data->map = read_map(path[0]);
    win->map_data->next = NULL;
    if (win->map_data->map == NULL)
        return (84);
    while (path[i] != NULL) {
        put_map_data_in_list(win->map_data, path[i]);
        i++;
    }
    return (0);
}

int launch_game(game_mode_t gm, char **path)
{
    win_t *win = malloc(sizeof(win_t));
    obj_t *obj = malloc(sizeof(obj_t));
    int (*select_gm[])(win_t *, obj_t *, int) = {start_game,
        start_game, start_edit_game, start_menu_game};

    if (init_window(win, 1920, 1080, gm) == 84 || set_null_obj(obj) == 84)
        return (84);
    if ((gm == PLAY || gm == PLAY_INF || gm == MENU) &&
        init_map_data(win, path) == 84)
        return (84);
    if (select_gm[gm](win, obj, 1) == 84)
        return (84);
    free_all_gobj(obj);
    free_win(win);
    return (0);
}