/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:03:39 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/21 18:10:10 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s_1;
	unsigned char	*s_2;

	i = 0;
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	while ((s_1[i] || s_2[i]) && i < n)
	{
		if (s_1[i] != s_2[i])
			return (s_1[i] - s_2[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("%d\n", ft_memcmp(av[1], av[2], ft_atoi(av[3])));
		printf("%d\n", memcmp(av[1], av[2], ft_atoi(av[3])));
	}
	return (0);
}

