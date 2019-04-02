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

#endif //MWRAP_REDEF_H
