/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <fcntl.h>
#include <stdio.h>
#include "my.h"
#include "runner.h"

void set_score(win_t *win, game_obj_t *score_bar)
{
    sfText *text = score_bar->comp[find_comp(score_bar, TEXT)]->text;
    char *score_str = my_int_to_str(win->score);
    sfVector2f pos = score_bar->pos;

    if (score_str == NULL || text == NULL)
        return ;
    sfText_setString(text, score_str);
    pos.x += 125;
    pos.y += 115;
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(win->window, text, NULL);
    free(score_str);
}

int read_score(void)
{
    int fd = open("hscore", O_RDONLY);
    char *score_str = NULL;

    if (fd == -1)
        return (0);
    score_str = get_next_line(fd);
    close(fd);
    return ((int) my_getnbr(score_str));
}

void disp_hscore(win_t *win, game_obj_t *score_bar)
{
    static char *score_str =  NULL;
    sfText *text = score_bar->comp[find_comp(score_bar, TEXT)]->text;
    sfVector2f pos = score_bar->pos;

    if (score_str == NULL)
        score_str = my_int_to_str(read_score());
    if (score_str == NULL || text == NULL)
        return ;
    sfText_setString(text, score_str);
    pos.x += 125;
    pos.y += 115;
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(win->window, text, NULL);
}

void save_score(win_t *win)
{
    FILE *fptr = NULL;
    char *score_str = my_int_to_str(win->score);

    if (read_score() < win->score) {
        fptr = fopen("hscore", "w");
        if (fptr == NULL || score_str == NULL)
            return ;
        fwrite(score_str, my_strlen(score_str), sizeof(char), fptr);
    }
}