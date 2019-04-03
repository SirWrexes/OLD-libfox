/*
** EPITECH PROJECT, 2018
** libfox_string
** File description:
** String tokenizer
*/

#include "private/p_foxstring.h"

__a((nonnull(2, 3)))
str_t fox_strtok_r(str_t str, str3c_t delims, str_t *stock)
{
    str_t end;

    if (str == NULL && *stock == NULL)
        return NULL;
    if (str != NULL && str != *stock)
        *stock = str;
    str = str ? : *stock;
    str += fox_strspn(str, delims);
    if (*str == '\0') {
        *stock = str;
        return NULL;
    }
    end = str + fox_strcspn(str, delims);
    if (*end == '\0') {
        *stock = end;
        return str;
    }
    *end = '\0';
    *stock = end + 1;
    return str;
}

__a((nonnull(2)))
str_t fox_strtok(str_t str, str3c_t delims)
{
    static str_t stock = NULL;

    return fox_strtok_r(str, delims, &stock);
}