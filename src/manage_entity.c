/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void move_entity(game_obj_t *obj)
{
    while (obj != NULL) {
        obj->pos.x += obj->comp[find_comp(obj, SPEED)]->f;
        sfSprite_setPosition(obj->sprite, obj->pos);
        set_g_rect(obj);
        obj = obj->next;
    }
}

void is_blocked(game_obj_t *player, game_obj_t *prop)
{
    sfFloatRect box;

    while (prop != NULL) {
        set_g_rect(prop);
        box = prop->g_rect;
        box.top += 20;
        box.height -= 20;
        if (sfFloatRect_intersects(&(player->g_rect), &box, NULL)) {
            player->comp[find_comp(player, BLOCKED)]->i = 1;
            return ;
        }
        prop = prop->next;
    }
}

void player_block(win_t *win, game_obj_t *player, game_obj_t *prop)
{
    if (prop == NULL)
        return ;
    if (player->comp[find_comp(player, BLOCKED)]->i) {
        player->pos.x += win->game_speed *
            prop->comp[find_comp(prop, SPEED)]->f;
    }
}

void is_running(game_obj_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) &&
        player->comp[find_comp(player, BLOCKED)]->i != 1 &&
        player->comp[find_comp(player, STAMINA)]->f > 0) {
        player->comp[find_comp(player, RUNNING)]->i = 1;
        player->comp[find_comp(player, STAMINA)]->f -= 0.5;
        move_entity(player);
    } else if (player->comp[find_comp(player, STAMINA)]->f < 100)
        player->comp[find_comp(player, STAMINA)]->f += 0.5;
}