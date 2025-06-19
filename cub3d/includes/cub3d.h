/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:41:16 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/19 18:44:45 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _GNU_SOURCE

// check /usr/include to see all libs
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <errno.h>

//macros
# define S_WIDTH 1280
# define S_HEIGHT 720

# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

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

// MLX handle
typedef struct s_mlx
{
	void	*mlx_co;
	void	*mlx_win;		//
	char	*name;			//screen name
}	t_mlx;

typedef struct s_img
{
	void	*img_ptr;		//?
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;
//---

typedef struct s_wall
{
	bool	is_hit;			//hit a wall(== 1)
	bool	which_side;		//0 = North/South(x), 1 = East/West(y)
}	t_wall;

typedef struct s_grid
{
	// curr map's square we're in([screen.width x screen.height]?)
	int				map_x;		//(int)grid.mapX = 0(floor, min)
	int				map_y;		//(int)grid.mapY = 719(S_HEIGHT - 1, max), if (double)player.posX = 719.99
	unsigned int	map_width;
	unsigned int	map_height;
	t_wall			wall;
}	t_grid;

//FOV, player view
typedef struct s_cam
{
	double	plane_x;		//0
	double	plane_y;		//0.66
	double	old_plane_x;	//saved state of cam.plane_x
	double	camera_x;		//=2 * x / w - 1;, [-1(left), 0(center), 1(right)]
}	t_cam;

typedef struct s_player
{
	//start pos will be full values(22, 12) based on grid
	double	pos_x;			//if (double)player.posX = 0.89(after moving on the map)
	double	pos_y;			//change after each move
	double	dir_x;			//-1, vector x coord
	double	dir_y;			//0, vector y coord
	double	old_dir_x;		//saved state of prev dir_x
	//Pythagorean Theorem = sqrt(x ^ 2 + y ^ 2) = vector length;
	double	fov;			//2 * atan(sqrt(cam.planeX ^ 2 + cam.planeY ^ 2) / sqrt(player.dirX ^ 2 + player.dirY ^ 2)) = N°
}	t_player;
//---

typedef struct s_ray
{
	double	pos_x;			//start at player.posX
	double	pos_y;			//player.posY
	double	dir_x;			//player.dirX + cam.planeX * cam.cameraX
	double	dir_y;			//player.dirY + cam.planeY * cam.cameraX
	int		step_x;			//-1, if ray.dirX < 0
	int		step_y;			//+1, if ray.dirY >= 0
	double	side_dist_x;		//(ray.posX - mapX) * deltaDistX;, if ray.dirX < 0
	double	side_dist_y;		//(mapY + 1.0 - ray.posY) * deltaDistY;, if ray.dirY >= 0
	double	delta_dist_x;		//abs(1 / ray.dirX); || INF(avoid / 0), if ray.dirX == 0
	double	delta_dist_y;		//abs(1 / ray.dirY); || INF(avoid / 0), if ray.dirY == 0
	double	perp_wall_dist;	//ray dist length
}	t_ray;

//time using gettimeofday()
typedef struct s_time
{
	//diff between 2 = how much should move player on keypress, FPS counter
	double		curr;		//curr frame, using gettimeofday(ms, us?)
	double		old;		//prev frame
	double		frame;		//time frame has taken to pop
}	t_time;
//---

typedef struct s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_draw;

typedef struct s_speed
{
	double	move;
	double	rot;
}	t_speed;

typedef struct s_data
{
	t_mlx		mlx;
	t_img		img;
	t_grid		grid;
	t_player	player;
	t_cam		cam;
	t_ray		ray;
	t_draw		draw;
	t_time		time;
	t_speed		speed;
}	t_data;

// INIT
void		init(t_data *data);

// HOOKS
int			handle_close(t_data *data);
int			handle_keys(int key_sym, t_data *data);

// UTILS
double		ft_abs(double dir);
void    	my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		my_clamped_formula(double (*formula)(double), double input);

// ERRORS
void		handle_err(char *msg, int status);

// PRINTF
void		print_data(t_data *data);

#endif