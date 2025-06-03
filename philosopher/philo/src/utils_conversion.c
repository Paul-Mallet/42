/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:34:52 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/03 20:07:49 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

time_t	get_current_time_in_ms()
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("gettimeofday failed.");
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1e3L));
}

static time_t	get_elapsed_time_in_us(struct timeval start, struct timeval curr)
{
	return ((curr.tv_sec - start.tv_sec) * 1e6L + (curr.tv_usec - start.tv_usec));
}

/*
	time_t usec: microsec arg to pause
	spinlocks
*/
void	precise_usleep(time_t usec)
{
	struct timeval	tv_start;
	struct timeval	tv_curr;
	time_t			elapsed_time;
	time_t			remove_time;

	gettimeofday(&tv_start, NULL);
	gettimeofday(&tv_curr, NULL);
	elapsed_time = get_elapsed_time_in_us(tv_start, tv_curr);
	remove_time = usec - elapsed_time;
	if (remove_time > 1000)
		usleep(remove_time / 2);
	while (elapsed_time < usec)
	{
		gettimeofday(&tv_curr, NULL);
		elapsed_time = get_elapsed_time_in_us(tv_start, tv_curr);
		remove_time = usec - elapsed_time;
		if (remove_time > 1000)
			usleep(remove_time / 2);
	}
}

unsigned int	ft_atoui(const char *nptr)
{
	unsigned int	res;
	unsigned int	sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += (*nptr - 48);
		nptr++;
	}
	return (sign * res);
}
