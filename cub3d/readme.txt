CUB3D Documentation

HOW TO DEV
man functions discovering(bash)
basic functions testing(main.c)
concepts(excalidraw)

STORY
wolfenstein 3d game(1rst FPS)
dooms, quake
http://users.atw.hu/wolf3d/ (read_this)

CONCEPTS
Ray-Tracing

Ray-Marching

Ray-Casting


Texturing

Maths
- how to apply formulas, have the vision to serve problem


MANDATORY
map -> *.cub

LIBRARIES

fcntl.h : open
unistd.h : close, read, write
stdlib.h : malloc, free, exit
stdio.h : printf, perror
string.h : strerror
sys/time.h : gettimeofday
math.h : ... + -lm linker flag at compile
minilibx : ...

MINILIBX
<-, -> look left / right
w, a, s, d move 4 point of view
esc, red cross clean exit
images recommended
./cub3D *.cub

Map(+ file parsing)
6 possible chars : 0, 1, N, S, E, W
surrounded by walls 1, or error
[see subject...]

laisse faire le Makefile, ajouterais mes flags / files / minilibx
main.c simple, parsing en 1er
