/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Writre a single character
*/

#include "private/__foxprintf.h"

inline void fox_putc(char c)
{
    N_ADD(write(1, &c, 1));
}

inline void fox_putnpc(char c)
{
    N_ADD(write(1, "\\", 1));
    fox_putuint_base((uint) c, "01234567");
}