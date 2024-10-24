/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:03:23 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/24 09:56:09 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (i < size)
		dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%ld\n", ft_strlcpy(av[1], av[2], ft_atoi(av[3])));
		//printf("%ld\n", strlcpy(av[1], av[2], ft_atoi(av[3])));
		printf("%s\n", av[1]);
	}
	else
		printf("Need valid arguments!");
	return (0);
}
*/
