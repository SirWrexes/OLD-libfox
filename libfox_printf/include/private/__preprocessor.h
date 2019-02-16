/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** No description
*/

#ifndef LIBFOX_PREPROCESSOR_H
#define LIBFOX_PREPROCESSOR_H

#undef  _UNUSED
#define _UNUSED __attribute__ ((unused))

#undef  IS_PRINTABLE
#define IS_PRINTABLE(c) ((c) >= 32 && (c) <= 176)

#undef  ABS
#define ABS(i)  ((i) > 0 ? (i) : -(i))

#undef  ITOC
#define ITOC(i) ((char) ((i) + '0'))

#undef  N_GET
#undef  N_ADD
#undef  N_RST
#define N_GET       n_printed_bytes(0)
#define N_ADD(x)    n_printed_bytes((x))
#define N_RST       n_printed_bytes(0 - n_printed_bytes(0))

#endif //LIBFOX_PREPROCESSOR_H
