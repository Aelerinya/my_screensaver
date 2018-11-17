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
sfClock* elapsed_time;
int lock;
} ssv_data_t;
