/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Print string on screen using my_putchar
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
