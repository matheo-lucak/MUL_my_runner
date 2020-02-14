/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int set_ground_param(game_obj_t *ground)
{
    int nb = get_randnb(1, 3);

    if (nb > 1) {
        if (set_sprite(ground, "./sprite/ground.png") == 84)
            return (84);
    } else {
        if (set_sprite(ground, "./sprite/ground_b.png") == 84)
            return (84);
    }
    return (0);
}

int create_ground(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 0, 1080 - 78);
    set_l_rect(obj, 32, 78);
    set_g_rect(obj);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    if (set_ground_param(obj) == 84)
        return (84);
    return (0);
}

int set_house_param(game_obj_t *house)
{
    int nb = get_randnb(1, 3);

    if (nb == 1) {
        set_pos(house, 500, 1080 - 78 - 732);
        set_l_rect(house, 672, 732);
        if (set_sprite(house, "./sprite/house_a.png") == 84)
            return (84);
    } else if (nb == 2) {
        set_pos(house, 500, 1080 - 78 - 976);
        set_l_rect(house, 840, 976);
        if (set_sprite(house, "./sprite/house_b.png") == 84)
            return (84);
    } else {
        set_pos(house, 500, 1080 - 78 - 732);
        set_l_rect(house, 884, 732);
        if (set_sprite(house, "./sprite/house_c.png") == 84)
            return (84);
    }
    return (0);
}

int create_house(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    if (set_house_param(obj) == 84)
        return (84);
    set_g_rect(obj);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, -2);
    return (0);
}