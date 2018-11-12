/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Prototypes of the extern functions of the my_screensaver sources
*/

#include <SFML/Graphics.h>
#include "framebuffer_t.h"
#include "screensaver_t.h"

int disp_error_in_arguments(int ac);
int disp_usage(void);
int disp_error_invalid_id(int ssv);
int start_screensaver(int ssv);

int event_loop(sfRenderWindow *window, int *ssv);

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
sfColor color);
void display_framebuffer(sfRenderWindow *window, framebuffer_t *fb,
sfTexture *texture, sfSprite *sprite);

int first_screensaver(framebuffer_t *fb, sfRenderWindow *window, int *ssv);
int second_screensaver(framebuffer_t *fb, sfRenderWindow *window, int *ssv);
int third_screensaver(framebuffer_t *fb, sfRenderWindow *window, int *ssv);
