/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int set_stamina_bar_param(game_obj_t *bar)
{
    if (add_comp(bar, IMAGE) == NULL || add_comp(bar, DEFAULT_IMAGE) == NULL ||
        add_comp(bar, BAR_FIELD) == NULL)
        return (84);
    if (set_comp_image(bar, DEFAULT_IMAGE, "./sprite/stamina_bar.png") == 84)
        return (84);
    bar->comp[find_comp(bar, BAR_FIELD)]->irect.left = 30;
    bar->comp[find_comp(bar, BAR_FIELD)]->irect.top = 14;
    bar->comp[find_comp(bar, BAR_FIELD)]->irect.width = 208;
    bar->comp[find_comp(bar, BAR_FIELD)]->irect.height = 24;
    return (0);
}

int create_stamina_bar(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 3;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 0 + 10, 50 + 10);
    set_l_rect(obj, 268, 50);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/stamina_bar.png") == 84)
        return (84);
    if (set_stamina_bar_param(obj) == 84)
        return (84);
    return (0);
}

int set_health_bar_param(game_obj_t *bar)
{
    if (add_comp(bar, IMAGE) == NULL || add_comp(bar, DEFAULT_IMAGE) == NULL ||
        add_comp(bar, BAR_FIELD) == NULL)
        return (84);
    if (set_comp_image(bar, DEFAULT_IMAGE, "./sprite/health_bar.png") == 84)
        return (84);
    bar->comp[find_comp(bar, BAR_FIELD)]->irect.left = 54;
    bar->comp[find_comp(bar, BAR_FIELD)]->irect.top = 12;
    bar->comp[find_comp(bar, BAR_FIELD)]->irect.width = 200;
    bar->comp[find_comp(bar, BAR_FIELD)]->irect.height = 24;
    return (0);
}

int create_health_bar(game_obj_t *obj)
{
    int i = -1;

    obj->comp_nb = 3;
    obj->comp = malloc(sizeof(component_t) * (obj->comp_nb + 1));
    while (++i < obj->comp_nb + 1)
        obj->comp[i] = NULL;
    if (obj->comp == NULL)
        return  (84);
    set_pos(obj, 1920 - 266 - 10, 54 + 10);
    set_l_rect(obj, 266, 54);
    set_g_rect(obj);
    if (set_sprite(obj, "./sprite/health_bar.png") == 84)
        return (84);
    if (set_health_bar_param(obj) == 84)
        return (84);
    return (0);
}