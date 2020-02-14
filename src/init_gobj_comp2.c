/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include "my.h"
#include "runner.h"

int set_comp_clock(game_obj_t *obj, prop_t type)
{
    int i = find_comp(obj, type);

    obj->comp[i]->clock = sfClock_create();
    obj->comp[i]->image = NULL;
    obj->comp[i]->text = NULL;
    obj->comp[i]->sound = NULL;
    if (obj->comp[i]->clock == NULL)
        return (84);
    return (0);
}

int reset_comp_clock(game_obj_t *obj, prop_t type)
{
    int i = find_comp(obj, type);

    sfClock_restart(obj->comp[i]->clock);
    obj->comp[i]->image = NULL;
    obj->comp[i]->text = NULL;
    obj->comp[i]->sound = NULL;
    return (0);
}

int set_comp_image(game_obj_t *obj, prop_t type, char *path)
{
    int i = find_comp(obj, type);

    obj->comp[i]->clock = NULL;
    obj->comp[i]->text = NULL;
    obj->comp[i]->sound = NULL;
    obj->comp[i]->image = sfImage_createFromFile(path);
    if (obj->comp[i]->image == NULL)
        return (84);
    return (0);
}

int set_comp_text(game_obj_t *obj, prop_t type, char *path, int size)
{
    int i = find_comp(obj, type);
    sfFont *font = sfFont_createFromFile(path);

    obj->comp[i]->clock = NULL;
    obj->comp[i]->image = NULL;
    obj->comp[i]->sound = NULL;
    obj->comp[i]->text = sfText_create();
    if (font == NULL || obj->comp[i]->text == NULL)
        return (84);
    sfText_setFont(obj->comp[i]->text, font);
    sfText_setCharacterSize(obj->comp[i]->text, size);
    return (0);
}

int set_comp_sound(game_obj_t *obj, prop_t type, char *path, float volume)
{
    int i = find_comp(obj, type);
    sfSoundBuffer *sound_b = sfSoundBuffer_createFromFile(path);

    obj->comp[i]->clock = NULL;
    obj->comp[i]->image = NULL;
    obj->comp[i]->text = NULL;
    obj->comp[i]->sound = sfSound_create();
    if (sound_b == NULL || obj->comp[i]->sound == NULL)
        return (84);
    sfSound_setBuffer(obj->comp[i]->sound, sound_b);
    sfSound_setVolume(obj->comp[i]->sound, volume);
    return (0);
}