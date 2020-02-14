/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

void apply_ghost(win_t *win, obj_t *obj)
{
    sfVector2f pos = obj->cursor->pos;

    if (sfKeyboard_isKeyPressed(sfKeySpace) && obj->ghost != NULL) {
        create_prop_from_ghost(obj, obj->ghost->type, pos);
        free_obj(obj->ghost);
        obj->ghost = NULL;
    }
    if (obj->ghost != NULL) {
        sfSprite_setPosition(obj->ghost->sprite, obj->cursor->pos);
        sfRenderWindow_drawSprite(win->window, obj->ghost->sprite, NULL);
    }
}

void show_item_bar(win_t *win, game_obj_t *item_bar, game_obj_t *cursor)
{
    set_g_rect(item_bar);
    set_g_rect(cursor);
    if (sfFloatRect_intersects(&(item_bar->g_rect), &(cursor->g_rect), NULL)
    && item_bar->pos.y < 0) {
        item_bar->pos.y += item_bar->comp[find_comp(item_bar, SPEED)]->f;
    } else if (item_bar->pos.y > -200 &&
        !sfFloatRect_intersects
        (&(item_bar->g_rect), &(cursor->g_rect), NULL)) {
        item_bar->pos.y -= item_bar->comp[find_comp(item_bar, SPEED)]->f;
    }
    disp_obj(win, item_bar);
    disp_obj(win, cursor);
}

int edit_game_event(win_t *win, obj_t *obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win->window);
    disp_env(win, obj);
    show_item_bar(win, obj->item_bar, obj->cursor);
    move_cursor(win, obj);
    reset_ghost(obj);
    select_ghost_obj(obj);
    apply_ghost(win, obj);
    disp_obj(win, obj->prop);
    close_edit_mode(win, obj);
    return (0);
}