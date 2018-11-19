/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Screensaver that displays an automatic snake game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "prototypes.h"
#include "globals.h"

static linked_list_t *create_snake(ssv_data_t *data)
{
    linked_list_t *list = NULL;
    linked_list_t *element;
    sfIntRect *rect;
    int pos = 400;

    for (int i = 0; i < 4; i++) {
        element = malloc(sizeof(linked_list_t));
        element->next = list;
        rect = malloc(sizeof(sfIntRect));
        rect->top = 100 + 1;
        rect->left = pos + 1;
        rect->width = 18;
        rect->height = 18;
        element->data = rect;
        draw_rect(data->fb, *rect, sfWhite);
        list = element;
        pos -= 20;
    }
    return list;
}

static sfIntRect *create_apple(framebuffer_t *fb)
{
    sfIntRect *apple = malloc(sizeof(sfIntRect));

    apple->top = (rand() % (fb->height / 20 - 2)) * 20 + 1;
    apple->left = (rand() % (fb->width / 20 - 2)) * 20 + 1;
    apple->width = 18;
    apple->height = 18;
    draw_rect(fb, *apple, sfRed);
    return apple;
}

static void catch_apple(ssv_data_t *data, linked_list_t **tail,
sfIntRect *rect, sfIntRect **apple)
{
    linked_list_t *tmp;
    sfIntRect *prev_rect;

    if (rect->top == (*apple)->top && rect->left == (*apple)->left) {
        free(*apple);
        *apple = create_apple(data->fb);
    } else {
        tmp = (*tail)->next;
        prev_rect = (*tail)->data;
        draw_rect(data->fb, *prev_rect, sfBlack);
        free((*tail)->data);
        free(*tail);
        *tail = tmp;
    }
}

static int move_snake(ssv_data_t *data, linked_list_t **tail,
sfVector2i *velocity, sfIntRect **apple)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));
    linked_list_t *head;
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    sfIntRect *prev_rect;

    for (head = *tail; head->next != NULL; head = head->next);
    prev_rect = head->data;
    new->next = NULL;
    new->data = rect;
    rect->top = prev_rect->top + velocity->y;
    rect->left = prev_rect->left + velocity->x;
    rect->height = prev_rect->height;
    rect->width = prev_rect->width;
    draw_rect(data->fb, *rect, sfWhite);
    head->next = new;
    catch_apple(data, tail, rect, apple);
    return snake_catch_lose(data->fb, *tail, new);
}

int snake(ssv_data_t *data)
{
    sfIntRect *apple = create_apple(data->fb);
    linked_list_t *tail = create_snake(data);
    sfClock *clock = sfClock_create();
    sfInt64 interval = sfSeconds(.1).microseconds;
    sfVector2i velocity = {20, 0};

    data->lock = 1;
    while (event_loop(data)) {
        if (sfClock_getElapsedTime(clock).microseconds > interval) {
            snake_get_input(&velocity);
            if (move_snake(data, &tail, &velocity, &apple))
                data->lock = -1;
            sfClock_restart(clock);
        }
        display_framebuffer(data);
    }
    return (0);
}
