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
    int pos;
    sfClock *clock = sfClock_create();
    sfInt64 interval = sfMilliseconds(400).microseconds;
    sfInt64 current;

    reset_framebuffer(data->fb, sfBlack);
    while (event_loop(data)) {
        current = sfClock_getElapsedTime(clock).microseconds;
        if (current > interval) {
            pos = rand() % data->fb->width;
            for (unsigned int i = 0; i < data->fb->height; i++)
                put_pixel(data->fb, pos, i, sfWhite);
            sfClock_restart(clock);
        }
        display_framebuffer(data);
    }
    return (0);
}
