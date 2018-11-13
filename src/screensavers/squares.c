/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Screensaver that draws random squares of random coulour at random positions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "prototypes.h"

static void draw_random_square(framebuffer_t *fb)
{
    unsigned int size = rand() % 40 + 10;
    unsigned int x = rand() % (fb->width - size);
    unsigned int y = rand() % (fb->height - size);
    sfColor color;

    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;
    color.a = 255;
    for (unsigned int i = x; i < size + x; i++)
        for (unsigned int j = y; j < size + y; j++)
            put_pixel(fb, i, j, color);
}

int squares(ssv_data_t *data)
{
    sfClock *clock = sfClock_create();
    sfInt64 interval = sfSeconds(.7).microseconds;
    sfInt64 current;

    reset_framebuffer(data->fb, sfBlack);
    while (event_loop(data)) {
        current = sfClock_getElapsedTime(clock).microseconds;
        if (current > interval) {
            draw_random_square(data->fb);
            sfClock_restart(clock);
        }
        display_framebuffer(data);
    }
    return (0);
}
