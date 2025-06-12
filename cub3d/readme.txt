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

ERROR HANDLING
- functions of math.h
HUGE_VAL(double | isinf)
INFINITY(double | isinf)
NAN(double | isnan)

- syst calls & I/O functions
open() return (non-neg int |-1 + set errno);
close() return (0 | -1 + set errno);
read() return (nb bytes read | -1 + set errno);
write() return (nb bytes written | -1 + set errno);
printf() return (nb char printed after joining all values + excluding last \0 | neg value);
gettimeofday() return (0 | -1 + set errno);

errno.h : EDOM math arg out of domain of function
int errno; global var with ext linkage(syst lib file, accessible from *.c files, only 1 def, 1 mem location)
extern int errno;

perror, strerror

- lib-based functions
malloc() return (void * | NULL);
free() return (void);
