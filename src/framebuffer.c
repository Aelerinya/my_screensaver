/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Basic functions to manipulate framebuffers
*/

#include "framebuffer_t.h"
#include <stdlib.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *new_fb;
    unsigned int size = width * height * 4;

    new_fb = malloc(sizeof(framebuffer_t));
    new_fb->width = width;
    new_fb->height = height;
    new_fb->pixels = malloc(sizeof(char) * size);
    return new_fb;
}

void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
sfColor color)
{
    unsigned int position = (framebuffer->width * y + x) * 4;

    framebuffer->pixels[position] = color.r;
    framebuffer->pixels[position + 1] = color.g;
    framebuffer->pixels[position + 2] = color.b;
    framebuffer->pixels[position + 3] = color.a;
}
