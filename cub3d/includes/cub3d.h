/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:41:16 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/26 12:59:30 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _GNU_SOURCE

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <inttypes.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <errno.h>

//macros
# define S_WIDTH	640
# define S_HEIGHT	480

// wall, ceil, floor textures and resolutions
# define TEX_NUM	8 //change with 3
# define TEX_WIDTH	64
# define TEX_HEIGHT	64

# define MAP_WIDTH	24
# define MAP_HEIGHT	24

# define X_STR		4
# define Y_STR		4

# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define BLACK		0x000000
# define WHITE		0xFFFFFF

//global vars(not allowed)
extern int	world_map[MAP_WIDTH][MAP_HEIGHT];

//enums
typedef enum e_err
{
	SUCCESS, // 0
	// lib functions
	MALLOC,
	// syst calls
	OPEN,
	CLOSE,
	READ,
	WRITE,
	TIME,
	// mlx
	INIT,
	WINDOW,
	IMAGE,
	// Math.h
	IS_HUGE_VAL,
	IS_INFINITY,
	IS_NAN,
	//...
}	t_err;

typedef struct s_mlx
{
	void	*mlx_co;
	void	*mlx_win;		//
	char	*name;			//screen name
}	t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_wall
{
	bool	is_hit;			//hit a wall(== 1)
	bool	which_side;		//0 = North/South(x), 1 = East/West(y)
}	t_wall;

/*
	// curr map's square we're in([screen.width x screen.height]?)
	int				map_x;		//(int)player.pos_x = 0(floor, min)
	int				map_y;		//(int)player.pos_y = 23(map_height - 1, max),
								if (double)player.posX = 22.999999
*/
typedef struct s_grid
{
	int				map_x;
	int				map_y;
	t_wall			wall;
}	t_grid;

/*
	double	camera_x;	//=2 * x / w - 1;, [-1(left), 0(center), 1(right)]
*/
typedef struct s_cam
{
	double	plane_x;		//0
	double	plane_y;		//0.66
	double	old_plane_x;	//saved state of cam.plane_x
	double	camera_x;
}	t_cam;

typedef struct s_screen
{
	//(0;0) = top-left corner
	int		x;				//x = width axe
	int		y;				//y = height axe
	char	*fps_str;			//string to put on screen
}	t_screen;

/*
	double	pos_x;	//if (double)player.posX = 0.89(after moving on the map)
	double	fov;	//2 * atan(sqrt(cam.planeX ^ 2 + cam.planeY ^ 2) /
					sqrt(player.dirX ^ 2 + player.dirY ^ 2)) = N°
*/
typedef struct s_player
{
	//start pos will be full values(22, 12) based on grid
	double	pos_x;
	double	pos_y;			//change after each move
	double	dir_x;			//-1, vector x coord
	double	dir_y;			//0, vector y coord
	double	old_dir_x;		//saved state of prev dir_x
	//Pythagorean Theorem = sqrt(x ^ 2 + y ^ 2) = vector length;
	double	fov;
}	t_player;

/*
	double	side_dist_y;	//(mapY + 1.0 - ray.posY) *
							deltaDistY;, if ray.dirY >= 0
	double	delta_dist_x;	//abs(1 / ray.dirX);
							|| INF(avoid / 0), if ray.dirX == 0
	double	delta_dist_y;	//abs(1 / ray.dirY);
							|| INF(avoid / 0), if ray.dirY == 0
*/
typedef struct s_ray
{
	double	pos_x;			//start at player.posX
	double	pos_y;			//player.posY
	double	dir_x;			//player.dirX + cam.planeX * cam.cameraX
	double	dir_y;			//player.dirY + cam.planeY * cam.cameraX
	int		step_x;			//-1, if ray.dirX < 0
	int		step_y;			//+1, if ray.dirY >= 0
	double	side_dist_x;	//(ray.posX - mapX) * deltaDistX;, if ray.dirX < 0
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;	//ray dist length
	float	dir_x_left;		//x leftmost point
	float	dir_x_right;	//x rightmost point
	float	dir_y_left;		//y ...
	float	dir_y_right;	//y ...
}	t_ray;

typedef struct s_time
{
	//diff between 2 = how much should move player on keypress, FPS counter
	double		curr;		//curr frame, using gettimeofday(ms, us?)
	double		old;		//prev frame
	double		frame;		//time frame has taken to pop
}	t_time;

/*

*/
typedef struct s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
}	t_draw;

/*

*/
typedef struct s_speed
{
	double	mov;
	double	rot;
}	t_speed;

/*

*/
typedef struct s_keys
{
	int	curr_map_x;
	int	curr_map_y;
	int	next_map_x_up;
	int	next_map_x_down;
	int	next_map_x_left;
	int	next_map_x_right;
	int	next_map_y_up;
	int	next_map_y_down;
	int	next_map_y_left;
	int	next_map_y_right;
	int	next_player_dir_x_right;
	int	next_player_dir_y_right;
	int	next_player_dir_x_left;
	int	next_player_dir_y_left;
}	t_keys;

/*

*/
typedef struct s_tex
{
	int			xorcolor;
	int			xcolor;
	int			ycolor;
	int			xycolor;
	int			tex_index;
	double		wall_x;
	int			x;
	int			y;
	int			y_tex_buff;
	double		step;
	double		pos;
	// maybe could use t_img instead
	void		*tex_img;
	char		*tex_addr;
	int			tex_bpp;
	int			tex_line_len;
	int			tex_endian;
	//---
	int			floor_x;
	int			floor_y;
	u_int32_t	color;
}	t_tex;

/*

*/
// floor / ceiling coordinates based on camera and distances
typedef struct s_floor
{
	int			pos_y;
	float		pos_z;
	float		row_dist;
	float		step_x;
	float		step_y;
	float		x;
	float		y;
	int			cell_x;
	int			cell_y;
}	t_floor;

typedef struct s_data
{
	t_mlx		mlx;
	t_img		img;
	t_grid		grid;
	t_screen	screen;
	t_player	player;
	t_cam		cam;
	t_ray		ray;
	t_draw		draw;
	t_time		time;
	t_speed		speed;
	t_keys		keys;
	t_tex		tex;
	t_floor		floor;
}	t_data;

// INIT
void		init(t_data *data);

// RENDER
void		render(t_data *data);

// HOOKS
int			handle_close(t_data *data);
int			handle_keys(int key_sym, t_data *data);

// UTILS
void		*ft_memset(void *s, int c, size_t n);
int			ft_intlen(int nb);
double		get_ticks(void);
double		ft_abs(double dir);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		my_clamped_formula(double (*formula)(double), double input);

// ERRORS
void		handle_err(char *msg, int status);

// PRINTF
void		print_data(t_data *data);

#endif