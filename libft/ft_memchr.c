/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:04:21 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:09:52 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(int ac, char **av)
{
	unsigned char	*res;

	if (ac == 3)
	{
		res = (unsigned char *)ft_memchr(av[1], av[2][0], 2 * sizeof(char));
		//res = (unsigned char *)memchr(av[1], av[2][0], 2 * sizeof(char));
		printf("res: %s\nres - str: %ld\n", res, res - (unsigned char *)av[1]);
	}
	return (0);
}
*/
