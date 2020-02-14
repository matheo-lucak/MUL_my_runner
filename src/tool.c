/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** csflm rtfm
*/

#include <time.h>
#include "my.h"
#include "runner.h"

int get_randnb(int min, int max)
{
    static int i = 0;
    int nb = 0;

    if (!i) {
        srand((size_t)&i);
        i++;
    }
    if (max == min)
        return (0);
    nb = rand() % (max - min) + min;
    return (nb);
}