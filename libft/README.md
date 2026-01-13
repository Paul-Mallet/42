# Libft - Project_00 @42

## 📝 Overview
**Libft** is the first project of the 42 School common core. The goal is to recreate a set of functions from the standard C library (`libc`) along with additional utility functions. Mastering this project is essential as this library will become a foundation for most of our future C projects at 42.

This project provides a deep dive into **memory management**, **pointer arithmetic**, and **data structure manipulation** (strings and linked lists).

---

## 📥 Installation

Clone the repository and navigate to the project folder:

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd libft
```

## Building the Library

The project includes a Makefile to automate the compilation process.

<table data-path-to-node="4"><thead><tr><td><span data-path-to-node="4,0,0,0">Command</span></td><td><span data-path-to-node="4,0,1,0">Description</span></td></tr></thead><tbody><tr><td><span data-path-to-node="4,1,0,0"><code data-path-to-node="4,1,0,0" data-index-in-node="0">make</code></span></td><td><span data-path-to-node="4,1,1,0">Compiles mandatory functions and creates <code data-path-to-node="4,1,1,0" data-index-in-node="41">libft.a</code>. !MANDATORY!</span></td></tr><tr><td><span data-path-to-node="4,2,0,0"><code data-path-to-node="4,2,0,0" data-index-in-node="0">make bonus</code></span></td><td><span data-path-to-node="4,2,1,0">Includes linked list functions in the library.</span></td></tr><tr><td><span data-path-to-node="4,3,0,0"><code data-path-to-node="4,3,0,0" data-index-in-node="0">make clean</code></span></td><td><span data-path-to-node="4,3,1,0">Removes object files (<code data-path-to-node="4,3,1,0" data-index-in-node="22">.o</code>).</span></td></tr><tr><td><span data-path-to-node="4,4,0,0"><code data-path-to-node="4,4,0,0" data-index-in-node="0">make fclean</code></span></td><td><span data-path-to-node="4,4,1,0">Removes object files and the static library (<code data-path-to-node="4,4,1,0" data-index-in-node="45">.a</code>).</span></td></tr><tr><td><span data-path-to-node="4,5,0,0"><code data-path-to-node="4,5,0,0" data-index-in-node="0">make re</code></span></td><td><span data-path-to-node="4,5,1,0">Recompiles the entire library from scratch.</span></td></tr></tbody></table>

## 🚀 Usage & Compilation

### 1. To use the library in your own program

You must include the header in your main.c file :

```c
   #include "./libft.h"

   // int main( void ) { ... }
```

### 2. Link the library to your code

```bash
   gcc -g main.c -L. -lft -o libft
```

### 3. Run the programm & Check for Memory Leaks

To ensure your functions (like ft_strdup or ft_calloc) handle memory correctly without leaks, run with Valgrind:

```bash
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes] ./libft ["42"]
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