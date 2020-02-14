/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void move_obj(win_t *win, game_obj_t *obj, float way)
{
    while (obj != NULL) {
        obj->pos.x += obj->comp[find_comp(obj, SPEED)]->f *
            win->game_speed * way;
        sfSprite_setPosition(obj->sprite, obj->pos);
        set_g_rect(obj);
        obj = obj->next;
    }
}

int expand_obj(game_obj_t *obj, elem_t type, int shift_min, int shift_max)
{
    while (obj->next != NULL)
        obj = obj->next;
    if (obj->pos.x < 2000 && obj->next == NULL) {
        obj->next = create_game_obj(type);
        if (obj->next == NULL)
            return (84);
        obj->next->pos.x = obj->l_rect.width + obj->pos.x +
            get_randnb(shift_min, shift_max);
        sfSprite_setPosition(obj->next->sprite, obj->next->pos);
        if (obj->next->pos.x < 2000)
            expand_obj(obj, type, shift_min, shift_max);
    }
    return (0);
}

void clean_obj(game_obj_t **obj)
{
    game_obj_t *tmp = *obj;

    if (*obj == NULL)
        return ;
    if ((*obj)->pos.x + (*obj)->l_rect.width < 0) {
        *obj = (*obj)->next;
        free_obj(tmp);
    }
}

void disp_obj(win_t *win, game_obj_t *obj)
{
    while (obj != NULL) {
        sfSprite_setPosition(obj->sprite, obj->pos);
        sfSprite_setTextureRect(obj->sprite, obj->l_rect);
        sfRenderWindow_drawSprite(win->window, obj->sprite, NULL);
        obj = obj->next;
    }
}