/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Phantomatic figures
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "prototypes.h"

static void draw_phantom_pixel(framebuffer_t *fb, unsigned int x,
unsigned int y)
{
    unsigned int position = (fb->width * y + x) * 4 + 3;
    unsigned int up = (y > 0) ? (fb->width * (y - 1) + x) * 4 + 3 : 0;
    unsigned int sum;
    unsigned char new;

    if (x == 0)
        new = (y == 0) ? 200 : fb->pixels[up];
    else if (y == 0)
        new = fb->pixels[position - 4];
    else {
        sum = fb->pixels[up] + fb->pixels[position - 4];
        new = (sum) / 2;
        new += (sum % 2) ? rand() % 2 : 0;
    }
    new = (new <= 1) ? 2 : new;
    new = (new >= 254 && (x == 0 || y == 0)) ? 253 : new;
    new += rand() % 3 - 1 + (rand() % 30 == 0);
    fb->pixels[position] = new;
}

static void draw_phantoms(framebuffer_t *fb)
{
    for (unsigned int y = 0; y < fb->height; y++)
        for (unsigned int x = 0; x < fb->width; x++)
                draw_phantom_pixel(fb, x, y);
}

int phantoms(ssv_data_t *data)
{
    sfColor white_transparent = {255, 255, 255, 0};

    reset_framebuffer(data->fb, white_transparent);
    draw_phantoms(data->fb);
    while (event_loop(data)) {
        display_framebuffer(data);
    }
    return (0);
}
