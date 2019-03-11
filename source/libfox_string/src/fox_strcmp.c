/*
** EPITECH PROJECT, 2019
** libfox_string
** File description:
** strcmp
*/

#include "private/p_foxstring.h"

__A((nonnull, pure))
int fox_strcmp(str3c_t s1, str3c_t s2)
{
    size_t i = 0;

    for (; s1[i] == s2[i] && s1[i] && s2[i]; i += 1);
    if (s1[i] == s2[i])
        return 0;
    return s1[i] - s2[i] < 0 ? -1 : 1;
}

__A((nonnull, pure))
char fox_strncmp(str3c_t s1, str3c_t s2, size_t n)
{
    size_t i = 0;

    for (; s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1; i += 1);
    return s1[i] - s2[i];
}
