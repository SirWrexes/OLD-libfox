/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** fox_display prototypes
*/

#ifndef LIBFOX_LIBFOX_DISPLAY_H
#define LIBFOX_LIBFOX_DISPLAY_H

#include <sys/types.h>
#include "fox_define.h"

/*
** All of the following functions have 3 variations :
** fox_<name> : write to stdout
** fox_e<name> : write to stderr
** fox_f<name> : write to given file descriptor
** Return value : number of written bytes or -1 in case of error
*/

// Write a single character
ssize_t fox_putc(char c);
ssize_t fox_eputc(char c);
ssize_t fox_fputc(int fd, char c);

// Write a non printable char in its octal value
ssize_t fox_putnpc(char c);
ssize_t fox_eputnpc(char c);
ssize_t fox_fputnpc(int fd, char c);

// Write a string
ssize_t fox_puts(str3c_t str);
ssize_t fox_eputs(str3c_t str);
ssize_t fox_fputs(int fd, str3c_t str);

// Write a string with non printable chars in their octal value
ssize_t fox_putnps(str3c_t str);
ssize_t fox_eputnps(str3c_t str);
ssize_t fox_fputnps(int fd, str3c_t str);

// Write an int
ssize_t fox_putint(int nb);
ssize_t fox_eputint(int nb);
ssize_t fox_fputint(int fd, int nb);

// Write an unsigned int
ssize_t fox_putuint(uint nbr);
ssize_t fox_eputuint(uint nbr);
ssize_t fox_fputuint(int fd, uint nbr);

// Write a long long
ssize_t fox_putllong(llong_t nbr);
ssize_t fox_eputllong(llong_t nbr);
ssize_t fox_fputllong(int fd, llong_t nbr);

// Write an unsigned long long
ssize_t fox_putullong(ullong_t nbr);
ssize_t fox_eputullong(ullong_t nbr);
ssize_t fox_fputullong(int fd, ullong_t nbr);

// Write an unsigned int in given base
size_t fox_putuint_base(uint nbr, str3c_t base)            __a((nonnull));
size_t fox_eputuint_base(uint nbr, str3c_t base)           __a((nonnull));
size_t fox_fputuint_base(int fd, uint nbr, str3c_t base)   __a((nonnull));

// Write an unsigned long long in given base
size_t fox_putullong_base(ullong_t nbr, str3c_t base)          __a((nonnull));
size_t fox_eputullong_base(ullong_t nbr, str2c_t base)         __a((nonnull));
size_t fox_fputullong_base(int fd, ullong_t nbr, str2c_t base) __a((nonnull));

__attribute__ ((nonnull, format(printf, 2,3)))
ssize_t fox_fprintf(int fd, str3c_t fstr, ...);

#undef fox_printf
#undef fox_eprintf
#define fox_printf(fstr, ...)  fox_fprintf(1, (fstr), ##__VA_ARGS__)
#define fox_eprintf(fstr, ...) fox_fprintf(2, (fstr), ##__VA_ARGS__)

#endif //LIBFOX_LIBFOX_DISPLAY_H
