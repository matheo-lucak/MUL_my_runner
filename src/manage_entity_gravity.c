/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void player_fall(game_obj_t *player)
{
    if (player->comp[find_comp(player, FALLING)]->i) {
        set_pos(player, player->pos.x, player->pos.y +
            player->comp[find_comp(player, FALL_SPEED)]->f);
        set_g_rect(player);
    }
}

void is_falling(game_obj_t *player, game_obj_t *obj)
{
    sfFloatRect obj_box;

    if (obj == NULL)
        return ;
    set_g_rect(player);
    while (obj != NULL) {
        set_g_rect(obj);
        obj_box = obj->g_rect;
        obj_box.height = 10;
        obj_box.left += 10;
        if (sfFloatRect_intersects(&(player->g_rect), &obj_box, NULL))
            player->comp[find_comp(player, FALLING)]->i = 0;
        obj = obj->next;
    }
}