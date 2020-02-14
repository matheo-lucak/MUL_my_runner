/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

void is_pause(win_t *win)
{
    sfTexture *texture = sfTexture_createFromFile
        ("./sprite/pause_screen.png", NULL);
    sfSprite *sprite = sfSprite_create();

    if (texture == NULL || sprite == NULL)
        return ;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(win->window, sprite, NULL);
    sfRenderWindow_display(win->window);
    while (!sfKeyboard_isKeyPressed(sfKeySpace));
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void entity_apply_event(win_t *win, obj_t *obj)
{
    player_block(win, obj->player2, obj->prop);
    player_block(win, obj->player, obj->prop);
    player_fall(obj->player2);
    player_fall(obj->player);
    manage_player_pos(obj->player2);
    manage_player_pos(obj->player);
    disp_obj(win, obj->player2);
    disp_obj(win, obj->player);
}

void entity_event(win_t *win, obj_t *obj)
{
    is_blocked(obj->player, obj->prop);
    is_falling(obj->player, obj->ground);
    is_falling(obj->player, obj->prop);
    is_running(obj->player);
    is_jumping(obj->player);
    is_blocked(obj->player2, obj->prop);
    is_falling(obj->player2, obj->prop);
    is_jumping(obj->player2);
    is_falling(obj->player2, obj->ground);
    is_picked(obj->player, obj->prop);
    is_giletjauned(obj->player, obj->player2);
    entity_apply_event(win, obj);
}