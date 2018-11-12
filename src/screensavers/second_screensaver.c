/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** first screen saver to tests things
*/

#include <SFML/Graphics.h>
#include "prototypes.h"

int second_screensaver(framebuffer_t *fb, sfRenderWindow *window, int *ssv)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_create(fb->width, fb->height);
    sprite = sfSprite_create();
    for (unsigned int i = 0; i < fb->width * fb->height * 4; i += 4) {
        fb->pixels[i] = 255;
        fb->pixels[i + 1] = 0;
        fb->pixels[i + 2] = 0;
        fb->pixels[i + 3] = 255;
    }
    while (event_loop(window, ssv)) {
        display_framebuffer(window, fb, texture, sprite);
    }
    return (0);
}
