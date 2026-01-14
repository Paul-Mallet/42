# get_next_line - Project_02

## 📝 Overview
The **get_next_line** project is a fundamental exercise that teaches you how to read content from a **file descriptor**, line by line. It introduces the crucial concept of **Static Variables** in C and deepens your understanding of memory allocation and buffer management.

The goal is to create a function that returns the next line found in a file, whether it comes from a standard input, a redirection, or a large file, without losing the reading thread.

---

## 📥 Installation

Clone the repository and navigate to the project folder:

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd get_next_line
```

## Building the Project

There was no Makefile allowed for this project.

## 🚀 Usage & Compilation

### 1. To use the library in your own program

You must include the headers in your main.c file :

```c
   #include "./get_next_line.h"
   #include <stdio.h>
   #include <fcntl.h>

   int main( void ) {
      int fd;
      char* line;

      fd = open(fd);
      while ((line = get_next_line(fd)))
      {
         printf("%s", line);
         free(line);
      }
      close(fd);
      return (0);
   }
```

### 2. Link & compile the project

```bash
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o get_next_line
```

<i>Note: The -D BUFFER_SIZE=n flag tells the compiler how many bytes to read at each read() call.</i>

### 3. Run the programm & Check for Memory Leaks

To ensure your functions (like ft_strdup or ft_calloc) handle memory correctly without leaks, run with Valgrind:

```bash
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=all] ./get_next_line "files/path_to_file_to_read.txt"
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
