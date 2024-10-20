/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:04:21 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/21 15:18:47 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	unsigned char	i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(int ac, char **av)
{
	unsigned char	*res;

	if (ac == 2)
	{
		res = (unsigned char *)ft_memchr(av[1], 'e', 2 * sizeof(char));
		//res = (unsigned char *)memchr(av[1], 'e', 2 * sizeof(char));
		printf("res: %s\nres - str: %ld\n", res, res - (unsigned char *)av[1]);
	}
	return (0);
}
*/
