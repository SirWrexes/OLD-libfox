/*
** EPITECH PROJECT, 2018
** libfox
** File description:
** Libfox macros
*/

#ifndef FOX_MACRO
#define FOX_MACRO

/*
** Following macros are sorted in contextual order
** unless they depend on another macro's previous
** definition and follow this template  :
**
**     //What purpose the macro serves
**     # define NAME (instruction)
*/

// First we need to make sure their
// name isn't already defined elsewhere
#ifndef LIBFOX_MACRO_UNDEF
    #define LIBFOX_MACRO_UNDEF
    #undef __a
    #undef __transparent
    #undef __unused
    #undef CTOI
    #undef ITOC
    #undef CHAR_PRINTABLE
    #undef CHAR_TOUPPER
    #undef CHAR_TOLOWER
    #undef IS_EOL
    #undef IS_ALPHALO
    #undef IS_ALPHAUP
    #undef IS_ALPHA
    #undef IS_NUM
    #undef IS_ALPHANUM
    #undef IS_PUNCT
    #undef IS_SIGN
    #undef IS_OP
    #undef ABS
    #undef MAX
    #undef EQ3
    #undef RETURN
#endif // LIBFOX_MACRO_UNDEF

// Then we can actually start to define them.
#ifndef LIBFOX_MACRO_DEF
    #define LIBFOX_MACRO_DEF

    // Shorter ways of writing attributes
    #define __a(attributes) __attribute__(attributes)
    #define __tranparent    __a((__transparent_union__))
    #define __unused        __a((unused))

    // Digit ascii value to numeric value
    #define CTOI(c) ((int) ((c) - '0'))

    // Numeric value to ascii char value
    #define ITOC(i) ((char) ((i) + '0'))

    // True if c is a printable ASCII char
    #define CHAR_PRINTABLE(c) ((c) >= 32 && (c) <= 176)

    // If an alphabetical character is lowercase, make it uppercase
    #define CHAR_TOUPPER(c)  ((c) >= 'a' && (c) <= 'z' ? (c) - 32 : (c))

    // If an alphabetical character is uppercase, make it lowercase
    #define CHAR_TOLOWER(c)  ((c) >= 'A' && (c) <= 'Z' ? (c) - 32 : (c))

    // Check if a char is an end of line (linebreak OR null char)
    #define IS_EOL(c) ((c) == '\n' || (c) == '\0')

    // Check if a char is strictly lowercase alphabetical
    #define IS_ALPHALO(c) ((c) >= 'a' && (c) <= 'z')

    // Check if a char is strictly uppercase alphabetical
    #define IS_ALPHAUP(c) ((c) >= 'A' && (c) <= 'Z')

    // Check if a char is strictly alphabetical
    #define IS_ALPHA(c) (IS_ALPHALO(c) || IS_ALPHAUP(c))

    // Check if a char is strictly numeric
    #define IS_NUM(c) ((c) >= '0' && (c) <= '9')

    // Check if a char is strictly alphanumeric
    #define IS_ALPHANUM(c) (IS_ALPHA(c) || IS_NUM(c))

    // Check if a char is punctuation
    #define IS_PUNCT(c)     \
    (                       \
        ((c) == '\'')       \
        || ((c) == '\"')    \
        || ((c) == ',')     \
        || ((c) == '.')     \
        || ((c) == '?')     \
        || ((c) == '!')     \
        || ((c) == ';')     \
        || ((c) == ':')     \
        || ((c) == '(')     \
        || ((c) == ')')     \
        || ((c) == '-')     \
        || ((c) == '/')     \
    )                       \

    // Check if a char is a sign (+ OR -)
    #define IS_SIGN(c) ((c) == '+' || (c) == '-')

    // Get the absolute value of a number
    #define ABS(x) ((x) >= 0 ? (x) : -(x))

    // Get the biggest of two numbers
    #define MAX(x, y) ((x) > (y) ? (x) : (y))

    // Check if 3 values are equal
    #define EQ3(x, y, z) ((x) == (y) && (y) == (z))

    // Execute a non-void function then return null no matter what
    // -- Useful when you want to log an error and return null in 1 line
    #define RETURN(value, funcs...) return (0 ? : (funcs, value))
#endif // LIBFOX_MACRO_DEF

#ifndef CCSTR_TYPE
    #define CCSTR_TYPE
    typedef char const * const * const  str4c_t;
    typedef char const * const          str3c_t;
    typedef char const *                str2c_t;
    typedef char *                      str_t;
#endif // CCSTR_TYPE

#ifndef LLONG_TYPE
    #define LLONG_TYPE
    typedef          long long llong_t;
    typedef unsigned long long ullong_t;
#endif // LLONG_TYPE

#endif // FOX_MACRO
