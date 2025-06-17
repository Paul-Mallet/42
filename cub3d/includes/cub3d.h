/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:41:16 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/16 17:58:11 by pamallet         ###   ########.fr       */
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
# include <limits.h>
# include <float.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <errno.h>

//macros, enums, structs, functions...

# define S_WIDTH 1280
# define S_HEIGHT 720

typedef enum e_err
{
	SUCCESS, // 0
	MALLOC, // MLX too
	// syst calls
	OPEN,
	CLOSE,
	READ,
	WRITE,
	TIME,
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
	void	*mlx_win;
	char	*name;
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
	bool	isHit;			//hit a wall(== 1)
	bool	whichSide;		//0 = North/South(x), 1 = East/West(y)
}	t_wall;

typedef struct s_grid
{
	// curr map's square we're in([screen.width x screen.height]?)
	int			mapX;		//(int)grid.mapX = 0(floor, min)
	int			mapY;		//(int)grid.mapY = 719(S_HEIGHT - 1, max), if (double)player.posX = 719.99
	t_wall		wall;
}	t_grid;

//FOV, player view
typedef struct s_cam
{
	double	planeX;			//0
	double	planeY;			//0.66
	double	cameraX;		//=2 * x / w - 1;, [-1(left), 0(center), 1(right)]
	double	width; 			//= S_WIDTH
}	t_cam;

typedef struct s_player
{
	//start pos will be full double(22, 12)
	double	posX;			//if (double)player.posX = 0.89(after moving on the map)
	double	posY;			//...
	double	dirX;			//-1, vector x coord
	double	dirY;			//0, vector y coord
	//Pythagorean Theorem = sqrt(x ^ 2 + y ^ 2) = vector length;
	double	fov;			//2 * atan(sqrt(cam.planeX ^ 2 + cam.planeY ^ 2) / sqrt(player.dirX ^ 2 + player.dirY ^ 2)) = N°
}	t_player;
//---

typedef struct s_ray
{
	double	posX;			//start at player.posX
	double	posY;			//player.posY
	double	dirX;			//player.dirX + cam.planeX * cam.cameraX
	double	dirY;			//player.dirY + cam.planeY * cam.cameraX
	int		stepX;			//-1, if ray.dirX < 0
	int		stepY;			//+1, if ray.dirY >= 0
	double	sideDistX;		//(ray.posX - mapX) * deltaDistX;, if ray.dirX < 0
	double	sideDistY;		//(mapY + 1.0 - ray.posY) * deltaDistY;, if ray.dirY >= 0
	double	deltaDistX;		//abs(1 / ray.dirX); || INF(avoid / 0), if ray.dirX == 0
	double	deltaDistY;		//abs(1 / ray.dirY); || INF(avoid / 0), if ray.dirY == 0
	double	perpWallDist;	//ray dist length
}	t_ray;

typedef struct s_vect
{
	t_player	player;
	t_cam		cam;
	t_ray		ray;
}	t_vect;

//full pixels image drawn(1280x720)
typedef struct s_frame
{
	//diff between 2 = how much should move player on keypress, FPS counter
	double		time;		//curr frame, using gettimeofday(ms, us?)
	double		oldTime;	//prev frame
}	t_frame;
//---

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
	t_grid	grid;
	t_vect	vect;
	t_frame	frame;
}	t_data;

#endif