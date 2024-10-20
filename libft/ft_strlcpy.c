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

size_t	ft_strlcpy(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	while (s2[i] && i < (size - 1))
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[s1_len + i] = '\0';
	return (ft_strlen(s2));
}
/*
int	main(void)
{
	char	s1[50] = "test";
	const char	s2[] = "de test";

	printf("%zu\n", ft_strlcpy(s1, s2, 5));
	//printf("%ld\n", strlcpy(s1, s2, 5));
	printf("%s\n", s1);
	return (0);
}
*/
