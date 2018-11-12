/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Main of the my_screensaver project : error management
*/

#include "prototypes.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return disp_error_in_arguments(ac);
    return (0);
}
