/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:06:06 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/17 00:00:49 by paul_mall        ###   ########.fr       */
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
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}		t_set;

# define WIDTH 800
# define HEIGHT 800

# ifndef COLOR1
#  define COLOR1 "00FF00"
# endif
# ifndef COLOR2
#  define COLOR2 "FFFFFF"
# endif
# ifndef COLOR3
#  define COLOR3 "000000"
# endif

void		init(t_set *set);
void		hooks(t_set *set);
void		render(t_set *set);

int			handle_close(t_set *set);
int			handle_keys(int key_sym, t_set *set);
int			handle_mouse(int button, int x, int y, t_set *set);

double		map(double uns_num,
				double n_min,
				double n_max,
				double o_min,
				double o_max); //!
t_complex	sum_complex(t_complex c1, t_complex c2);
t_complex	square_complex(t_complex c);
int			ft_hextoi(char c, char *hex);
int			ft_power(int nb, int power);
int			ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2, int n);
double		ft_atodbl(char *s);

#endif
