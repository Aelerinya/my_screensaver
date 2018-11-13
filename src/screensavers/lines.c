/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** screensaver that draw random perpendicular lines
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "prototypes.h"

int lines(ssv_data_t *data)
{
    unsigned int pos;
    int dir;
    sfClock *clock = sfClock_create();
    sfInt64 interval = sfSeconds(1).microseconds;
    sfInt64 current;

    reset_framebuffer(data->fb, sfBlack);
    while (event_loop(data)) {
        current = sfClock_getElapsedTime(clock).microseconds;
        if (current > interval) {
            dir = rand() % 2;
            pos = rand() % ((dir) ? data->fb->width : data->fb->height);
            for (unsigned int i = 0; i < ((dir) ? data->fb->height : data->fb->width); i++)
                put_pixel(data->fb, (dir) ? pos : i, (dir) ? i : pos, sfWhite);
            sfClock_restart(clock);
        }
        display_framebuffer(data);
    }
    return (0);
}
