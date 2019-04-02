/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_include.h"
#include "test_suite_trick.h"

#define const
#define int
#define dummy(...) TestSuite(__VA_ARGS__)
const int dummy(alist, .init = init, .fini = reset_malloc_cpt);
const int dummy(aitem, .init = init, .fini = reset_malloc_cpt);
const int dummy(graph, .init = init, .fini = reset_malloc_cpt);
#undef const
#undef int

extern inline void init(void)
{
    errno = 0;
    cr_redirect_stderr();
    cr_redirect_stdout();
}
