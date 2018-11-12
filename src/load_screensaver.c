/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Main loop of the my_screensaver project
*/

#include <SFML/Graphics.h>
#include "prototypes.h"
#include "globals.h"

int start_screensaver(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    framebuffer_t *fb = framebuffer_create(800, 600);

    window = sfRenderWindow_create(mode, "My screensaver", sfDefaultStyle, NULL);
    screensaver_list[0].f(fb, window);
    sfRenderWindow_destroy(window);
    return (0);
}

void event_loop(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void display_framebuffer(sfRenderWindow *window, framebuffer_t *fb,
sfTexture *texture, sfSprite *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfTexture_updateFromPixels(texture, fb->pixels,
    fb->width, fb->height, 0, 0);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}
