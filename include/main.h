/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Header for global constants
*/

#pragma once

const int MAX_ID = 4;
const screensaver_t screensaver_list[4] = {
{"colorfull noise", &colorfull_noise},
{"bouncing ball changing color", &bouncing},
{"print random colored squares", &squares},
{"print horizontal and vertical lines at random", &lines}
};
