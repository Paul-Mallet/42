/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:06:06 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/17 19:04:28 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000

# ifndef CLR_1
#  define CLR_1 "00FF00"
# endif
# ifndef CLR_2
#  define CLR_2 "FFFFFF"
# endif
# ifndef CLR_3
#  define CLR_3 "000000"
# endif
# ifndef CLR_NOT_IN_SET
#  define CLR_NOT_IN_SET 0x000000
# endif
# ifndef HEXA_STR
#  define HEXA_STR "0123456789ABCDEF"
# endif

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_mlx
{
	void	*mlx_co;
	void	*mlx_win;
}		t_mlx;

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

typedef struct s_set
{
	t_mlx		mlx;
	t_img		img;
	t_complex	z;
	t_complex	c;
	char		*name;
	int			iterations;
	int			out_value;
	int			*from_to;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}		t_set;

void		init(t_set *set);
void		render(t_set *set);

int			handle_close(t_set *set);
int			handle_keys(int key_sym, t_set *set);
int			handle_mouse(int button, int x, int y, t_set *set);

void		*ft_calloc(size_t nmemb, size_t size);
void		my_mlx_pixel_put(t_set *set, int x, int y, int color);
double		resize(double unsc_n, double n_min, double n_max, double prv_max);
t_complex	sum_complex(t_complex c1, t_complex c2);
t_complex	square_complex(t_complex c);

int			ft_hextoi(char c, char *hex);
int			ft_power(int nb, int power);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
double		ft_atodbl(char *s);

#endif
