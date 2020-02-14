/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

void mouve_cursor_hori(win_t *win, obj_t *obj, float coeff_speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) &&
        obj->cursor->pos.x < win->video_mode.width)
        obj->cursor->pos.x +=
        obj->cursor->comp[find_comp(obj->cursor, SPEED)]->f *
        win->game_speed * coeff_speed;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && obj->cursor->pos.x > 0)
        obj->cursor->pos.x -=
        obj->cursor->comp[find_comp(obj->cursor, SPEED)]->f *
        win->game_speed * coeff_speed;
}

void mouve_cursor_verti(win_t *win, obj_t *obj, float coeff_speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && obj->cursor->pos.y > 0)
        obj->cursor->pos.y -=
        obj->cursor->comp[find_comp(obj->cursor, SPEED)]->f *
        win->game_speed * coeff_speed;
    if (sfKeyboard_isKeyPressed(sfKeyDown) &&
        obj->cursor->pos.y < win->video_mode.height)
        obj->cursor->pos.y +=
        obj->cursor->comp[find_comp(obj->cursor, SPEED)]->f *
        win->game_speed * coeff_speed;
}

void move_cursor(win_t *win, obj_t *obj)
{
    float coeff_speed = 1;

    if (sfKeyboard_isKeyPressed(sfKeyLShift) ||
        sfKeyboard_isKeyPressed(sfKeyRShift))
        coeff_speed = 0.25;
    mouve_cursor_hori(win, obj, coeff_speed);
    mouve_cursor_verti(win, obj, coeff_speed);
    sfSprite_setPosition(obj->cursor->sprite, obj->cursor->pos);
    set_g_rect(obj->cursor);
}

int create_prop_from_ghost(obj_t *obj, elem_t type, sfVector2f coord)
{
    game_obj_t *prop = obj->prop;
    game_obj_t *tmp = obj->prop;

    if (type == NONE)
        return (0);
    if (obj->prop == NULL) {
        obj->prop = create_game_obj(type);
        if (obj->prop == NULL)
            return (84);
        set_pos(obj->prop, coord.x, coord.y);
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = create_game_obj(type);
        if (tmp->next == NULL)
            return (84);
        set_pos(tmp->next, coord.x, coord.y);
        obj->prop = prop;
    }
    return (0);
}