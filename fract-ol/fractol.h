/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:06:06 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/09 17:23:15 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int	bits_per_pxl;
	int	line_len;
	int	endian;
}		t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
}		t_mlx;

typedef struct	s_set
{
	double		re_min;
	double		re_max;
	double		im_min;
	double		im_max;
	double		c_re;
	double		c_im;
	double		z_re;
	double		z_im;
	double		z_re2;
	double		z_im2;
	unsigned int	x;
	unsigned int	y;
}		t_set;

# define W_W 1280
# define W_H 720

# ifndef MAX_IT
#  define MAX_IT 32
# endif
# ifndef COLOR1
#  define COLOR1 "FF0000"
# endif
# ifndef COLOR2
#  define COLOR2 "FFFFFF"
# endif
# ifndef COLOR3
#  define COLOR3 "000000"
# endif

int	handle_no_event(void *data);
int	pointer_hook(int x, int y);
int	close_esc_hook(int key_sym, t_mlx *mlx);
int	zoom_hook(int button);
int	close_cross_hook(t_mlx *mlx);

int	is_valid_set(char *set);
int	ft_strcmp(char *s1, char *s2);

#endif
