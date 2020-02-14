/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int init_map_finite_game(win_t *win, obj_t *obj)
{
    float last_x_pos = 0;
    map_t *map_data = win->map_data;

    while (map_data != NULL) {
        last_x_pos = get_tail_x_pos(obj->prop);
        if (obj->prop == NULL)
            last_x_pos = 1000;
        if (create_map(map_data->map, obj, last_x_pos) == 84)
            return (84);
        map_data = map_data->next;
    }
    return (0);
}

int start_game(win_t *win, obj_t *obj, int init)
{
    if (init == 1 && init_obj_env(obj) == 84)
        return (84);
    if (init_obj_player(obj) == 84 || init_obj_inf_hud(obj) == 84)
        return (84);
    if (win->gm == PLAY && init_map_finite_game(win, obj) == 84)
        return (84);
    while (sfRenderWindow_isOpen(win->window) && win->gm != MENU) {
        sfRenderWindow_clear(win->window, sfBlack);
        if (inf_game_event(win, obj) == 84)
            sfRenderWindow_close(win->window);
        sfRenderWindow_display(win->window);
    }
    return (0);
}

int start_edit_game(win_t *win, obj_t *obj, int init)
{
    if (init == 1 && init_obj_env(obj) == 84)
        return (84);
    if (init_obj_edit(obj) == 84)
        return (84);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfBlack);
        if (edit_game_event(win, obj) == 84)
            sfRenderWindow_close(win->window);
        sfRenderWindow_display(win->window);
    }
    return (0);
}

int start_menu_game(win_t *win, obj_t *obj, int init)
{
    int (*select_gm[])(win_t *, obj_t *, int) = {start_game,
        start_game, start_edit_game, start_menu_game};

    if (init == 1 && (init_obj_env(obj) == 84 || init_obj_menu(obj) == 84))
        return (84);
    while (sfRenderWindow_isOpen(win->window) && win->gm == MENU) {
        sfRenderWindow_clear(win->window, sfBlack);
        if (menu_game_event(win, obj) == 84)
            sfRenderWindow_close(win->window);
        sfRenderWindow_display(win->window);
    }
    if (win->gm != MENU && select_gm[win->gm](win, obj, 0) == 84)
        return (84);
    return (0);
}