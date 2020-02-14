/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int create_barrel(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 2000, 1080 - 64 - 150);
    set_l_rect(obj, 120, 150);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/barrel.png") == 84)
        return (84);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}

int create_crate(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 2000, 1080 - 64 - 100);
    set_l_rect(obj, 111, 100);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/crate.png") == 84)
        return (84);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}

int create_hay_wagon(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 2000, 1080 - 64 - 180);
    set_l_rect(obj, 223, 180);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/hay_wagon.png") == 84)
        return (84);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}

int create_well(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 2000, 1080 - 64 - 200);
    set_l_rect(obj, 200, 200);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/well.png") == 84)
        return (84);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}