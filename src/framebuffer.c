/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Basic functions to manipulate framebuffers
*/

#include <SFML/Graphics.h>
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

void reset_framebuffer(framebuffer_t *fb, sfColor color)
{
    for (unsigned int i = 0; i < fb->width * fb->height * 4; i += 4) {
        fb->pixels[i] = color.r;
        fb->pixels[i + 1] = color.g;
        fb->pixels[i + 2] = color.b;
        fb->pixels[i + 3] = color.a;
    }
}
