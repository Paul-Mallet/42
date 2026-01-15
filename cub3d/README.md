# cub3D - Project_08

## 📝 Overview

The **cub3D** project is a remarkable introduction to the world of **raycasting**. The objective is to create a dynamic 3D graphical view of a maze from a first-person perspective, inspired by the world-famous 90's game **Wolfenstein 3D**.

This project focuses on the **MiniLibX** graphical library, handling window management, images, and user events. It requires a solid understanding of mathematics (**trigonometry**), parsing complex map configuration files (.cub), and efficient pixel manipulation to render a fluid 3D environment.

## 🔍 About Raycasting

Raycasting is a technique used to render a 3D world from a 2D map. For every vertical line of the screen, the engine "casts" a ray from the player's position in a specific direction.

1. **Distance Calculation** : The ray travels until it hits a wall.

2. **Wall Height** : The distance to the wall is used to calculate how tall the vertical line should be drawn on the screen (the closer the wall, the taller the line).

3. **Texture Mapping** : By determining exactly where the ray hit the wall, we can apply specific textures (North, South, East, or West) to give the maze a realistic look.

---

## 📥 Installation

Clone the repository and navigate to the project folder :

```bash
   git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
   cd repo-name-you-want
   cd cub3d
```

Then you must clone the minilibx library on the 42 Paris official repo, build the inner project and backward to your last path working directory :

```bash
   git clone git@github.com:42paris/minilibx-linux.git minilibx-linux
   cd minilibx-linux
   make
   cd ..
```

## Building the Project

<table data-path-to-node="12"><thead><tr><td><span data-path-to-node="12,0,0,0">Command</span></td><td><span data-path-to-node="12,0,1,0">Description</span></td></tr></thead><tbody><tr><td><span data-path-to-node="12,1,0,0"><code data-path-to-node="12,1,0,0" data-index-in-node="0">make</code></span></td><td><span data-path-to-node="12,1,1,0">Compiles mandatory functions and creates <code data-path-to-node="12,1,1,0" data-index-in-node="41">cub3D</code>. <b data-path-to-node="12,1,1,0" data-index-in-node="56">!MANDATORY!</b></span></td></tr><tr><td><span data-path-to-node="12,2,0,0"><code data-path-to-node="12,2,0,0" data-index-in-node="0">make clean</code></span></td><td><span data-path-to-node="12,2,1,0">Removes object files (<code data-path-to-node="12,2,1,0" data-index-in-node="22">.o</code>).</span></td></tr><tr><td><span data-path-to-node="12,3,0,0"><code data-path-to-node="12,3,0,0" data-index-in-node="0">make fclean</code></span></td><td><span data-path-to-node="12,3,1,0">Removes object files.</span></td></tr><tr><td><span data-path-to-node="12,4,0,0"><code data-path-to-node="12,4,0,0" data-index-in-node="0">make re</code></span></td><td><span data-path-to-node="12,4,1,0">Recompiles the entire library from scratch.</span></td></tr></tbody></table>

## 🚀 Usage & Compilation

### 1. To change textures or maps configuration files

The program requires a .cub file as an argument. You can modify these files to change the environment:

* **maps/** : Contains the maze layout (using 0 for empty space, 1 for walls, and <code data-path-to-node="12,3,0,0" data-index-in-node="0">N,S,E,W</code> for player start).

* **textures/** : Path to <code data-path-to-node="12,3,0,0" data-index-in-node="0">.xpm</code> textures for the four cardinal directions.

* **Colors** : Floor and Ceiling colors defined by RGB values.

### 2. Run the programm & Check for Memory Leaks

To ensure your functions handle memory correctly without leaks, run with Valgrind:

```bash
   [valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=all] ./cub3D "maps/map.cub"
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

Once the window is open, you can use the following commands :

**<-,-> keys**: Rotate current user.

**W,A,S,D keys**: Move Up,Left,Down,Right across the map.

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
