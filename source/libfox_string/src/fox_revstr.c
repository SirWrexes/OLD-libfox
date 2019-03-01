/*
** EPITECH PROJECT, 2018
** libfox_string
** File description:
** Revert a string and return its pointer
*/

#include "private/__foxstring.h"

__attribute__((nonnull))
char *fox_revstr(char *str)
{
    size_t len = fox_strlen(str);
    char c;

    for (size_t i = 0; i < len / 2; i += 1) {
        c = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = c;
    }
    return str;
}
