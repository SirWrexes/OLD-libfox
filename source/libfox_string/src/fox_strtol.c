/*
** EPITECH PROJECT, 2019
** libfox_str
** File description:
** Convert a string to a long
*/

#include "private/p_foxstring.h"

static char const base[36] = {
    '0', '1', '2', '3', '4',
    '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E',
    'F', 'G', 'H', 'I', 'K',
    'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U',
    'V', 'W', 'X', 'Y', 'Z',
};

enum {
    A   ,
    B   ,
    BASE,
    POW ,
    NEG ,
    KEY_COUNT
};

__A((const))
static bool is_base36(char c)
{
    return IS_ALPHANUM(c);
}

static __A((nonnull, pure))
long getlong(str3c_t str, char **endptr, size_t i[KEY_COUNT])
{
    long ret = 0;
    size_t n = 0
    size_t x = 0;
    size_t y = 0;

    for (i[B] -= 1 ; i[B] >= i[A] ; i[B] -= 1) {
        for (n = 0
        ;   n < 36 && CHAR_TOUPPER(str[i[B]]) != is_base36(str[i[B]])
        ;   n += 1);
        x = n * fox_pow(i[BASE], i[POW]++);
        if (y > 0 && ret > LONG_MAX - y)
            return LONG_MAX;
        if (y < 0 && x < INT_MIN - y)
            return LONG_MIN;
        ret += y;
    }
    return ret;
}

static bool get_base_and_sign(str3c_t str, size_t base, size_t i[KEY_COUNT])
{
    if (base != 0 && (base < 2 || base > 36))
        return true;
    IS_SIGN(str[i[A]]) ? i[A]++ & i[NEG]++ : 0;
    if (!is_base36(str[i[A]]))
        return true;
    if (str[i[A]] == '0') {
        i[A] += 1;
        if (CHAR_TOUPPER(str[i[A]]) == 'X' && (!base  || base == 16)) {
            i[A] += 1;
            i[BASE] = 16;
        } else if (str[i[A]] == '0' && (!base  || base == 16)) {
            i[A] += 1;
            i[BASE] = 8;
        } else
            i[BASE] = 10;
    }
    return false;
}

__A((nonnull(1), pure))
long fox_strtol(str3c_t str, char **endptr, size_t base)
{
    size_t i[KEY_COUNT] = {0};

    for (; !IS_EOL(str[i[A]]) && str[i[A]] == ' '; i[A] += 1);
    if (!IS_SIGN(str[i[A]]) && !is_base36(str[i[A]]))
        return 0;
    if (get_base_and_sign(str, base, i))
        return 0;
    i[B] = i[A];
    for(; !IS_EOL(str[i[B]]) && is_base36(str[i[B]]); i[B] += 1);
    return getlong(str, endptr, i);
}

int main(void)
{
    long n = 0;
    n = fox_strtol("123", NULL, 10);
    n = fox_strtol("      123", NULL, 10);
    n = fox_strtol("      +123", NULL, 10);
    n = fox_strtol("      -123", NULL, 10);
    n = fox_strtol("      -1:23", NULL, 10);
    return 0;
}