/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Choose the adequate printer depending on arg info
*/

#include "private/fox_printf/p_foxprintf.h"
#include "private/fox_printf/p_il_printerpicker_unsigned.h"

static __a((nonnull))
ssize_t print_bin(int fd, farg_t const * const arg)
{
    switch (arg->lenmodif) {
    default :
        return fox_fputuint_base(fd, arg->value.ui, "01");
    case LM_CHAR :
        return fox_fputuint_base(fd, arg->value.uc, "01");
    case LM_SHORT :
        return fox_fputuint_base(fd, arg->value.uh, "01");
    case LM_LONG :
    case LM_ULONG :
        return fox_fputullong_base(fd, arg->value.ul, "01");
    case LM_LLONG :
        return fox_fputullong_base(fd, arg->value.ull, "01");
    }
}

static __a((nonnull))
ssize_t print_oct(int fd, farg_t const * const arg)
{
    switch (arg->lenmodif) {
    default :
        return fox_fputuint_base(fd, arg->value.ui, "01234567");
    case LM_CHAR :
        return fox_fputuint_base(fd, arg->value.uc, "01234567");
    case LM_SHORT :
        return fox_fputuint_base(fd, arg->value.uh, "01234567");
    case LM_LONG :
    case LM_ULONG :
        return fox_fputullong_base(fd, arg->value.ul, "01234567");
    case LM_LLONG :
        return fox_fputullong_base(fd, arg->value.ull, "01234567");
    }
}

static __a((nonnull))
ssize_t print_hex(int fd, farg_t const * const arg)
{
    switch (arg->lenmodif) {
    default :
        return fox_fputuint_base(fd, arg->value.ui, _hex_base_(arg->convspec));
    case LM_CHAR :
        return fox_fputuint_base(fd, arg->value.uc, _hex_base_(arg->convspec));
    case LM_SHORT :
        return fox_fputuint_base(fd, arg->value.uh, _hex_base_(arg->convspec));
    case LM_LONG :
    case LM_ULONG :
        return
        fox_fputullong_base(fd, arg->value.ul, _hex_base_(arg->convspec));
    case LM_LLONG :
        return
        fox_fputullong_base(fd, arg->value.ull, _hex_base_(arg->convspec));
    }
}

static __a((nonnull))
ssize_t print_unsigned_small(int fd, farg_t const * const arg)
{
    switch (arg->lenmodif) {
    case LM_CHAR :
        return fox_fputuint(fd, arg->value.uc);
    case LM_SHORT :
        return fox_fputuint(fd, arg->value.uh);
    default :
        return fox_fputuint(fd, arg->value.ui);
    }
}

inline __a((nonnull))
ssize_t print_unsigned(int fd, farg_t const * const arg)
{
    if (arg->convspec != CS_UINT)
        if (arg->convspec == CS_BIN)
            return print_bin(fd, arg);
        else if (arg->convspec == CS_OCT)
            return print_oct(fd, arg);
        else
            return print_hex(fd, arg);
    else
        if (arg->lenmodif <= LM_SHORT)
            return print_unsigned_small(fd, arg);
        else if (arg->lenmodif == LM_LONG || arg->lenmodif == LM_ULONG)
            return fox_fputullong(fd, arg->value.ul);
        else
            return fox_fputullong(fd, arg->value.ull);
}