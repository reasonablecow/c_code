# c_code

C code examples.

## References

* [C reference (cppreference.com)](https://en.cppreference.com/w/c)
* [The C Programming Language, 2nd Edition by Brian W. Kernighan and Dennis M. Ritchie](https://www.amazon.com/exec/obidos/ASIN/0131103628/)
* [Linux kernel coding style by Linus Torvalds](https://github.com/torvalds/linux/blob/master/Documentation/process/coding-style.rst)
* [Modern C by Jens Gustedt](https://hal.inria.fr/hal-02383654/document)
* [How I program C by Eskil Steenberg](https://youtu.be/443UNeGrFoM)
* [GCC 3.8 Options to Request or Suppress Warnings](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
* [OpenMP Specifications](https://www.openmp.org/specifications/)

## Getting Started

```sh
# Compile
gcc -Wall -Wextra -pedantic -g code.c

# Run
./a.out
echo $?

# Debug
gdb a.out

# Check memory
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind.txt ./a.out
```
