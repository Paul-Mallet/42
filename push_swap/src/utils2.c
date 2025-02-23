/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:55:20 by paul_mall         #+#    #+#             */
/*   Updated: 2025/02/22 14:21:06 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		arr[i++] = '\0';
	return (arr);
}

int	is_overflow(char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res *= 10;
		if ((res * sign) < -2147483648 || (res * sign) > INT_MAX)
			return (1);
		res += (*s++ - 48);
		if ((res * sign) < -2147483648 || (res * sign) > INT_MAX)
			return (1);
	}
	return (0);
}

int	is_duplicate(t_stack *stk, int k, int n)
{
	int	i;

	if (k == 0)
		return (0);
	i = 0;
	while (i < k)
	{
		if (stk->arr[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *s)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = (res * 10) + (*s++ - 48);
	return (res * sign);
}
