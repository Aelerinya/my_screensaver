/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Bouncing ball changing color
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include "prototypes.h"

static void draw_circle(framebuffer_t *fb, sfVector2u pos, int size,
sfColor color)
{
    for (int i = -size; i < size; i++)
        for (int j = -size; j < size; j++)
            if (sqrt(i * i + j * j) < size)
                put_pixel(fb, pos.x + i, pos.y + j, color);
}

static void move_ball(ssv_data_t *data, int size, sfVector2u *pos,
sfVector2u *v)
{
    unsigned int sizeu = (unsigned int)size;

    pos->x += v->x;
    pos->y += v->y;
    if (pos->x < sizeu || pos->x + sizeu > data->fb->width)
        v->x *= -1;
    if (pos->y < sizeu || pos->y + sizeu > data->fb->height)
        v->y *= -1;
}

int bouncing(ssv_data_t *data)
{
    int size = rand() % 40 + 10;
    sfVector2u pos;
    sfVector2u v;
    sfColor color = random_hue();

    pos.x = rand() % (data->fb->width - 4 * size) + 2 * size;
    pos.y = rand() % (data->fb->height - 4 * size) + 2 * size;
    v.x = (rand() % 12 - 6) * 2 + 10;
    v.y = (rand() % 12 - 6) * 2 + 10;
    reset_framebuffer(data->fb, sfBlack);
    while(event_loop(data)) {
        draw_circle(data->fb, pos, size, sfBlack);
        cycle_hue(&color);
        move_ball(data, size, &pos, &v);
        draw_circle(data->fb, pos, size, color);
        display_framebuffer(data);
    }
    return (0);
}
