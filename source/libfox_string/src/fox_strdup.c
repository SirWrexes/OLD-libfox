/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** Returns a pointer to a newly created duplicate of src string
*/

#include "private/__foxstring.h"

str_t fox_strdup(str3c_t src)
{
    int   i;
    char *dest = NULL;

    if (src == NULL)
        return NULL;
    dest = malloc(sizeof(*dest) * (fox_strlen(src) + 1));
    if (dest == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i += 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}