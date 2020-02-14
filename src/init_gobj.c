/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void set_comp_null(component_t * comp)
{
    comp->image = NULL;
    comp->text = NULL;
    comp->clock = NULL;
    comp->sound = NULL;
}

component_t *add_comp(game_obj_t *obj, prop_t type)
{
    component_t *new_prop = malloc(sizeof(component_t));
    int i = 0;

    while (obj->comp[i] != NULL && i < obj->comp_nb)
        i++;
    if (new_prop == NULL)
        return (NULL);
    new_prop->type = type;
    set_comp_null(new_prop);
    obj->comp[i] = new_prop;
    return (new_prop);
}

void free_obj(game_obj_t *obj)
{
    if (obj == NULL)
        return ;
    free_all_comp(obj);
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
}

static const int (*create_obj_by_type[])(game_obj_t *) = {
    create_player,
    create_player2,
    create_background,
    create_middleground,
    create_ground,
    create_house,
    create_barrel,
    create_health_bar,
    create_stamina_bar,
    create_crate,
    create_hay_wagon,
    create_well,
    create_cursor,
    create_map_name_field,
    create_wood_top,
    create_wood_bot,
    create_wood_left,
    create_wood_right,
    create_spike,
    create_item_bar,
    create_b_play,
    create_b_inf_play,
    create_b_edit,
    create_score_bar,
    create_hscore_bar
};

game_obj_t *create_game_obj(elem_t type)
{
    game_obj_t *obj = malloc(sizeof(game_obj_t));

    if (obj == NULL)
        return (NULL);
    obj->next = NULL;
    obj->type = type;
    if (create_obj_by_type[type](obj) == 84)
        return (NULL);
    return (obj);
}