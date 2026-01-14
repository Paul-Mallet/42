# fract-ol - Project_04

## 📝 Overview
The **fract-ol** project is a graphical introduction to the world of fractals. The objective is to create a small software capable of generating **Mandelbrot** and **Julia** sets.

This project allows for a deeper exploration of the **MiniLibX** graphical library, the manipulation of **complex numbers**, an understanding of optimized pixel rendering, and the implementation of interactive features such as zooming, mouse movement, and keyboard input handling.

## 🔍 About Fractals

The calculation is about iterate over complex numbers, by applying this formula :

$$z_{n+1} = z_n^2 + c$$

Mandelbrot : We needs to alterate $c$ (the pixel position) and then, start with $z_0 = 0$.
Julia : We set $c$ (passed as argument) and we start with $z_0$ egal to the pixel's position.

---

## 📥 Installation

Clone the repository and navigate to the project folder :

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd fract-ol
```

Then you must clone the minilibx library on the 42 Paris official repo, build the inner project and backward to your last path working directory :

```bash
   git clone git@github.com:42paris/minilibx-linux.git minilibx-linux
   cd minilibx-linux
   make
   cd ..
```

## Building the Project

<table data-path-to-node="12"><thead><tr><td><span data-path-to-node="12,0,0,0">Command</span></td><td><span data-path-to-node="12,0,1,0">Description</span></td></tr></thead><tbody><tr><td><span data-path-to-node="12,1,0,0"><code data-path-to-node="12,1,0,0" data-index-in-node="0">make</code></span></td><td><span data-path-to-node="12,1,1,0">Compiles mandatory functions and creates <code data-path-to-node="12,1,1,0" data-index-in-node="41">fract-ol</code>. <b data-path-to-node="12,1,1,0" data-index-in-node="56">!MANDATORY!</b></span></td></tr><tr><td><span data-path-to-node="12,2,0,0"><code data-path-to-node="12,2,0,0" data-index-in-node="0">make clean</code></span></td><td><span data-path-to-node="12,2,1,0">Removes object files (<code data-path-to-node="12,2,1,0" data-index-in-node="22">.o</code>).</span></td></tr><tr><td><span data-path-to-node="12,3,0,0"><code data-path-to-node="12,3,0,0" data-index-in-node="0">make fclean</code></span></td><td><span data-path-to-node="12,3,1,0">Removes object files and the static library (<code data-path-to-node="12,3,1,0" data-index-in-node="45">.a</code>).</span></td></tr><tr><td><span data-path-to-node="12,4,0,0"><code data-path-to-node="12,4,0,0" data-index-in-node="0">make re</code></span></td><td><span data-path-to-node="12,4,1,0">Recompiles the entire library from scratch.</span></td></tr></tbody></table>

## 🚀 Usage & Compilation

### 1. To use the library in your own program

The main.c file is given for this project and already built after run make.

### 2. Run the programm & Check for Memory Leaks

To ensure your functions (like ft_strdup or ft_calloc) handle memory correctly without leaks, run with Valgrind:

```bash
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=all] ./fractol "mandelbrot"
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=all] ./fractol "julia" "000000.8" "0.156"
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

### 3. Interactive Controls

Once the window is open, you can use the following commands:

**Mouse wheel**: Zoom in / Zoom out at the cursor's position.

**Arrow keys**: Move across the complex plane.

**ESC**: Exit the program cleanly.

**Window cross**: Exit the program cleanly.

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
