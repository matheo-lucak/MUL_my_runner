/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

void loose_screen(win_t *win)
{
    sfTexture *texture = sfTexture_createFromFile("./sprite/end_1.png", NULL);
    sfSprite *sprite = sfSprite_create();

    if (texture == NULL || sprite == NULL)
        return ;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(win->window, sprite, NULL);
    sfRenderWindow_display(win->window);
    while (!sfKeyboard_isKeyPressed(sfKeySpace));
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    win->gm = MENU;
    save_score(win);
}

void victory_screen(win_t *win)
{
    sfTexture *texture = sfTexture_createFromFile("./sprite/end_2.png", NULL);
    sfSprite *sprite = sfSprite_create();

    if (texture == NULL || sprite == NULL)
        return ;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(win->window, sprite, NULL);
    sfRenderWindow_display(win->window);
    while (!sfKeyboard_isKeyPressed(sfKeySpace));
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    win->gm = MENU;
    save_score(win);
}

int is_end(win_t *win, obj_t *obj)
{
    if (obj->player->comp[find_comp(obj->player, LIFE)]->i <= 0)
        loose_screen(win);
    if (obj->prop == NULL)
        victory_screen(win);
    return (0);
}