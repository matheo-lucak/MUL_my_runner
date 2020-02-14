/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int add_player2_param(game_obj_t *obj)
{
    if (add_comp(obj, SPEED) == NULL || add_comp(obj, GRAVITY) == NULL ||
        add_comp(obj, CLOCK) == NULL || add_comp(obj, FALLING) == NULL ||
        add_comp(obj, JUMPING) == NULL || add_comp(obj, RUNNING) == NULL ||
        add_comp(obj, BLOCKED) == NULL || add_comp(obj, JUMP_CLOCK) == NULL ||
        add_comp(obj, JUMP_HITBOX) == NULL ||
        add_comp(obj, FALL_SPEED) == NULL ||
        add_comp(obj, NORMAL_HITBOX) == NULL)
        return (84);
    return (0);
}

int set_player2_param(game_obj_t *obj)
{
    set_comp_float(obj, SPEED, -5);
    set_comp_float(obj, FALL_SPEED, 10);
    set_comp_float(obj, GRAVITY, 3);
    set_comp_int(obj, FALLING, 1);
    set_comp_int(obj, JUMPING, 0);
    set_comp_int(obj, RUNNING, 0);
    set_comp_int(obj, BLOCKED, 0);
    set_comp_v2i(obj, NORMAL_HITBOX, 162, 258);
    set_comp_v2i(obj, JUMP_HITBOX, 200, 265);
    if (set_comp_clock(obj, CLOCK) == 84 ||
        set_comp_clock(obj, JUMP_CLOCK) == 84)
        return (84);
    return (0);
}

int create_player2(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 11;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 200, 1080 - 100 - 258);
    set_l_rect(obj, 162, 258);
    set_g_rect(obj);
    if (add_player2_param(obj) == 84 || set_player2_param(obj) == 84)
        return (84);
    if (set_sprite(obj, "./sprite/gilet_jaune_sheet.png") == 84)
        return (84);
    return (0);
}
