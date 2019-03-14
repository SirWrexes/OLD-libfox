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
        return fox_fputuint_base(fd, arg->argvalue.ui, "01");
    case LM_CHAR :
        return fox_fputuint_base(fd, arg->argvalue.uc, "01");
    case LM_SHORT :
        return fox_fputuint_base(fd, arg->argvalue.uh, "01");
    case LM_LONG :
    case LM_ULONG :
        return fox_fputullong_base(fd, arg->argvalue.ul, "01");
    case LM_LLONG :
        return fox_fputullong_base(fd, arg->argvalue.ull, "01");
    }
}

static __a((nonnull))
ssize_t print_oct(int fd, farg_t const * const arg)
{
    switch (arg->lenmodif) {
    default :
        return fox_fputuint_base(fd, arg->argvalue.ui, "01234567");
    case LM_CHAR :
        return fox_fputuint_base(fd, arg->argvalue.uc, "01234567");
    case LM_SHORT :
        return fox_fputuint_base(fd, arg->argvalue.uh, "01234567");
    case LM_LONG :
    case LM_ULONG :
        return fox_fputullong_base(fd, arg->argvalue.ul, "01234567");
    case LM_LLONG :
        return fox_fputullong_base(fd, arg->argvalue.ull, "01234567");
    }
}

static __a((nonnull))
ssize_t print_hex(int fd, farg_t const * const arg)
{
    switch (arg->lenmodif) {
    default : return
        fox_fputuint_base(fd, arg->argvalue.ui, _hex_base_(arg->convspec));
    case LM_CHAR : return
        fox_fputuint_base(fd, arg->argvalue.uc, _hex_base_(arg->convspec));
    case LM_SHORT : return
        fox_fputuint_base(fd, arg->argvalue.uh, _hex_base_(arg->convspec));
    case LM_LONG :
    case LM_ULONG : return
        fox_fputullong_base(fd, arg->argvalue.ul, _hex_base_(arg->convspec));
    case LM_LLONG : return
        fox_fputullong_base(fd, arg->argvalue.ull, _hex_base_(arg->convspec));
    }
}

static __a((nonnull))
ssize_t print_unsigned_small(int fd, farg_t const * const arg)
{
    switch (arg->lenmodif) {
    case LM_CHAR :
        return fox_fputuint(fd, arg->argvalue.uc);
    case LM_SHORT :
        return fox_fputuint(fd, arg->argvalue.uh);
    default :
        return fox_fputuint(fd, arg->argvalue.ui);
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
            return fox_fputullong(fd, arg->argvalue.ul);
        else
            return fox_fputullong(fd, arg->argvalue.ull);
}