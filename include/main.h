/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Header for global constants
*/

#pragma once

const int MAX_ID = 4;
const screensaver_t screensaver_list[4] = {
{"first screensaver", &first_screensaver},
{"second screensaver", &second_screensaver},
{"print random colored squares", &squares},
{"print horizontal and vertical lines at random", &lines}
};
