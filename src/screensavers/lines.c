/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** screensaver that draw random perpendicular lines
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "prototypes.h"

static void draw_line(ssv_data_t *data, int dir, unsigned int pos)
{
    int counter = 0;
    unsigned int limit = (dir) ? data->fb->height : data->fb->width;
    int part;

    for (unsigned int i = 0; i < limit; i++)
        if (get_pixel(data->fb, (dir) ? pos : i, (dir) ? i : pos)->r != 0)
            counter++;
    part = rand() % (counter + 1);
    counter = 0;
    for (unsigned int i = 0; i < limit; i++) {
        if (get_pixel(data->fb, (dir) ? pos : i, (dir) ? i : pos)->r != 0)
            counter++;
        if (counter == part)
            put_pixel(data->fb, (dir) ? pos : i, (dir) ? i : pos, sfWhite);
        if (counter > part)
            break;
    }
}

int lines(ssv_data_t *data)
{
    unsigned int pos;
    int dir;
    sfClock *clock = sfClock_create();
    sfInt64 interval = sfMilliseconds(500).microseconds;
    sfInt64 current;

    reset_framebuffer(data->fb, sfBlack);
    while (event_loop(data)) {
        current = sfClock_getElapsedTime(clock).microseconds;
        if (current > interval) {
            dir = rand() % 2;
            pos = rand() % ((dir) ? data->fb->width : data->fb->height);
            draw_line(data, dir, pos);
            sfClock_restart(clock);
        }
        display_framebuffer(data);
    }
    return (0);
}
