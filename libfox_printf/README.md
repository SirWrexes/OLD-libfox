# libfox

### fox_printf

*A personal implementation of printf*



This is a school project I made and use regularly. It works just like printf but doesn't use any kind of dynamic memory allocation. In fact the only system call there is in this implementation is `write`.



###### Features :

- Support for all most useful length modifiers
  - hh → char
  - h → short
  - l → long
  - ll, q, L →long long
  - z → unsigned long
- Support for most common conversion specifiers
  - d, i → integer
  - u → unsigned integer
  - o, x, X → octal, lowercase and uppercase hexadecimal
  - n → current number of written bytes
  - % → literal % symbol
  - c → character
  - s → string
- Custom conversion specifiers
  - b → binary
  - S → string with non-printables written as `\[octal ASCII value]`
- Printf-like compile time warnings with `format` attribute
- Epitech C coding style



###### To do :

- UNIT TESTS !!!
- Add flag support
- Add extensive exception handling OR find a way to add custom behaviour for `format` attribute
- Add floating point conversion specifiers
- More custom conversion specifiers :
  - %m : prints strrerror (need to find a way to get the string directly instead of using a standard lib function)
  - Maybe more to come


###### Versions
- 1.0
  - Initial commit
- 1.0.1
  - Added pointer conversion specifiers
  - Added versions to README