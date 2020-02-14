/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

void set_jump_mode(game_obj_t *player, int mode)
{
    if (mode == 1) {
        player->l_rect.width = player->comp
            [find_comp(player, JUMP_HITBOX)]->v2i.x;
        player->l_rect.height = player->comp
            [find_comp(player, JUMP_HITBOX)]->v2i.y;
        player->l_rect.top = player->comp
            [find_comp(player, NORMAL_HITBOX)]->v2i.y;
    } else {
        player->l_rect.width = player->comp
            [find_comp(player, NORMAL_HITBOX)]->v2i.x;
        player->l_rect.height = player->comp
            [find_comp(player, NORMAL_HITBOX)]->v2i.y;
        player->l_rect.top = 0;
    }
    player->comp[find_comp(player, JUMPING)]->i = mode;
    player->l_rect.left = 0;
    set_g_rect(player);
    reset_comp_clock(player, CLOCK);
    reset_comp_clock(player, JUMP_CLOCK);
}

void player_jump(game_obj_t *player, sfClock *clock)
{
    sfTime time;
    float second;

    if (clock == NULL)
        return ;
    time = sfClock_getElapsedTime(clock);
    second = sfTime_asSeconds(time);
    if (second < 1 && second > 0.4) {
        player->pos.y -= player->comp[find_comp(player, GRAVITY)]->f * 2;
        set_g_rect(player);
    } else if (second < 0.4 || second < 1.7) {
        player->comp[find_comp(player, BLOCKED)]->i = 1;
    } else
        set_jump_mode(player, 0);
}

void player2_jump(game_obj_t *player, sfClock *clock)
{
    sfTime time;
    float second;

    if (clock == NULL)
        return ;
    time = sfClock_getElapsedTime(clock);
    second = sfTime_asSeconds(time);
    if (second < 0.65 && second > 0.1) {
        player->pos.y -= player->comp[find_comp(player, GRAVITY)]->f * 2;
        set_g_rect(player);
    } else if (second < 0.1 || second < 0.75) {
        player->comp[find_comp(player, BLOCKED)]->i = 1;
    } else
        set_jump_mode(player, 0);
}

void is_jumping_p2(game_obj_t *player)
{
    sfClock *clock = player->comp[find_comp(player, JUMP_CLOCK)]->clock;

    if ((player->type == PLAYER2 &&
        player->comp[find_comp(player, JUMPING)]->i == 0 &&
        player->comp[find_comp(player, BLOCKED)]->i == 1)) {
        set_jump_mode(player, 1);
        reset_comp_clock(player, JUMP_CLOCK);
    }
    if (player->comp[find_comp(player, JUMPING)]->i &&
        player->type == PLAYER2)
        player2_jump(player, clock);
}

void is_jumping(game_obj_t *player)
{
    sfClock *clock = player->comp[find_comp(player, JUMP_CLOCK)]->clock;

    if (player->type == PLAYER2) {
        is_jumping_p2(player);
        return ;
    }
    if ((player->type == PLAYER &&
        sfKeyboard_isKeyPressed(sfKeyUp) &&
        player->comp[find_comp(player, STAMINA)]->f >= 20 &&
        player->comp[find_comp(player, JUMPING)]->i == 0)) {
        set_jump_mode(player, 1);
        player->comp[find_comp(player, STAMINA)]->f -= 20;
        reset_comp_clock(player, JUMP_CLOCK);
    }
    if (player->comp[find_comp(player, JUMPING)]->i &&
        player->type == PLAYER)
        player_jump(player, clock);
}