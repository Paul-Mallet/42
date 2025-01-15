/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:06:06 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/15 16:46:05 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800

# define OUT_VALUE 4

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}		t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}		t_mlx;

typedef struct	s_complex
{
	double	x; //re
	double	y; //im
}		t_complex;

typedef struct	s_fractal
{
	char	*name;
	int	iterations; //30, 200, 400(julia)
	double	shift_x;
	double	shift_y;
	double	zoom;
}		t_fractal;

void	handle_hooks(t_mlx *mlx, t_fractal *fractal);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atodbl(char *str);

#endif
