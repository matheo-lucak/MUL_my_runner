/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

int init_window_param(win_t *win, game_mode_t gm)
{
    win->game_speed = 1;
    win->game_time = sfClock_create();
    win->gm = gm;
    win->score = 0;
    win->map_data = malloc(sizeof(map_t));
    win->music = sfMusic_createFromFile("./music/game_music.ogg");
    if (win->map_data == NULL || win->game_time == NULL || win->music == NULL)
        return (84);
    win->map_data->map = NULL;
    win->map_data->path = NULL;
    sfMusic_setVolume(win->music, 1);
    sfMusic_setLoop(win->music, sfTrue);
    sfMusic_play(win->music);
    return (0);
}

int init_window(win_t *win , int width, int height, game_mode_t gm)
{
    if (win == NULL)
        return (84);
    win->video_mode.width = width;
    win->video_mode.height = height;
    win->video_mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(win->video_mode,
        "Macron VS Gilets jaunes", sfClose | sfDefaultStyle | sfFullscreen,
        NULL);
    if (win->window == NULL  || init_window_param(win, gm) == 84)
        return (84);
    sfRenderWindow_setFramerateLimit(win->window, 60);
    return (0);
}

void set_game_speed(win_t *win)
{
    sfTime time = sfClock_getElapsedTime(win->game_time);
    float seconds = sfTime_asSeconds(time);

    win->game_speed = 2.5 - 2.5 * exp(-0.01 * seconds) + 1;
}

void set_game_score(win_t *win)
{
    win->score += 1;
}

void set_game_var(win_t *win)
{
    set_game_speed(win);
    set_game_score(win);
}