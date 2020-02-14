/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int create_background(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 0, 0);
    set_l_rect(obj, 1440, 1080);
    set_g_rect(obj);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -0.3);
    if (set_sprite(obj, "./sprite/background.png") == 84)
        return (84);
    return (0);
}

int create_middleground(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 0, 0);
    set_l_rect(obj, 1920, 1080);
    set_g_rect(obj);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -0.5);
    if (set_sprite(obj, "./sprite/middleground.png") == 84)
        return (84);
    return (0);
}