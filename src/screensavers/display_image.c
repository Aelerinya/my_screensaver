/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Screensaver which loads an image from a bitmap and displays it
*/

#include "prototypes.h"
#include "my.h"

int display_image(ssv_data_t *data)
{
    load_raw_image_in_framebuffer(data->fb, "bitmaps/victor.data");
    while(event_loop(data)) {
        display_framebuffer(data);
    }
    return (0);
}
