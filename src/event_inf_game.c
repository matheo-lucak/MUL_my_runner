/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

void move_env(win_t *win, obj_t *obj, int mode)
{
    move_obj(win, obj->background, mode);
    move_obj(win, obj->middleground, mode);
    move_obj(win, obj->ground, mode);
    move_obj(win, obj->house, mode);
    move_obj(win, obj->prop, mode);
}

void disp_env(win_t *win, obj_t *obj)
{
    expand_obj(obj->background, BACKGROUND, 0, 0);
    expand_obj(obj->middleground, MIDDLEGROUND, 0, 0);
    expand_obj(obj->ground, GROUND, 0, 0);
    expand_obj(obj->house, HOUSE, 0, 350);
    disp_obj(win, obj->background);
    disp_obj(win, obj->middleground);
    disp_obj(win, obj->ground);
    disp_obj(win, obj->house);
    disp_obj(win, obj->prop);
    clean_obj(&(obj->background));
    clean_obj(&(obj->middleground));
    clean_obj(&(obj->ground));
    clean_obj(&(obj->house));
    clean_obj(&(obj->prop));
}

void entity_gesture(obj_t *obj)
{
    anime_obj(obj->player2, PLAYER2);
    anime_obj(obj->player, PLAYER);
    obj->player->comp[find_comp(obj->player, FALLING)]->i = 1;
    obj->player2->comp[find_comp(obj->player2, FALLING)]->i = 1;
    obj->player->comp[find_comp(obj->player, BLOCKED)]->i = 0;
    obj->player2->comp[find_comp(obj->player2, BLOCKED)]->i = 0;
    obj->player->comp[find_comp(obj->player, RUNNING)]->i = 0;
    obj->player2->comp[find_comp(obj->player2, RUNNING)]->i = 0;
}

int hud_gesture(win_t *win, obj_t *obj)
{
    fill_bar(obj->player, obj->stamina_bar);
    fill_bar(obj->player, obj->health_bar);
    disp_obj(win, obj->health_bar);
    disp_obj(win, obj->stamina_bar);
    disp_obj(win, obj->score_bar);
    set_score(win, obj->score_bar);
    return (0);
}

int inf_game_event(win_t *win, obj_t *obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win->window);
    generate_inf_map(win, obj);
    set_game_var(win);
    move_env(win, obj, 1);
    disp_env(win, obj);
    entity_gesture(obj);
    hud_gesture(win, obj);
    entity_event(win, obj);
    if (sfKeyboard_isKeyPressed(sfKeyP))
        is_pause(win);
    is_end(win, obj);
    return (0);
}