/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int create_b_play(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 0;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 1920 / 2 - 1000 / 2, 100);
    set_l_rect(obj, 1000, 288);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/b_play.png") == 84)
        return (84);
    return (0);
}

int create_b_inf_play(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 0;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 1920 / 2 - 1000 / 2, 100 + 288);
    set_l_rect(obj, 1000, 288);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/b_inf_play.png") == 84)
        return (84);
    return (0);
}

int create_b_edit(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 1920 / 2 - 1000 / 2, 388 + 288);
    set_l_rect(obj, 1000, 288);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/b_edit.png") == 84)
        return (84);
    return (0);
}