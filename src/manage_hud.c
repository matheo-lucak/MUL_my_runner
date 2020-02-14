/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int check_color(const sfColor color, const sfColor source)
{
    if (color.r == source.r &&
        color.b == source.b &&
        color.g == source.g)
        return (1);
    return (0);
}

void color_stamina_bar(game_obj_t *player, game_obj_t *bar, int x, int y)
{
    float stamina = player->comp[find_comp(player, STAMINA)]->f;
    int width = bar->comp[find_comp(bar, BAR_FIELD)]->irect.width;
    sfColor color;

    color.r = 0;
    color.g = (255 / width) * x;
    color.b = 255;
    if ((stamina / 100) * width >= x)
        color.a = 255;
    else
        color.a = 0;
    sfImage_setPixel
        (bar->comp[find_comp(bar, IMAGE)]->image,
        x + bar->comp[find_comp(bar, BAR_FIELD)]->irect.left,
        y + bar->comp[find_comp(bar, BAR_FIELD)]->irect.top, color);
}

void color_health_bar(game_obj_t *player, game_obj_t *bar, int x, int y)
{
    float life = player->comp[find_comp(player, LIFE)]->i;
    int width = bar->comp[find_comp(bar, BAR_FIELD)]->irect.width;
    sfColor color;

    if (x <= width / 2) {
        color.r = 255;
        color.g = x * 255 / (width / 2);
    } else {
        color.r = -x * 255 / (width / 2);
        color.g = 255;
    }
    color.b = 0;
    if ((life / 100) * width > x)
        color.a = 255;
    else
        color.a = 0;
    sfImage_setPixel
        (bar->comp[find_comp(bar, IMAGE)]->image,
        x + bar->comp[find_comp(bar, BAR_FIELD)]->irect.left,
        y + bar->comp[find_comp(bar, BAR_FIELD)]->irect.top, color);
}

void color_bar(game_obj_t *player, game_obj_t *bar, int x, int y)
{
    if (bar->type == STAMINA_BAR)
        color_stamina_bar(player, bar, x, y);
    if (bar->type == HEALTH_BAR)
        color_health_bar(player, bar, x, y);
}

void fill_bar(game_obj_t *player, game_obj_t *bar)
{
    int x = 0;
    int y = 0;

    bar->comp[find_comp(bar, IMAGE)]->image = sfImage_copy
        (bar->comp[find_comp(bar, DEFAULT_IMAGE)]->image);
    while (y < bar->comp[find_comp(bar, BAR_FIELD)]->irect.height) {
        while (x < bar->comp[find_comp(bar, BAR_FIELD)]->irect.width) {
            color_bar(player, bar, x, y);
            x++;
        }
        x = 0;
        y++;
    }
    sfTexture_updateFromImage
        (bar->texture, bar->comp[find_comp(bar, IMAGE)]->image, 0, 0);
    sfImage_destroy(bar->comp[find_comp(bar, IMAGE)]->image);
    bar->comp[find_comp(bar, IMAGE)]->image = NULL;
}