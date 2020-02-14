/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void set_l_rect(game_obj_t *obj, int width, int height)
{
    obj->l_rect.left = 0;
    obj->l_rect.top = 0;
    obj->l_rect.width = width;
    obj->l_rect.height = height;
}

void set_pos(game_obj_t *obj, float x, float y)
{
    obj->pos.x = x;
    obj->pos.y = y;
}

void set_g_rect(game_obj_t *obj)
{
    obj->g_rect.left = obj->pos.x;
    obj->g_rect.top = obj->pos.y;
    obj->g_rect.width = obj->l_rect.width;
    obj->g_rect.height = obj->l_rect.height;
}

int set_sprite(game_obj_t *obj, char const *path)
{
    obj->texture = sfTexture_createFromFile(path, NULL);
    obj->sprite = sfSprite_create();
    if (obj->texture == NULL || obj->sprite == NULL)
        return (84);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->l_rect);
    return (0);
}