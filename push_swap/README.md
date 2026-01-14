# push_swap - Project_05

## 📝 Overview

The **push_swap** project is a highly efficient algorithm project that challenges you to sort a stack of integers using a limited set of instructions and a secondary stack. The goal is to produce the **smallest sequence of operations** possible to achieve a perfectly sorted stack.

This project introduces you to sorting algorithms, complexity analysis (**Big O notation** - Time and Space ones), and linked list or array manipulation. It requires choosing and implementing the most optimized strategy (such as Radix sort, Turk sort, Mechanical sort ...) to meet the strict efficiency requirements of the 42 school evaluation.

For this one, I chose to implement the Turk sort algorithm by following this guide : [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

---

## 📥 Installation

Clone the repository and navigate to the project folder :

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd push_swap
```

Then you must clone a visualizer (optional but recommended), build the inner project and return to your working directory :

```bash
   git clone https://github.com/o-reo/push_swap_visualizer.git push_swap_visualizer
   cd push_swap_visualizer
   mkdir build && cd build
   cmake ..
   make
   cd ../..
```

Now you can run the visualizer by entering this command :

```bash
   ./push_swap_visualizer/build/bin/visualizer
```

## Building the Project

<table data-path-to-node="12"><thead><tr><td><span data-path-to-node="12,0,0,0">Command</span></td><td><span data-path-to-node="12,0,1,0">Description</span></td></tr></thead><tbody><tr><td><span data-path-to-node="12,1,0,0"><code data-path-to-node="12,1,0,0" data-index-in-node="0">make</code></span></td><td><span data-path-to-node="12,1,1,0">Compiles mandatory functions and creates <code data-path-to-node="12,1,1,0" data-index-in-node="41">push_swap</code>. <b data-path-to-node="12,1,1,0" data-index-in-node="56">!MANDATORY!</b></span></td></tr><tr><td><span data-path-to-node="12,2,0,0"><code data-path-to-node="12,2,0,0" data-index-in-node="0">make clean</code></span></td><td><span data-path-to-node="12,2,1,0">Removes object files (<code data-path-to-node="12,2,1,0" data-index-in-node="22">.o</code>).</span></td></tr><tr><td><span data-path-to-node="12,3,0,0"><code data-path-to-node="12,3,0,0" data-index-in-node="0">make fclean</code></span></td><td><span data-path-to-node="12,3,1,0">Removes object files and the static library (<code data-path-to-node="12,3,1,0" data-index-in-node="45">.a</code>).</span></td></tr><tr><td><span data-path-to-node="12,4,0,0"><code data-path-to-node="12,4,0,0" data-index-in-node="0">make re</code></span></td><td><span data-path-to-node="12,4,1,0">Recompiles the entire library from scratch.</span></td></tr></tbody></table>

## 🚀 Usage & Compilation

### 1. To use the library in your own program

The main.c file is given for this project and already built after run make.

### 2. Run the programm & Check for Memory Leaks

To ensure your functions (like ft_strdup or ft_calloc) handle memory correctly without leaks, run with Valgrind:

```bash
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes] ./push_swap 2 1 3 6 5 8
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes] ARG="4 67 3 87 23"; ./push_swap $ARG
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

### 3. Give the correct path to our push_swap executive file

Once your visualizer is open, you will be able to setup the same metrics as follow :

**values to generate** : < 1000 (to avoid lags)
**shuffle** : click on it
**push_swap file path** : ../../../push_swap **!IMPORTANT!**
**compute** : click on it, must show OK

### 4. Available Operations Meaning

The algorithm uses two stacks, **Stack A** and **Stack B**, with the following operations:

**sa, sb, ss** : Swap the first 2 elements (ss - both at same time).
**pa, pb** : Push an element from one stack to another.
**ra, rb, rr** : Rotate all elements up by 1 (rr - both).
**rra, rrb, rrr** : Reverse rotate all elements down by 1 (rrr - both).

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
