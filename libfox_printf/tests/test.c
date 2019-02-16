/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** No description
*/

#include <stdio.h>
#include <stdarg.h>
#include "fox_printf.h"

int main(void)
{
    printf("%X%i\n", 45678u, 23);
    fox_printf("%X %n %isauce\n%s caca\n%n %n%n %% %n", 45678u, 23, "le cul ça fait");
    return 0;
}