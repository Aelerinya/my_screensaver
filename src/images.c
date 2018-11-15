/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Utilities to manipulate images
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "prototypes.h"
#include "my.h"

int load_raw_image_in_framebuffer(framebuffer_t *fb, char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int length = fb->width * fb->height * 4;
    char *buff;

    if (!(buff = malloc(sizeof(char) * length))) {
        my_put_error("Could not allocate buffer.\n");
        return (-1);
    } else if (fd == -1) {
        my_put_error(filepath);
        my_put_error(" : Could not open file.\n");
        return (-1);
    }
    if (read(fd, buff, length) < length) {
        my_put_error("Not enough data in file\n");
        free(buff);
        return (-1);
    }
    for (int i = 0; i < length; i++)
        fb->pixels[i] = buff[i];
    free(buff);
    return (0);
}
