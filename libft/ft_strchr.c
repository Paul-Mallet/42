/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:21:12 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/16 18:56:55 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%s\n", ft_strchr(av[1], av[2][0]));
		//printf("%s\n", strchr(av[1], (int)av[2][0]));
	}
	else
		printf("Need valid arguments!");
	return (0);
}
*/
