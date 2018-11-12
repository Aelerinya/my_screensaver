/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Structure that stores data between screensavers
*/

typedef struct ssv_data {
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    framebuffer_t *fb;
    int ssv;
    sfClock* time_elapsed;
} ssv_data_t;
