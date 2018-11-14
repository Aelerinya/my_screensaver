/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Functions to create and modify colors
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

void cycle_hue(sfColor *color)
{
    if (color->r == 255 && color->g < 255 && color->b == 0)
        color->g++;
    if (color->r > 0 && color->g == 255 && color->b == 0)
        color->r--;
    if (color->r == 0 && color->g == 255 && color->b < 255)
        color->b++;
    if (color->r == 0 && color->g > 0 && color->b == 255)
        color->g--;
    if (color->r < 255 && color->g == 0 && color->b == 255)
        color->r++;
    if (color->r == 255 && color->g == 0 && color->b > 0)
        color->b--;
}

sfColor random_hue(void)
{
    sfColor random;
    int mode = rand() % 6;

    random.r = (mode == 0 || mode == 5) ? 255 : 0;
    random.g = (mode == 1 || mode == 2) ? 255 : 0;
    random.b = (mode == 3 || mode == 4) ? 255 : 0;
    random.r = (mode == 1 || mode == 4) ? rand() % 255 : random.r;
    random.g = (mode == 0 || mode == 3) ? rand() % 255 : random.g;
    random.b = (mode == 2 || mode == 5) ? rand() % 255 : random.b;
    random.a = 255;
    return random;
}
