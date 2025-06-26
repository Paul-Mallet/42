/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:38:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/26 12:48:17 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	60 = 2, 0 = 1
	Return is supposed to be always positive value
*/
int	ft_intlen(int nb)
{
	int	len;

	len = 1;
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
		str[i++] = ch;
	return (str);
}

// return time in milliseconds
double	get_ticks(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday failed");
		return (EXIT_FAILURE);
	}
	return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
}

double	ft_abs(double dir)
{
	if (dir < 0)
		return (dir * -1);
	return (dir);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

double	my_clamped_formula(double (*formula)(double), double input)
{
	double	res;

	if (input > 1)
		input = 1.0;
	if (input < 1)
		input = -1.0;
	res = formula(input);
	return (res);
}
