/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:03:23 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/16 17:15:53 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned int	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	while (src[i])
		i++;
	return (i);
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
