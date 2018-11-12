/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** first screen saver to tests things
*/

#include <SFML/Graphics.h>
#include "prototypes.h"

int first_screensaver(framebuffer_t *fb, sfRenderWindow *window, int *ssv)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_create(fb->width, fb->height);
    sprite = sfSprite_create();
    for (unsigned int i = 0; i < fb->width * fb->height * 4; i++)
        fb->pixels[i] = 255;
    while (event_loop(window, ssv)) {
        display_framebuffer(window, fb, texture, sprite);
    }
    return (0);
}
