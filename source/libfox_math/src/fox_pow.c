/*
** EPITECH PROJECT, 2019
** libfox_string
** File description:
** Power calculcation
*/

#include "private/p_foxstring.h"

__a((const))
long fox_pow(long nb, size_t power)
{
    return power ? nb * fox_pow(nb, --power) : 1;
}