/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int create_score_bar(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 1920 / 2 - 300 / 2 , 0);
    set_l_rect(obj, 300, 175);
    set_g_rect(obj);
    if (add_comp(obj, TEXT) == NULL)
        return (84);
    if (set_comp_text(obj, TEXT, "./font/black.ttf", 32) == 84)
        return (84);
    if (set_sprite(obj, "./sprite/score_bar.png") == 84)
        return (84);
    return (0);
}

int create_hscore_bar(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 0, 0);
    set_l_rect(obj, 300, 175);
    set_g_rect(obj);
    if (add_comp(obj, TEXT) == NULL)
        return (84);
    if (set_comp_text(obj, TEXT, "./font/black.ttf", 32) == 84)
        return (84);
    if (set_sprite(obj, "./sprite/hscore_bar.png") == 84)
        return (84);
    return (0);
}