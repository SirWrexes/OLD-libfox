/*
** EPITECH PROJECT, 2018
** libfox_memory -- cleanup
** File description:
** Autoclose a file descriptor or pointer
*/

#include "private/p_foxmemory.h"

__attribute__ ((nonnull))
void fox_autoclose_fd(int *fd)
{
    if (*fd < 0)
        return;
    close(*fd);
    *fd = -1;
}

void fox_autoclose_fp(FILE **fp)
{
    if (*fp == NULL)
        return;
    fclose(*fp);
    *fp = NULL;
}