/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Error management
*/

#include <my.h>

int disp_error_in_arguments(int ac)
{
    my_put_error("./my_screensaver: bad arguments: ");
    my_put_error(my_nbr_to_str(ac - 1));
    my_put_error(" given but 1 is required\nretry with -h\n");
    return (84);
}
