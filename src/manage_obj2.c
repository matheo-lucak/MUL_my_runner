/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void set_frame(game_obj_t *obj, int max_frame, int lapse)
{
    sfClock *clock = obj->comp[find_comp(obj, CLOCK)]->clock;
    sfTime time = sfClock_getElapsedTime(clock);
    sfUint32 msecond = sfTime_asMilliseconds(time);

    int frame = obj->l_rect.left / obj->l_rect.width;

    if (lapse * (frame + 1) < (int)msecond &&
        lapse * (frame + 2) > (int)msecond &&
        obj->l_rect.left == frame * obj->l_rect.width)
        obj->l_rect.left += obj->l_rect.width;
    if (lapse * max_frame < (int)msecond) {
        sfClock_restart(obj->comp[find_comp(obj, CLOCK)]->clock);
        obj->l_rect.left = 0;
    }
}

void anime_obj(game_obj_t *obj, elem_t type)
{
    if (type == PLAYER && obj->comp[find_comp(obj, JUMPING)]->i == 1)
        set_frame(obj, 19, 100);
    else if (type == PLAYER && obj->comp[find_comp(obj, JUMPING)]->i == 0)
        set_frame(obj, 6, 200 - 50 *  obj->comp[find_comp(obj, RUNNING)]->i);
    if (type == PLAYER2 && obj->comp[find_comp(obj, JUMPING)]->i == 1)
        set_frame(obj, 15, 50);
    else if (type == PLAYER2 && obj->comp[find_comp(obj, JUMPING)]->i == 0)
        set_frame(obj, 6, 200);
}

void manage_player_pos(game_obj_t *player)
{
    if (player->type == PLAYER2 && player->pos.x < 250) {
        player->pos.x += -0.0008 * player->pos.x + 2;
    }
    if (player->type == PLAYER &&
        player->pos.x < 1920 && player->pos.x > 1250) {
        player->pos.x -= 0.003 * player->pos.x - 4;
    }
}