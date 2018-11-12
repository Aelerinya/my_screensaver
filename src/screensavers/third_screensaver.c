/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** first screen saver to tests things
*/

#include <SFML/Graphics.h>
#include "prototypes.h"

int third_screensaver(framebuffer_t *fb, sfRenderWindow *window)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_create(fb->width, fb->height);
    sprite = sfSprite_create();
    for (unsigned int i = 0; i < fb->width * fb->height * 4; i += 4) {
        fb->pixels[i] = 0;
        fb->pixels[i + 1] = 255;
        fb->pixels[i + 2] = 0;
        fb->pixels[i + 3] = 255;
    }
    while (sfRenderWindow_isOpen(window)) {
        event_loop(window);
        display_framebuffer(window, fb, texture, sprite);
    }
    return (0);
}
