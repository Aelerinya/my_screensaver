/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Seconds file of snake screensaver
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "prototypes.h"

void snake_get_input(sfVector2i *velocity)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) && velocity->y == 0) {
        velocity->x = 0, velocity->y = -20;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && velocity->x == 0) {
        velocity->x = -20, velocity->y = 0;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && velocity->y == 0) {
        velocity->x = 0, velocity->y = 20;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && velocity->x == 0)
        velocity->x = 20, velocity->y = 0;
}

int snake_catch_lose(framebuffer_t *fb, linked_list_t *tail,
linked_list_t *head)
{
    sfIntRect *tail_r;
    sfIntRect *head_r = head->data;

    if ((unsigned int)head_r->top > fb->height || head_r->top < 0)
        return (1);
    if ((unsigned int)head_r->left > fb->width || head_r->left < 0)
        return (1);
    while (tail->next != NULL) {
        tail_r = tail->data;
        if (head_r->top == tail_r->top && head_r->left == tail_r->left)
            return (1);
        tail = tail->next;
    }
    return (0);
}
