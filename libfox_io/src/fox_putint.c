/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Write an int
*/

#include "private/__foxdisplay.h"

ssize_t fox_putint(int nb)
{
    char conv[fox_nbsize(nb)];
    bool neg = nb < 0;
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(ABS(nb) % 10);
        nb /= 10;
    } while (nb);
    if (neg && len)
        write(1, "-", 1);
    i = len - 1;
    do
        if (write(1, &conv[i--], 1) == -1)
            return -1;
    while (i >= 0);
    return len + neg && len;
}

ssize_t fox_eputint(int nb)
{
    char conv[fox_nbsize(nb)];
    bool neg = nb < 0;
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(ABS(nb) % 10);
        nb /= 10;
    } while (nb);
    if (neg && len)
        write(2, "-", 1);
    i = len - 1;
    do
        if (write(2, &conv[i--], 1) == -1)
            return -1;
    while (i >= 0);
    return len + neg && len;
}

ssize_t fox_fputint(int fd, int nb)
{
    char conv[fox_nbsize(nb)];
    bool neg = nb < 0;
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(ABS(nb) % 10);
        nb /= 10;
    } while (nb);
    if (neg && len)
        write(fd, "-", 1);
    i = len - 1;
    do
        if (write(fd, &conv[i--], 1) == -1)
            return -1;
    while (i >= 0);
    return len + neg && len;
}

// This functions work like this :
//  1. Make a char array of size n where n is the count of digits in nb
//  2. Check if the number is negative
//  3. Initialize a length variable
//  3b. Initialize an index for later use
//  4. Store each last digit in the array...
//      -- We use the absolute value to avoid ascii mishaps because
//      -- Digit is directly converted to ascii value
//      -- The number is stored reverted (123 becomes "321")
//  ... by doing to magic %10 → /10 each iteration ...
//      -- This picks the last digit (3 in 123) with %10
//      -- And then 'deletes' it ((int) 123 / 10 becomes 12)
//  ... and finally len is incremented after each iteration (len++)
//  5. If nb is a non null negative, write '-'
//  6. len - 1 goes into i to start from the end of the array
//  7. Each iteration we check if write is successful, while writing a digit
//      -- If not, -1 is returned
//      -- This goes on until i < 0 and we wrote the whole number
//  8. The cont of digits in nb is returned + 1 if it's negative, ('-')