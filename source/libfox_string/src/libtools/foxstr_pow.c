/*
** EPITECH PROJECT, 2019
** libfox_string
** File description:
** Power calculcation
*/

#include "private/__foxstring.h"

__A((const))
long fox_pow(long nb, size_t power)
{
    return power ? nb * fox_pow(nb, --power) : 1;
}