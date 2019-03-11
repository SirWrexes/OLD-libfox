/*
** EPITECH PROJECT, 2018
** libfox
** File description:
** Write a string the normal way
*/

#include "private/p_foxprintf.h"

__attribute__ ((always_inline))
inline void fox_puts(str3c_t str)
{
    size_t len = 0;

    if (str == NULL) {
        N_ADD(write(1, "(null)", 6));
        return;
    }
    len = fox_strlen(str);
    N_ADD(write(1, str, len));
}

__attribute__ ((always_inline))
inline void fox_puts2(str3c_t str)
{
    size_t len = 0;

    if (str == NULL) {
        N_ADD(write(1, "(null)", 6));
        return;
    }
    while (str[len] != '\0')
        if (IS_PRINTABLE(str[len]))
            fox_putc(str[len]);
        else
            fox_putnpc(str[len]);
}