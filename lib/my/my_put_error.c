/*
** EPITECH PROJECT, 2018
** my_put_error
** File description:
** Print string in stderr
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_put_error(char const *str)
{
    write(2, str, my_strlen(str));
    return (84);
}
