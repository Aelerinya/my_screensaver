/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Prototypes of the extern functions of the my_screensaver sources
*/

#include <SFML/Graphics.h>
#include "framebuffer_t.h"
#include "ssv_data_t.h"
#include "screensaver_t.h"

int disp_error_in_arguments(int ac);
int disp_usage(void);
int disp_error_invalid_id(int ssv);
int start_screensaver(int ssv);
ssv_data_t *init_ssv_data(int ssv);

int event_loop(ssv_data_t *data);

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
sfColor color);
void display_framebuffer(ssv_data_t *data);
void reset_framebuffer(framebuffer_t *fb, sfColor color);

int first_screensaver(ssv_data_t *data);
int second_screensaver(ssv_data_t *data);
int third_screensaver(ssv_data_t *data);
int lines(ssv_data_t *data);
