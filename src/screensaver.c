/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Main loop of the my_screensaver project
*/

#include <SFML/Graphics.h>
#include "prototypes.h"

int start_screensaver(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    framebuffer_t *fb = framebuffer_create(800, 600);
    sfTexture *texture;
    sfSprite *sprite;

    window = sfRenderWindow_create(mode, "My screensaver", sfDefaultStyle, NULL);
    texture = sfTexture_create(800, 600);
    sprite = sfSprite_create();
    while (sfRenderWindow_isOpen(window)) {
        event_loop(window);
        sfTexture_updateFromPixels(texture, fb->pixels, 800, 600, 0, 0);
        sfSprite_setTexture(sprite, texture, sfFalse);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

void event_loop(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
