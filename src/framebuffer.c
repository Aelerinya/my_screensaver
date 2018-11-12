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
