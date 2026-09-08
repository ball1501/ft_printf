*This project has been created as part of the 42 curriculum by wngamkri.*

# ft_printf

## Description

`ft_printf` is a project from the 42 curriculum that consists of recreating the behavior of the standard C `printf()` function.

The main goal of this project is to understand variadic functions in C and to practice handling different data types and formatted output without relying on the original `printf()` implementation.

The project implements the following conversions:

* `%c` — prints a single character
* `%s` — prints a string
* `%p` — prints a pointer address in hexadecimal format
* `%d` — prints a signed decimal integer
* `%i` — prints a signed decimal integer
* `%u` — prints an unsigned decimal integer
* `%x` — prints a number in lowercase hexadecimal
* `%X` — prints a number in uppercase hexadecimal
* `%%` — prints a percent sign

The implementation uses the `write()` system call for output and handles arguments through the C `stdarg` library.

## Instructions

### Compilation

Clone the repository and enter the project directory:

```bash
git clone https://github.com/ball1501/ft_printf.git
cd ft_printf
```

Compile the library using:

```bash
make
```

This generates the `libftprintf.a` static library.

Available Makefile commands:

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Recompile the project
```

### Using the library

Include the header file in your C source:

```c
#include "ft_printf.h"
```

Then compile your program together with the library:

```bash
cc main.c -L. -lftprintf -o test
```

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s!\n", "42");
	ft_printf("Number: %d\n", 42);
	ft_printf("Hexadecimal: %x\n", 255);
	return (0);
}
```

Run the program:

```bash
./test
```

## Algorithm and Data Structure

### Format Parsing

The main algorithm of `ft_printf()` processes the format string from left to right.

For each character:

1. If the character is not `%`, it is printed directly.
2. When `%` is encountered, the next character is interpreted as a conversion specifier.
3. The corresponding argument is retrieved from the `va_list`.
4. A dedicated helper function formats and prints the value.
5. The number of characters printed is returned and accumulated.

The general flow is:

```text
ft_printf()
    |
    v
parse format string
    |
    +-- normal character ---> ft_putchar_rtn()
    |
    +-- %c -----------------> ft_putchar_rtn()
    |
    +-- %s -----------------> ft_putstr_rtn()
    |
    +-- %p -----------------> ft_putptr_rtn()
    |
    +-- %d / %i ------------> ft_putnbr_rtn()
    |
    +-- %u -----------------> ft_putunsigned_rtn()
    |
    +-- %x / %X ------------> ft_puthex_rtn()
    |
    +-- %% -----------------> ft_putchar_rtn('%')
```

### Number Conversion

Decimal and hexadecimal numbers are printed recursively.

For example, hexadecimal conversion repeatedly divides the number by the base:

```text
number
  |
  +-- number / 16
  |
  +-- number % 16 --> hexadecimal digit
```

The recursive call processes the higher-order digits first, then the remainder is printed after returning from recursion.

This allows numbers to be printed in the correct order without requiring a temporary array.

### Data Structures

The project does not require complex data structures such as linked lists, trees, or hash tables.

The main data structures used are:

* `va_list` — stores and accesses the variable number of arguments passed to `ft_printf()`.
* Character strings — used for the format string and hexadecimal lookup tables.
* Primitive integer types — used for decimal, unsigned, hexadecimal, and pointer values.

The implementation intentionally keeps the data structures simple because the problem is primarily about **format parsing, type handling, and variadic arguments**, rather than storing large amounts of data.

### Design Choices

The implementation separates each conversion into its own helper function. This provides:

* Clear separation of responsibilities
* Easier debugging and testing
* Reusable number-printing functions
* Better compliance with the 42 coding standards
* A simpler `ft_printf()` main loop

Each helper returns the number of characters it printed. `ft_printf()` adds these return values together and returns the total number of characters written, matching the behavior expected from `printf()`.

## Resources

### Documentation

* C `write()` documentation — used for writing characters and strings to standard output.
* C `stdarg.h` documentation — used to understand and implement variadic functions.
* `printf(3)` manual — used as a reference for the behavior and return value of `printf()`.
* C integer and pointer types documentation — used to understand the differences between signed, unsigned, hexadecimal, and pointer representations.

Useful commands for accessing the manuals on Unix-like systems:

```bash
man 2 write
man 3 printf
man stdarg
```

### Learning Resources

* The 42 ft_printf subject — the primary specification and requirements for the project.
* C documentation and manual pages — used to verify function behavior and data types.
* Standard C references and tutorials — used to better understand variadic arguments, recursion, and number representation.

### AI Usage

AI tools were used as a learning and debugging aid during the development of this project.

They were used for tasks such as:

* Explaining C concepts that were unclear during implementation.
* Helping understand how variadic functions and `va_list` work.
* Analyzing compiler errors and tester failures.
* Reviewing implementation logic and identifying potential edge cases.
* Explaining why particular implementations behaved incorrectly.
* Suggesting ways to simplify or improve code while keeping the implementation understandable.

The project code was implemented and reviewed by the student. AI was used as a supplementary learning and debugging tool rather than as a replacement for understanding or implementing the project.

## Testing

The implementation can be tested by comparing its output and return values with the standard `printf()` function.

Example:

```c
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_printf("Hello %s %d %x\n", "42", 42, 42);
	ret2 = printf("Hello %s %d %x\n", "42", 42, 42);

	printf("ft_printf return: %d\n", ret1);
	printf("printf return:    %d\n", ret2);

	return (0);
}
```

Testing should include different argument types, empty strings, zero values, negative numbers, large unsigned integers, hexadecimal values, and pointer addresses.

## Project Structure

A typical project structure is:

```text
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_printf_char.c
├── ft_printf_hex.c
├── ft_printf_nbr.c
└── ...
```

The exact files may vary depending on the implementation.

## Author

**wngamkri**

42 Student
