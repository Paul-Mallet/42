/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:55:20 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/21 22:32:17 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	sign;

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
			handle_error(ERROR_MSG);
		res += (*s++ - 48);
		if ((res * sign) < -2147483648 || (res * sign) > INT_MAX)
			handle_error(ERROR_MSG);
	}
	return (0);
}

int	is_duplicate(t_stack *stk, int n)
{
	int	i;

	if (!stk->arr[0])
		return (0);
	i = 0;
	while (i < stk->len) //cond jump arr[0], check with 0!, i < stl->len
	{
		if (stk->arr[i] == n)
			handle_error(ERROR_MSG);
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
