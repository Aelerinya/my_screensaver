/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Main of the my_screensaver project : error management
*/

#include "main.h"
#include "prototypes.h"
#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return disp_error_in_arguments(ac);
    if (my_strcmp(av[1], "-h") == 0)
        return disp_usage();
    return (0);
}
