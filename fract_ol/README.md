# fract-ol - Project_04

## 📝 Overview
Le projet **fract-ol** est une introduction graphique au monde des fractales. L'objectif est de créer un petit logiciel capable de générer des ensembles de **Mandelbrot**, **Julia**.

Ce projet permet d'approfondir la gestion de la bibliothèque graphique **MiniLibX**, de manipuler les nombres complexes, de comprendre le rendu de pixels optimisé et d'implémenter des fonctionnalités interactives comme le zoom, le déplacement à la souris et la pression des touches du clavier.

---

## 📥 Installation

Clone the repository and navigate to the project folder:

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd fract-ol
```

## Building the Project

<table data-path-to-node="12"><thead><tr><td><span data-path-to-node="12,0,0,0">Command</span></td><td><span data-path-to-node="12,0,1,0">Description</span></td></tr></thead><tbody><tr><td><span data-path-to-node="12,1,0,0"><code data-path-to-node="12,1,0,0" data-index-in-node="0">make</code></span></td><td><span data-path-to-node="12,1,1,0">Compiles mandatory functions and creates <code data-path-to-node="12,1,1,0" data-index-in-node="41">fract-ol</code>. <b data-path-to-node="12,1,1,0" data-index-in-node="56">!MANDATORY!</b></span></td></tr><tr><td><span data-path-to-node="12,2,0,0"><code data-path-to-node="12,2,0,0" data-index-in-node="0">make clean</code></span></td><td><span data-path-to-node="12,2,1,0">Removes object files (<code data-path-to-node="12,2,1,0" data-index-in-node="22">.o</code>).</span></td></tr><tr><td><span data-path-to-node="12,3,0,0"><code data-path-to-node="12,3,0,0" data-index-in-node="0">make fclean</code></span></td><td><span data-path-to-node="12,3,1,0">Removes object files and the static library (<code data-path-to-node="12,3,1,0" data-index-in-node="45">.a</code>).</span></td></tr><tr><td><span data-path-to-node="12,4,0,0"><code data-path-to-node="12,4,0,0" data-index-in-node="0">make re</code></span></td><td><span data-path-to-node="12,4,1,0">Recompiles the entire library from scratch.</span></td></tr></tbody></table>

## 🚀 Usage & Compilation

### 1. To use the library in your own program

The main.c file is given for this project.

### 2. Link & compile the project

```bash
   
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
