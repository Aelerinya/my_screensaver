/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** random noise, but colorfull
*/

#include <SFML/Graphics.h>
#include "prototypes.h"

int colorfull_noise(ssv_data_t *data)
{
    while (event_loop(data)) {
        for (unsigned int i = 0; i < data->fb->width; i++)
            for (unsigned int j = 0; j < data->fb->height; j++)
                put_pixel(data->fb, i, j, random_hue());
        display_framebuffer(data);
    }
    return (0);
}
