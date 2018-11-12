/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** second screen saver to tests things : red
*/

#include <SFML/Graphics.h>
#include "prototypes.h"

int second_screensaver(ssv_data_t *data)
{
    unsigned int length = data->fb->width * data->fb->height * 4;
    for (unsigned int i = 0; i < length; i += 4) {
        data->fb->pixels[i] = 255;
        data->fb->pixels[i + 1] = 0;
        data->fb->pixels[i + 2] = 0;
        data->fb->pixels[i + 3] = 255;
    }
    while (event_loop(data)) {
        display_framebuffer(data);
    }
    return (0);
}
