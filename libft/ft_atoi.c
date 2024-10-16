/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:12:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/16 12:30:49 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(int *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += (*nptr - 48);
		nptr++;
	}
	return (sign * res);
}

int	main(void)
{
	printf("%d\n", ft_atoi("   -1234pld"));
	printf("%d\n", atoi("   -1234pld"));
	return (0);
}
