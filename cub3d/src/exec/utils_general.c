/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:47:29 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/29 18:53:20 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	free_map_int(t_data *data)
{
	int	y;

	y = -1;
	while (++y < data->parsing.map_line_number)
		free(data->parsing.map_int[y]);
	free(data->parsing.map_int);
}

double	ft_abs(double dir)
{
	if (dir < 0)
		return (dir * -1);
	return (dir);
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
