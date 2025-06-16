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

# define WIDTH 1280
# define HEIGHT 720

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

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_co;
	void	*mlx_win;
	char	*name;
}	t_mlx;

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
	//grid, vectors...
}	t_data;

#endif