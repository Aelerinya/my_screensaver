/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Error management
*/

#include "globals.h"
#include "my.h"

int disp_error_in_arguments(int ac)
{
    my_put_error("./my_screensaver: bad arguments: ");
    my_put_error(my_nbr_to_str(ac - 1));
    my_put_error(" given but 1 is required\nretry with -h\n");
    return (84);
}

int disp_usage(void)
{
    my_putstr("animation rendering in a CSFML window.\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_screensaver [OPTIONS] animation_id\n");
    my_putstr("  animation_id    ID of the animation to process ");
    my_putstr("(between 1 and ");
    my_putstr(my_nbr_to_str(MAX_ID));
    my_putstr(").\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -d               print the description of all ");
    my_putstr("the animations and quit.\n");
    my_putstr(" -h               print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" LEFT_ARROW       switch to the previous animation.\n");
    my_putstr(" RIGHT_ARROW      switch to the next animation.\n");
    return (0);
}
