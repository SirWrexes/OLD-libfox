/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Choose the adequate printer depending on arg info
*/

#include "private/p_foxprintf.h"
#include "private/p_il_printerpicker_unsigned.h"

static __attribute__ ((nonnull))
void print_bin(farg_t const * const arg)
{
    switch (arg->lenmodif) {
    default :
        fox_putuint_base(arg->argvalue.ui, "01");
        break;
    case LM_CHAR :
        fox_putuint_base(arg->argvalue.uc, "01");
        break;
    case LM_SHORT :
        fox_putuint_base(arg->argvalue.uh, "01");
        break;
    case LM_LONG :
    case LM_ULONG :
        fox_putullong_base(arg->argvalue.ul, "01");
        break;
    case LM_LLONG :
        fox_putullong_base(arg->argvalue.ull, "01");
        break;
    }
}

static __attribute__ ((nonnull))
void print_oct(farg_t const * const arg)
{
    switch (arg->lenmodif) {
    default :
        fox_putuint_base(arg->argvalue.ui, "01234567");
        break;
    case LM_CHAR :
        fox_putuint_base(arg->argvalue.uc, "01234567");
        break;
    case LM_SHORT :
        fox_putuint_base(arg->argvalue.uh, "01234567");
        break;
    case LM_LONG :
    case LM_ULONG :
        fox_putullong_base(arg->argvalue.ul, "01234567");
        break;
    case LM_LLONG :
        fox_putullong_base(arg->argvalue.ull, "01234567");
        break;
    }
}

static __attribute__ ((nonnull))
void print_hex(farg_t const * const arg)
{
    switch (arg->lenmodif) {
    default :
        fox_putuint_base(arg->argvalue.ui, _hex_base_(arg->convspec));
        break;
    case LM_CHAR :
        fox_putuint_base(arg->argvalue.uc, _hex_base_(arg->convspec));
        break;
    case LM_SHORT :
        fox_putuint_base(arg->argvalue.uh, _hex_base_(arg->convspec));
        break;
    case LM_LONG :
    case LM_ULONG :
        fox_putullong_base(arg->argvalue.ul, _hex_base_(arg->convspec));
        break;
    case LM_LLONG :
        fox_putullong_base(arg->argvalue.ull, _hex_base_(arg->convspec));
        break;
    }
}

static __attribute__ ((nonnull))
void print_unsigned_small(farg_t const * const arg)
{
    switch (arg->lenmodif) {
    case LM_CHAR :
        fox_putuint(arg->argvalue.uc);
        break;
    case LM_SHORT :
        fox_putuint(arg->argvalue.uh);
        break;
    default :
        fox_putuint(arg->argvalue.ui);
        break;
    }
}

inline __attribute__ ((nonnull))
void print_unsigned(farg_t const * const arg)
{
    if (arg->convspec != CS_UINT)
        if (arg->convspec == CS_BIN)
            print_bin(arg);
        else if (arg->convspec == CS_OCT)
            print_oct(arg);
        else
            print_hex(arg);
    else
        if (arg->lenmodif <= LM_SHORT)
           print_unsigned_small(arg);
        else if (arg->lenmodif == LM_LONG || arg->lenmodif == LM_ULONG)
            fox_putullong(arg->argvalue.ul);
        else
            fox_putullong(arg->argvalue.ull);
}