/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int create_wood_top(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 2000, 1080 - 64 - 40);
    set_l_rect(obj, 46, 40);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/wood_top.png") == 84)
        return (84);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}

int create_wood_bot(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 2000, 1080 - 64 - 50);
    set_l_rect(obj, 100, 50);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/wood_bot.png") == 84)
        return (84);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}

int create_wood_left(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 2000, 1080 - 64 - 100);
    set_l_rect(obj, 100, 100);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/wood_left.png") == 84)
        return (84);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}

int create_wood_right(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 2000, 1080 - 64 - 100);
    set_l_rect(obj, 100, 100);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/wood_right.png") == 84)
        return (84);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}

int create_spike(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 2000, 1080 - 64 - 69);
    set_l_rect(obj, 100, 69);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/spike.png") == 84)
        return (84);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}