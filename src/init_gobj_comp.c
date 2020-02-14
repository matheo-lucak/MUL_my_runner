/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int set_comp_int(game_obj_t *obj, prop_t type, int nb)
{
    int i = find_comp(obj, type);

    obj->comp[i]->i = nb;
    obj->comp[i]->clock = NULL;
    obj->comp[i]->image = NULL;
    obj->comp[i]->text = NULL;
    obj->comp[i]->sound = NULL;
    return (0);
}

int set_comp_float(game_obj_t *obj, prop_t type, float nb)
{
    int i = find_comp(obj, type);

    obj->comp[i]->f = nb;
    obj->comp[i]->clock = NULL;
    obj->comp[i]->image = NULL;
    obj->comp[i]->text = NULL;
    obj->comp[i]->sound = NULL;
    return (0);
}

int set_comp_v2i(game_obj_t *obj, prop_t type, int x, int y)
{
    int i = find_comp(obj, type);

    obj->comp[i]->v2i.x = x;
    obj->comp[i]->v2i.y = y;
    obj->comp[i]->clock = NULL;
    obj->comp[i]->image = NULL;
    obj->comp[i]->text = NULL;
    obj->comp[i]->sound = NULL;
    return (0);
}

int set_comp_v2f(game_obj_t *obj, prop_t type, float x, float y)
{
    int i = find_comp(obj, type);

    obj->comp[i]->v2f.x = x;
    obj->comp[i]->v2f.y = y;
    obj->comp[i]->clock = NULL;
    obj->comp[i]->image = NULL;
    obj->comp[i]->text = NULL;
    obj->comp[i]->sound = NULL;
    return (0);
}
