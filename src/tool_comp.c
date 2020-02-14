/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int find_comp(game_obj_t *obj, prop_t type)
{
    int i = 0;

    while (obj->comp[i]->type != type && i < obj->comp_nb)
        i++;
    if (obj->comp[i]->type != type)
        return (0);
    return (i);
}

void free_comp(component_t *comp)
{
    if (comp->clock != NULL)
        sfClock_destroy(comp->clock);
    if (comp->image != NULL)
        sfImage_destroy(comp->image);
    if (comp->text != NULL)
        sfText_destroy(comp->text);
    if (comp->sound != NULL)
        sfSound_destroy(comp->sound);
}

void free_all_comp(game_obj_t *obj)
{
    int i = 0;

    while (obj->comp[i]) {
        free_comp(obj->comp[i]);
        free(obj->comp[i]);
        i++;
    }
    free(obj->comp);
}