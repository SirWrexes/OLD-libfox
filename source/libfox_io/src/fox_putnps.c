/*
** EPITECH PROJECT, 2019
** libfox_IO
** File description:
** Write a string with any non printable char as its octal value
*/

#include "private/p_foxio.h"

extern inline ssize_t fox_fputnps(int fd, str3c_t str)
{
    size_t len = 0;
    ssize_t n;

    if (str == NULL)
        return fox_fputs(fd, "(null)");
    while (str[len] != '\0')
        if (CHAR_PRINTABLE(str[len])) {
            n = fox_fputc(fd, str[len]);
            len += n > 0 ? n : 0;
        } else {
            n = fox_fputnpc(fd, str[len]);
            len += n > 0 ? n : 0;
        }
    return len;
}

extern inline ssize_t fox_eputnps(str3c_t str)
{
    return fox_fputnps(2, str);
}

extern inline ssize_t fox_putnps(str3c_t str)
{
    return fox_fputnps(1, str);
}