/*
** EPITECH PROJECT, 2018
** libfox
** File description:
** Libfox macros
*/

#ifndef FOX_MACRO
#define FOX_MACRO

/*
** Following macros are sorted in alphabetical order
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
    #undef ABS
    #undef CHAR_TOUPPER
    #undef CHAR_TOLOWER
    #undef CTOI
    #undef IS_ALPHALO
    #undef IS_ALPHAUP
    #undef IS_ALPHA
    #undef IS_NUM
    #undef IS_ALPHANUM
    #undef IS_EOL
    #undef IS_OP
    #undef IS_PUNCT
    #undef IS_SIGN
    #undef ITOC
    #undef MAX
    #undef __A
#endif // LIBFOX_MACRO_UNDEF

//Then we can actually start to define them.
#ifndef LIBFOX_MACRO_DEF
    #define LIBFOX_MACRO_DEF

    //Get the absolute value of a number
    #define ABS(x) ((x) >= 0 ? (x) : -(x))

    //If an alphabetical character is lowercase, make it uppercase
    #define CHAR_TOUPPER(c)  ((c) >= 'a' && (c) <= 'z' ? (c) - 32 : (c))

    //If an alphabetical character is uppercase, make it lowercase
    #define CHAR_TOLOWER(c)  ((c) >= 'A' && (c) <= 'Z' ? (c) - 32 : (c))

    //Digit ascii value to numeric value
    #define CTOI(c) ((int) ((c) - '0'))

    //Check if a char is strictly lowercase alphabetical
    #define IS_ALPHALO(c) ((c) >= 'a' && (c) <= 'z')

    //Check if a char is strictly uppercase alphabetical
    #define IS_ALPHAUP(c) ((c) >= 'A' && (c) <= 'Z')

    //Check if a char is strictly alphabetical
    #define IS_ALPHA(c) (IS_ALPHALO(c) || IS_ALPHAUP(c))

    //Check if a char is strictly numeric
    #define IS_NUM(c) ((c) >= '0' && (c) <= '9')

    //Check if a char is strictly alphanumeric
    #define IS_ALPHANUM(c) (IS_ALPHA(c) || IS_NUM(c))

    //Check if a char is an end of line (linebreak OR null char)
    #define IS_EOL(c) ((c) == '\n' || (c) == '\0')

    //Check if a char is punctuation
    #define IS_PUNCT(c)  \
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

    //Check if a char is a sign (+ OR -)
    #define IS_SIGN(c) ((c) == '+' || (c) == '-')

    //Numeric value to ascii char value
    #define ITOC(i) ((char) ((i) + '0'))

    //Get the biggest of two numbers
    #define MAX(x, y) ((x) > (y) ? (x) : (y))

    //Shorter way of writing __attribute__
    #define __A(attributes) __attribute__(attributes)
#endif // LIBFOX_MACRO_DEF

#endif //FOX_MACRO