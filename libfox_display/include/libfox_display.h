/*
** EPITECH PROJECT, 2018
** libfox_display
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
*/

// Write a single character,
// RETURN : write() return value
ssize_t fox_putc(char c);
ssize_t fox_eputc(char c);
ssize_t fox_fputc(int fd, char c);

// Write a complete string
// RETURN : write() return value
ssize_t fox_puts(char const *str);
ssize_t fox_eputs(char const *str);
ssize_t fox_fputs(int fd, char const *str);

#endif //LIBFOX_LIBFOX_DISPLAY_H
