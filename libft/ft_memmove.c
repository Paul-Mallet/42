/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:37 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/23 18:33:04 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (dest <= src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = ft_strlen(src) - 1; //n?
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	return (dest);
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("original str: %s\n", av[1]);

		memmove(av[1] + 10, av[1], ft_strlen(av[1]));
		printf("memmove overlap: %s\n", av[1]);

		ft_memmove(av[1] + 10, av[1], ft_strlen(av[1]));
		printf("ft_memmove overlap: %s\n", av[1]);
	}
	else
		printf("Need valid arguments!");
	return (0);
}
*/
