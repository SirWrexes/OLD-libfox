___# Almost everything here is outdated.___

# Modular Makefile example
This folder contains a basic CMakeLists.txt template for Clion users like me.
It also contains my gitignore which is basically GitHub's with a few additions,
like CMake/CLion files that are not necessary, as the lib is compiled via Makefile.

Speaking of which, let's concentrate on the Makefile this folder contains.
This Makefile is made in a way that to build necessary modules, link them
to your project, clean libfox temp files \[and archives\] along with yours...
all you need to do is uncomment lines corresponding to the modules you want.
Of course I'd recommend editing the Makefile tou your tastes if needed.

## Breaking down the beast
###### I'll be guiding you through the many options at your disposition, nice and easy

#### 1. Fundamentals
  - It is *recommended* to fill the header.
  - It is *required* to add a project name.
  - It is *not recommended* to change the `SHELL` variable value, for
  [compatibility reasons](https://www.gnu.org/software/make/manual/make.html#Makefile-Basics)
  - You may choose the compiler you want.

#### 2. Project architecture
You should arrange those settings to meet your projects skeleton. Or you
could be a lazy guy (like me) and just replicate this simple architecture:
  - project root
    - include
    - src
    - tests
    - libfox git submodule

Also, if you're curious about
[`VPATH`](https://www.gnu.org/software/make/manual/html_node/General-Search.html) ...

#### 3. Module automation
As written there, all you need to activate a module is to uncomment the
corresponding `USEDMODULE` line. 

Hey hum. About that coffee... 
 
#### 4. Don't touch that
Just don't. You may observe it. Maybe larn a thing or two. But modifying
that will *surely* break the module automation. Just note that `LDFLAGS` is
set to libfoxs directory. So if you want to add your own `LDFLAGS`, be sure
be sure to use the `+=` operator.

#### 5. Custom compilation settings
`DEFINE` is for adding preprocessor definitions from Make. Can be useful
sometimes. Like that `TDEFINE = -D _TESTS_RUN_` I use to re-define `malloc()`
to a custom wrapper if I'm compiling unit tests.

Other flags you're probably familiar with.
`LDFLAGS` is where you can indicate the folder to you own libs, `LDLIBS` where
you can include them to your linkage part of the compilation.

#### 6. Test configuration
You may change/add `TLDLIBS` and `TLDFLAGS` as you wish but, as you should
have [Criterion](github.com/Snaipe/Criterion) installed for libfox unit tests
I'm pretty sure you'll keep those on.

`WR_<funcName>` is where I wrap stuff sing GCC's wrap extension. [Here's why
I'm wrapping malloc and you should too.](https://github.com/Snaipe/Criterion/issues/277)
Any new `WR_<funcName>` should be added to `WRAPPERS`.

#### 7. Sources
The .c file containing your main (and nothing else) should go in `MAIN`. This
is to separate it from other sources when compiling unit tests. Having a main
in a batch of Criterion UT sources just breaks it completely.
Other than that, all sources go in `SRC` or `TESTS`.
