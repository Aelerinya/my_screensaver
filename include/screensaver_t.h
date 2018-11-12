/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** screensaver structure
*/

#include <SFML/Graphics.h>

typedef struct screensaver {
    char *description;
    int (*f)(ssv_data_t *data);
} screensaver_t;
