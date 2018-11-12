/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** first screen saver to tests things
*/

#include <SFML/Graphics.h>
#include "prototypes.h"

int first_screensaver(ssv_data_t *data)
{
    for (unsigned int i = 0; i < data->fb->width * data->fb->height * 4; i++)
        data->fb->pixels[i] = 255;
    while (event_loop(data)) {
        display_framebuffer(data);
    }
    return (0);
}
