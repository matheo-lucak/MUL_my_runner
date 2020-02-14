/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

void reset_ghost(obj_t *obj)
{
    sfKeyCode code = sfKeyNum1;

    while (code != sfKeyEscape) {
        if ((sfKeyboard_isKeyPressed(code) ||
            sfKeyboard_isKeyPressed(sfKeyBack)) &&
            obj->ghost != NULL) {
            free_obj(obj->ghost);
            free(obj->ghost);
            obj->ghost = NULL;
        }
        code++;
    }
}

void set_ghost_pixel(sfImage *image, int x, int y)
{
    sfColor color;

    color = sfImage_getPixel(image, x, y);
    if (color.a != 0)
        color.a = 200;
    sfImage_setPixel(image, x, y, color);
}

sfImage *set_ghost_alpha(sfImage *image)
{
    sfVector2u size = sfImage_getSize(image);
    unsigned int x = 0;
    unsigned int y = 0;

    while (y < size.y) {
        while (x < size.x) {
            set_ghost_pixel(image, x, y);
            x++;
        }
        x = 0;
        y++;
    }
    return (image);
}

void set_ghost_image(game_obj_t *cursor, game_obj_t *ghost)
{
    sfImage *tmp = sfTexture_copyToImage(ghost->texture);

    cursor->comp[find_comp(cursor, IMAGE)]->image = set_ghost_alpha(tmp);
    if (cursor->comp[find_comp(cursor, IMAGE)]->image != NULL) {
    sfTexture_updateFromImage
        (ghost->texture, cursor->comp[find_comp(cursor, IMAGE)]->image, 0, 0);
    sfSprite_setTexture(ghost->sprite, ghost->texture, sfTrue);
    }
}

void select_ghost_obj(obj_t *obj)
{
    elem_t pattern[9] = {BARREL, CRATE, HAY_WAGON, WELL, WOOD_T, WOOD_B,
        WOOD_L, WOOD_R, SPIKE};
    sfKeyCode code = sfKeyNum1;

    if (obj->ghost != NULL)
        return ;
    while (code != sfKeyEscape) {
        if (sfKeyboard_isKeyPressed(code))
            obj->ghost = create_game_obj(pattern[code - sfKeyNum1]);
        code++;
    }
    if (obj->ghost != NULL)
        set_ghost_image(obj->cursor, obj->ghost);
}