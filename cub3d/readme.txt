"settings, keyboard, compose key(alt + right) for accents"

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

- errno.h : EDOM math arg out of domain of function
int errno; global var with ext linkage(syst lib file, accessible from *.c files, only 1 def, 1 mem location)
extern int errno;

- perror, strerror
custom string based on enums || errno value(EACCESS = int)

- lib-based functions
malloc() return (void * | NULL);
free() return (void);

RAY-CASTING

// Init player position, vector direction, plane 
double posX; //[x, y] on the grid
double posY;

double dirX; //[X, Y]
double dirY;

double planeX; //2d vector plane
double planeY;

double time; //curr frame
double oldTime;

// Deduce the Field Of View
FOV = 2 * atan(dirVector/cameraPlane) = ?deg

// game loop starts

// Start drawing rays based on x-coordinate width of the screen
double cameraX; //[-1(left), 1(right)]
double rayDirX;
double rayDirY;
double w; //width?

while (x < w)
{
	cameraX = 2 * x / w - 1;
	rayDirX = dirX + (planeX * cameraX);
	rayDirY = dirY + (planeY * cameraX);
	x++;
}
// got every rayDirs along the screen width(x)

// --- DDA Algo(ray points on each grid square)

unsigned int mapX, mapY //curr map's square coord the ray is in

rayPosX, rayPosY //contains in which square it is && ...

sideDistX, sideDistY //distance ray needs to travel from start pos to 1rst grid x/y side encounter

deltaDistX, deltaDistY //full dist the ray has to travel to go next grid x/y side

// deriving deltaDistX/Y using Pythagoras formula
double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
// or
double deltaDistX = abs(|rayDir| / rayDirX), where rayDir = rayDirX/Y length
double deltaDistY = abs(|rayDir| / rayDirY)
// ratio 1 instead of |rayDir|, cause same
double deltaDistX = abs(1 / rayDirX) || 1e30(or INFINITY) if rayDirX/Y == 0
double deltaDistY = abs(1 / rayDirY)

double perpWallDist; // ray len

int stepX, stepY; //[-1 or 1], ray direction(x, y)

bool hit = false; //determinate whether or not coming loop may be ended
int side; //(x = 0 = NS/y = 1 = EW-side)
// ---

// --- before start DDA calculation, still calculated stepX, stepY, sideDistX and sideDistY
//calculate step and initial sideDist
if (rayDirX < 0)
{
	stepX = -1;
	sideDistX = (posX - mapX) * deltaDistX; // dist from start pos to 1rst left side
}
else
{
	stepX = 1;
	sideDistX = (mapX + 1.0 - posX) * deltaDistX;
}
if (rayDirY < 0)
{
	stepY = -1;
	sideDistY = (posY - mapY) * deltaDistY;
}
else
{
	stepY = 1;
	sideDistY = (mapY + 1.0 - posY) * deltaDistY;
}
//---
//---




#TODO
Makefile : check CFLAGS(compiler, %.o:%.c), LDFLAGS(linker, exec file)

PARSING :
like fract-ol -> no need to convert *.cub(32x32) to fit screen view, because 3D FPS!
worldMap[x][y]	-> char ** "01P..."
				-> but need (int **) cast!

RENDERING :
x, y value, where start drawing pixels?, top-left corner(0, 0)?


--TEXTURED RAYCASTING--

before
* while (i < x), where x = width
* draw vertical line
* single int color (0xFF0000)

after
* while (i < x), while (j < y), where x & y = width & height
* draw every pixel(texel)
* draw entire screen(frame), then put it on image using mlx
* convert texture files.png(mlx_png_file_to_image) into int color
* texture_width /height = 64px for 640 x 480px screen
* tex_x = 
* tex_y = float to int to select actual texture pixel
* draw y line, 1 pixel at a time
* interpolation between draw_start & draw_end of vertical line to draw
* compute step(tex_end - tex_start) / wall_height(line_height) to multiply it each iteration of y pixel
* take car of color's darker pattern, work with 24 bits int, bit shifting & AND-ing with decimal value
* drawn the buffer[x][y] = color = 1 pixel, draw entire buffer, then clear it entirely using 2 loops(y 1rst, x nested)
* strafe Left / Right keys, same as Up/Down but using planeX and planeY instead of dirX & dirY
* opti CPU cache using and avoid page misses, store in mem vertical stripe / vertical stripe instead of horizontal ones