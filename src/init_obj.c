/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int init_obj_player(obj_t *obj)
{
    obj->player = create_game_obj(PLAYER);
    obj->player2 = create_game_obj(PLAYER2);
    if (obj->player == NULL || obj->player2 == NULL)
        return (84);
    return (0);
}

int init_obj_env(obj_t *obj)
{
    obj->background = create_game_obj(BACKGROUND);
    obj->middleground = create_game_obj(MIDDLEGROUND);
    obj->ground = create_game_obj(GROUND);
    obj->house = create_game_obj(HOUSE);
    if (obj->background == NULL || obj->middleground == NULL ||
        obj->ground == NULL || obj->house == NULL)
        return (84);
    return (0);
}

int init_obj_inf_hud(obj_t *obj)
{
    obj->health_bar = create_game_obj(HEALTH_BAR);
    obj->stamina_bar = create_game_obj(STAMINA_BAR);
    obj->score_bar = create_game_obj(SCORE_BAR);
    if (obj->health_bar == NULL || obj->stamina_bar == NULL ||
        obj->score_bar == NULL)
        return (84);
    return (0);
}

int init_obj_edit(obj_t *obj)
{
    obj->cursor = create_game_obj(CURSOR);
    obj->item_bar = create_game_obj(ITEM_BAR);
    if (obj->cursor == NULL || obj->item_bar == NULL)
        return (84);
    return (0);
}

int init_obj_menu(obj_t *obj)
{
    obj->cursor = create_game_obj(CURSOR);
    obj->b_play = create_game_obj(B_PLAY);
    obj->b_inf_play = create_game_obj(B_INF_PLAY);
    obj->b_edit = create_game_obj(B_EDIT);
    obj->score_bar = create_game_obj(HSCORE_BAR);
    if (obj->cursor == NULL || obj->b_play == NULL ||
        obj->b_inf_play == NULL || obj->b_edit == NULL ||
        obj->score_bar == NULL)
        return (84);
    return (0);
}