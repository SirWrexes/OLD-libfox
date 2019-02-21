/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** fox_display prototypes
*/

#ifndef LIBFOX_LIBFOX_DISPLAY_H
#define LIBFOX_LIBFOX_DISPLAY_H

#include <sys/types.h>

/*
** All of the following functions have 3 variations :
** fox_<name> : write to stdout
** fox_e<name> : write to stderr
** fox_f<name> : write to given file descriptor
** Return value : number of written bytes or -1 in case of error
*/

// Write a single character,
ssize_t fox_putc(char c);
ssize_t fox_eputc(char c);
ssize_t fox_fputc(int fd, char c);

// Write a complete string
ssize_t fox_puts(char const *str);
ssize_t fox_eputs(char const *str);
ssize_t fox_fputs(int fd, char const *str);

// Write an int
ssize_t fox_putint(int nb);
ssize_t fox_eputint(int nb);
ssize_t fox_fputint(int fd, int nb);

#endif //LIBFOX_LIBFOX_DISPLAY_H
