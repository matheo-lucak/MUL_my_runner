/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

void disp_button(win_t *win, obj_t *obj)
{
    disp_obj(win, obj->b_edit);
    disp_obj(win, obj->b_play);
    disp_obj(win, obj->b_inf_play);
}

void button_gesture(win_t *win, obj_t *obj)
{
    sfFloatRect b1_box;
    sfFloatRect b2_box;
    sfFloatRect b3_box;

    set_g_rect(obj->b_play);
    set_g_rect(obj->b_inf_play);
    set_g_rect(obj->b_edit);
    set_g_rect(obj->cursor);
    b1_box = obj->b_play->g_rect;
    b2_box = obj->b_inf_play->g_rect;
    b3_box = obj->b_edit->g_rect;
    if (!sfKeyboard_isKeyPressed(sfKeySpace))
        return ;
    if (sfFloatRect_intersects(&(obj->cursor->g_rect), &(b1_box), NULL))
        win->gm = PLAY;
    if (sfFloatRect_intersects(&(obj->cursor->g_rect), &(b2_box), NULL))
        win->gm = PLAY_INF;
    if (sfFloatRect_intersects(&(obj->cursor->g_rect), &(b3_box), NULL))
        win->gm = EDIT;
}

int menu_game_event(win_t *win, obj_t *obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win->window);
    disp_env(win, obj);
    move_env(win, obj, 1);
    disp_button(win, obj);
    disp_obj(win, obj->cursor);
    move_cursor(win, obj);
    disp_obj(win, obj->prop);
    disp_obj(win, obj->score_bar);
    disp_hscore(win, obj->score_bar);
    button_gesture(win, obj);
    return (0);
}