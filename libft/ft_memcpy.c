/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:11:07 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/18 16:15:20 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*sc;

	i = 0;
	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = (unsigned char)sc[i];
		i++;
	}
	while (sc[i])
		i++;
	dst[i] = '\0';
	return (dst);
}
/*
int	main(void)
{
	char	str[100] = "Learningisfun";
	char	*first;
	first = str;
	char	dest1[50] = "test"; //4
	char	dest2[50] = "test"; //4
	char	*src = "okokokokok"; //4

	printf("before: %s\n", dest1);
	ft_memcpy(dest1, src, 0 * sizeof(char));
	printf("after: %s\n", dest1);

	printf("before: %s\n", dest2);
	memcpy(dest2, src, 0 * sizeof(char));
	memcpy(first + 8, first, 10);
	printf("after: %s\n", dest2);
	printf("after: %s\n", first);
	return (0);
}
*/
