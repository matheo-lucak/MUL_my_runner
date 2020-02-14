/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void is_picked(game_obj_t *player, game_obj_t *obj)
{
    int picked = 0;

    if (obj == NULL)
        return ;
    set_g_rect(player);
    while (obj != NULL) {
        set_g_rect(obj);
        if (sfFloatRect_intersects(&(player->g_rect), &(obj->g_rect), NULL) &&
            obj->type == SPIKE) {
            picked = 1;
            }
        obj = obj->next;
    }
    if (picked == 1) {
        player->comp[find_comp(player, LIFE)]->i -= 1;
        if (sfSound_getStatus
        (player->comp[find_comp(player, HIT_SOUND)]->sound) != sfPlaying)
            sfSound_play(player->comp[find_comp(player, HIT_SOUND)]->sound);
    }
}

void is_giletjauned(game_obj_t *player, game_obj_t *player2)
{
    if (player == NULL || player2 == NULL)
        return ;
    set_g_rect(player);
    if (sfFloatRect_intersects(&(player->g_rect), &(player2->g_rect), NULL)) {
        player->comp[find_comp(player, LIFE)]->i -= 1;
        if (sfSound_getStatus
            (player->comp[find_comp(player, HIT_SOUND2)]->sound) != sfPlaying)
            sfSound_play(player->comp[find_comp(player, HIT_SOUND2)]->sound);
    }
}