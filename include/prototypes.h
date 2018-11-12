/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Prototypes of the extern functions of the my_screensaver sources
*/

#include <SFML/Graphics.h>
#include "framebuffer_t.h"

int disp_error_in_arguments(int ac);
int disp_usage(void);
int start_screensaver(void);

void event_loop(sfRenderWindow *window);

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
sfColor color);
