# philosophers - Project_07

## 📝 Overview

The **Philosophers** project is a classic introduction to **concurrent programming** and the complexities of process synchronization. Based on the "Dining Philosophers Problem," the goal is to simulate a scenario where philosophers sit at a round table, doing one of three things: eating, thinking, or sleeping.

This project focuses on the fundamentals of **Threads** and **Mutexes**. You must ensure that no philosopher dies of starvation, while avoiding **deadlocks** and **race conditions**. It is an intensive exercise in memory safety and timing precision within a multi-threaded environment.

---

## 📥 Installation

Clone the repository and navigate to the project folder :

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd philosopher/philo/
```

## Building the Project

<table data-path-to-node="12"><thead><tr><td><span data-path-to-node="12,0,0,0">Command</span></td><td><span data-path-to-node="12,0,1,0">Description</span></td></tr></thead><tbody><tr><td><span data-path-to-node="12,1,0,0"><code data-path-to-node="12,1,0,0" data-index-in-node="0">make</code></span></td><td><span data-path-to-node="12,1,1,0">Compiles mandatory functions and creates <code data-path-to-node="12,1,1,0" data-index-in-node="41">philo</code>. <b data-path-to-node="12,1,1,0" data-index-in-node="56">!MANDATORY!</b></span></td></tr><tr><td><span data-path-to-node="12,2,0,0"><code data-path-to-node="12,2,0,0" data-index-in-node="0">make clean</code></span></td><td><span data-path-to-node="12,2,1,0">Removes object files (<code data-path-to-node="12,2,1,0" data-index-in-node="22">.o</code>).</span></td></tr><tr><td><span data-path-to-node="12,3,0,0"><code data-path-to-node="12,3,0,0" data-index-in-node="0">make fclean</code></span></td><td><span data-path-to-node="12,3,1,0">Removes object files and the static library (<code data-path-to-node="12,3,1,0" data-index-in-node="45">.a</code>).</span></td></tr><tr><td><span data-path-to-node="12,4,0,0"><code data-path-to-node="12,4,0,0" data-index-in-node="0">make re</code></span></td><td><span data-path-to-node="12,4,1,0">Recompiles the entire library from scratch.</span></td></tr></tbody></table>

## 🚀 Usage & Compilation

### 1. How to run the program

The program takes the following arguments: <code data-path-to-node="12,1,1,0" data-index-in-node="41">number_of_philosophers</code> <code data-path-to-node="12,1,1,0" data-index-in-node="41">time_to_die</code> <code data-path-to-node="12,1,1,0" data-index-in-node="41">time_to_eat</code> <code data-path-to-node="12,1,1,0" data-index-in-node="41">time_to_sleep</code> <code data-path-to-node="12,1,1,0" data-index-in-node="41">[number_of_times_each_philosopher_must_eat]</code>

```bash
   ./philo 5 800 200 200
```

**number_of_philosophers**: The number of philosophers and forks.

**time_to_die** (in ms): If a philosopher hasn't started eating within this time since their last meal, they die.

**time_to_eat** (in ms): The time it takes for a philosopher to eat (requires two forks).

**time_to_sleep** (in ms): The time spent sleeping.

**number_of_times_each_philosopher_must_eat** (optional): If all philosophers eat at least this many times, the simulation stops.

### 2. Run the programm & Check for Data Races

In addition to Valgrind, it is highly recommended to compile with the **Thread Sanitizer** <code data-path-to-node="12,1,1,0" data-index-in-node="41">-fsanitize=thread</code> to detect race conditions.

But because of the serialization of Valgrind, you **MUST** avoid to use them together ! (this is why I've already put in the Makefile in commentary):

So when you need to check for :
* **Memory leaks** : Valgrind with a small amount of philos (< 10)
* <code data-path-to-node="12,1,1,0" data-index-in-node="41">-fsanitize=thread</code> : To test a high amount of philos to be + precise

```bash
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=helgrind] ./philo 5 800 200 200
```

If you see those kind of lines at the end of the runtime :

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
