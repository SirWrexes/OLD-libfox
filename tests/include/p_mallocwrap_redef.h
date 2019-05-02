/*
** EPITECH PROJECT, 2019
** libfox_memory
** File description:
** Malloc tests preprocessor
*/

#ifndef MWRAP_REDEF_H
#define MWRAP_REDEF_H

#define real_malloc __real_malloc
#define wrap_malloc __wrap_malloc

typedef enum {
    MW_RESET,
    MW_SET,
    MW_STEP,
} mw_action_t;

static inline bool counter(mw_action_t a, ssize_t n)
{
    static ssize_t cpt = 0;
    static ssize_t break_at = -1;

    if (a == MW_STEP)
        cpt += (break_at != -1) && (cpt + 1 > cpt);
    if (a == MW_SET)
        break_at = n;
    if (a == MW_RESET) {
        cpt = 0;
        return counter(MW_SET, -1);
    }
    return break_at == -1 ||  cpt < break_at;
}

#endif //MWRAP_REDEF_H