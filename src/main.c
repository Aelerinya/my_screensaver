/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Main of the my_screensaver project : error management
*/

#include "prototypes.h"
#include "main.h"
#include "my.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    int ssv;

    if (ac != 2)
        return disp_error_in_arguments(ac);
    if (my_strcmp(av[1], "-h") == 0)
        return disp_usage();
    if (my_strcmp(av[1], "-d") == 0)
        return disp_screensaver_list();
    ssv = my_getnbr(av[1]);
    if (ssv < 1 || ssv > MAX_ID)
        return disp_error_invalid_id(ssv);
    start_screensaver(ssv);
    return (0);
}
