# Pipex - Project_06

## 📝 Overview

The **pipex** project is a deep dive into UNIX mechanisms, specifically focusing on how data flows between processes. The objective is to reproduce the behavior of the shell **pipe** command: &< file1 cmd1 **|** cmd2 > file2&.

This project introduces you to fundamental **system calls** such as &pipe()&, &fork()&, &dup2()&, and &execve()&. You will learn how to manage **multiple processes**, handle standard input/output **redirection**, and search for executable binaries within the **system's PATH**=/home/user/bin:... Understanding these concepts is a crucial milestone in mastering C programming and systems administration.

---

## 📥 Installation

Clone the repository and navigate to the project folder :

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd pipex
```

## Building the Project

<table data-path-to-node="12"><thead><tr><td><span data-path-to-node="12,0,0,0">Command</span></td><td><span data-path-to-node="12,0,1,0">Description</span></td></tr></thead><tbody><tr><td><span data-path-to-node="12,1,0,0"><code data-path-to-node="12,1,0,0" data-index-in-node="0">make</code></span></td><td><span data-path-to-node="12,1,1,0">Compiles mandatory functions and creates <code data-path-to-node="12,1,1,0" data-index-in-node="41">pipex</code>. <b data-path-to-node="12,1,1,0" data-index-in-node="56">!MANDATORY!</b></span></td></tr><tr><td><span data-path-to-node="12,2,0,0"><code data-path-to-node="12,2,0,0" data-index-in-node="0">make clean</code></span></td><td><span data-path-to-node="12,2,1,0">Removes object files (<code data-path-to-node="12,2,1,0" data-index-in-node="22">.o</code>).</span></td></tr><tr><td><span data-path-to-node="12,3,0,0"><code data-path-to-node="12,3,0,0" data-index-in-node="0">make fclean</code></span></td><td><span data-path-to-node="12,3,1,0">Removes object files and the static library (<code data-path-to-node="12,3,1,0" data-index-in-node="45">.a</code>).</span></td></tr><tr><td><span data-path-to-node="12,4,0,0"><code data-path-to-node="12,4,0,0" data-index-in-node="0">make re</code></span></td><td><span data-path-to-node="12,4,1,0">Recompiles the entire library from scratch.</span></td></tr></tbody></table>

## 🚀 Usage & Compilation

### 1. To use the library in your own program

The main.c file is given for this project and already built after run make.

### 2. How to read the commands

The program must be executed with four arguments: an input file, two shell commands, and an output file.

```bash
   ./pipex infile "cmd1" "cmd2" outfile
```

This is equivalent to the following shell command :

```bash
   < infile cmd1 | cmd2 > outfile
```

### 3. Run the programm & Check for Memory Leaks

To ensure your functions (like ft_strdup or ft_calloc) handle memory correctly without leaks, run with Valgrind:

```bash
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes] ./pipex infile "cat" "grep hello" outfile
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes] ./pipex input.txt "ls -l" "wc -l" output.txt
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

### 4. Logic Breakdown

The program follows these logical steps:

**Pipe**: Create a pipe using pipe(fd).

**Fork**: Create a child process using fork().

**Redirection**: Use dup2() to swap stdin/stdout with the file descriptors of the files or the pipe.

**Execution**: Find the command path in envp and execute it using execve().

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
