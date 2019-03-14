/*
** EPITECH PROJECT, 2019
** libfox_string
** File description:
** Public header
*/

#ifndef LIBFOX_FOX_STRING_H
#define LIBFOX_FOX_STRING_H

#include <stdbool.h>
#include <stddef.h>
#include "fox_define.h"

// Returns true if a string is numeric, returns false otherwise
bool fox_isnum(str3c_t str) __a((nonnull, pure));

// Convert a string into an int
int fox_atoi(str3c_t str) __a((pure));

// Returns the number of characters in a string
size_t fox_strlen(str3c_t str) __a((pure));

// Check if s1 is the same as s2 [up to n character]
int fox_strcmp(str3c_t s1, str3c_t s2)             __a((nonnull, pure));
char fox_strncmp(str3c_t s1, str3c_t s2, size_t n) __a((nonnull, pure));

// Revert a string and return its pointer
str_t fox_revstr(str_t str) __a((nonnull));

// Copy a string into another [up to n characters]
str_t fox_strcpy(str_t dst, str3c_t src)    __a((nonnull));
str_t fox_strncpy(str_t dst, str3c_t src)   __a((nonnull));

// Returns a pointer to a newly created duplicate of src string
str_t fox_strdup(str3c_t src) __a((malloc));

#endif //LIBFOX_FOX_STRING_H
