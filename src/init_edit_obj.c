/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int create_cursor(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 3;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 500, 500);
    set_l_rect(obj, 45, 45);
    set_g_rect(obj);
    if (add_comp(obj, SPEED) == NULL || add_comp(obj, ORIGIN) == NULL ||
        add_comp(obj, IMAGE) == NULL)
        return (84);
    if (set_sprite(obj, "./sprite/cursor.png") == 84)
        return (84);
    set_comp_v2f(obj, ORIGIN, 45 / 2, 45 / 2);
    sfSprite_setOrigin(obj->sprite, obj->comp[find_comp(obj, ORIGIN)]->v2f);
    set_comp_float(obj, SPEED, 5);
    return (0);
}

int create_map_name_field(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, (1920 / 2) - (1000 / 2), (1080 / 2) - (410 / 2));
    set_l_rect(obj, 1000, 410);
    set_g_rect(obj);
    if (add_comp(obj, TEXT) == NULL)
        return (84);
    if (set_comp_text(obj, TEXT, "./font/black.ttf", 60) == 84)
        return (84);
    if (set_sprite(obj, "./sprite/map_name_field.png") == 84)
        return (84);
    return (0);
}

int create_item_bar(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 1;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 1920 - 1000 - (1920 - 1000) / 2 , - 200);
    set_l_rect(obj, 1000, 286);
    set_g_rect(obj);
    if (add_comp(obj, SPEED) == NULL)
        return (84);
    set_comp_float(obj, SPEED, 3);
    if (set_sprite(obj, "./sprite/item_bar.png") == 84)
        return (84);
    return (0);
}