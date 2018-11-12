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
        screensaver_list[data->ssv - 1].f(data);
    sfRenderWindow_destroy(data->window);
    return (0);
}

int event_loop(ssv_data_t *data)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(data->window);
            return (0);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        data->ssv = (data->ssv > 1) ? data->ssv - 1 : MAX_ID;
        return (0);
    } else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        data->ssv = (data->ssv < MAX_ID) ? data->ssv + 1 : 1;
        return (0);
    }
    return (1);
}

void display_framebuffer(ssv_data_t *data)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfTexture_updateFromPixels(data->texture, data->fb->pixels,
    data->fb->width, data->fb->height, 0, 0);
    sfSprite_setTexture(data->sprite, data->texture, sfFalse);
    sfRenderWindow_drawSprite(data->window, data->sprite, NULL);
    sfRenderWindow_display(data->window);
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
