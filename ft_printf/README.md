# ft_printf - Project_01

## 📝 Overview

The ft_printf project is a key milestone in the 42 curriculum. The goal is to mimic the behavior of the standard C printf function. This project introduces a fundamental concept in C programming: **Variadic Functions**.

By re-coding this function, you learn how to handle a variable number of **arguments** and how to parse format strings to display various data types efficiently.

---

## 📥 Installation

Clone the repository and navigate to the project folder:

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd ft_printf
```

## Building the Library

The project includes a Makefile to automate the compilation process.

<table data-path-to-node="12"><thead><tr><td><span data-path-to-node="12,0,0,0">Command</span></td><td><span data-path-to-node="12,0,1,0">Description</span></td></tr></thead><tbody><tr><td><span data-path-to-node="12,1,0,0"><code data-path-to-node="12,1,0,0" data-index-in-node="0">make</code></span></td><td><span data-path-to-node="12,1,1,0">Compiles mandatory functions and creates <code data-path-to-node="12,1,1,0" data-index-in-node="41">libftprintf.a</code>. <b data-path-to-node="12,1,1,0" data-index-in-node="56">!MANDATORY!</b></span></td></tr><tr><td><span data-path-to-node="12,2,0,0"><code data-path-to-node="12,2,0,0" data-index-in-node="0">make clean</code></span></td><td><span data-path-to-node="12,2,1,0">Removes object files (<code data-path-to-node="12,2,1,0" data-index-in-node="22">.o</code>).</span></td></tr><tr><td><span data-path-to-node="12,3,0,0"><code data-path-to-node="12,3,0,0" data-index-in-node="0">make fclean</code></span></td><td><span data-path-to-node="12,3,1,0">Removes object files and the static library (<code data-path-to-node="12,3,1,0" data-index-in-node="45">.a</code>).</span></td></tr><tr><td><span data-path-to-node="12,4,0,0"><code data-path-to-node="12,4,0,0" data-index-in-node="0">make re</code></span></td><td><span data-path-to-node="12,4,1,0">Recompiles the entire library from scratch.</span></td></tr></tbody></table>

## 🚀 Usage & Compilation

### 1. Supported Conversions

Your ft_printf should handle the following conversions:
<code data-path-to-node="17,4,0" data-index-in-node="0">%c</code> Prints a single character.
<code data-path-to-node="17,4,0" data-index-in-node="0">%s</code> Prints a string.
<code data-path-to-node="17,4,0" data-index-in-node="0">%p</code> Prints a void * pointer argument in hexadecimal format.
<code data-path-to-node="17,4,0" data-index-in-node="0">%d</code> / <code data-path-to-node="17,4,0" data-index-in-node="0">%i</code> Prints a decimal (base 10) number.
<code data-path-to-node="17,4,0" data-index-in-node="0">%u</code> Prints an unsigned decimal (base 10) number.
<code data-path-to-node="17,4,0" data-index-in-node="0">%x</code> Prints a number in hexadecimal (base 16) lowercase format.
<code data-path-to-node="17,4,0" data-index-in-node="0">%X</code> Prints a number in hexadecimal (base 16) uppercase format.
<code data-path-to-node="17,4,0" data-index-in-node="0">%%</code> Prints a percent sign.

### 2. To use the library in your own program

```c
   #include "ft_printf.h"
   #include <stdio.h> // to compare with the real function

   int main(void)
   {
      ft_printf("Hello %s, the answer is %d\n", "42", 42);
      printf("Hello %s, the answer is %d\n", "42", 42);
      return (0);
   }
```

### 3. Link the library to your code

```bash
   gcc -g main.c -L. -lftprintf -o ft_printf
```

### 4. Run the programm & Check for Memory Leaks

To ensure your functions (like ft_strdup or ft_calloc) handle memory correctly without leaks, run with Valgrind:

```bash
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes] ./ft_printf ["42"]
```

If you see those kind of lines at the end of the runtime:

```bash
HEAP SUMMARY:
==172076==     in use at exit: 0 bytes in 0 blocks
==172076==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==172076== 
==172076== All heap blocks were freed -- no leaks are possible
```

It means the programm ran properly without leaks, well done !

## 🔍 Installing Valgrind

Valgrind is an instrumentation framework for building dynamic analysis tools. It is essential for detecting memory leaks and memory management bugs.

* Linux/Windows(WSL2) :
```bash
   sudo apt update && sudo apt install -y valgrind
```

* macOS :
```bash
   brew install valgrind
```

### ⚠️ If not working !

You can directly download the latest stable version in the official website: [Valgrind Current Releases](https://valgrind.org/downloads/current.html#current)
