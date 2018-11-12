/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Main loop of the my_screensaver project
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "prototypes.h"
#include "globals.h"

int start_screensaver(int ssv)
{
    ssv_data_t *data = init_ssv_data(ssv);

    while (sfRenderWindow_isOpen(data->window))
        screensaver_list[ssv - 1].f(data->fb, data->window, &ssv);
    sfRenderWindow_destroy(data->window);
    return (0);
}

int event_loop(sfRenderWindow *window, int *ssv)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (0);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        *ssv = (*ssv > 1) ? *ssv - 1 : MAX_ID;
        my_put_nbr(*ssv);
        return (0);
    } else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        *ssv = (*ssv < MAX_ID) ? *ssv + 1 : 1;
        my_put_nbr(*ssv);
        return (0);
    }
    return (1);
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

ssv_data_t *init_ssv_data(int ssv)
{
    ssv_data_t *data = malloc(sizeof(ssv_data_t));
    framebuffer_t *fb = framebuffer_create(800, 600);
    sfVideoMode mode = {fb->width, fb->height, 32};

    data->window = sfRenderWindow_create(mode, "My screensaver",
    sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(data->window, 60);
    data->texture = sfTexture_create(fb->width, fb->height);
    data->sprite = sfSprite_create();
    data->fb = fb;
    data->ssv = ssv;
    data->elapsed_time = sfClock_create();
    return data;
}
