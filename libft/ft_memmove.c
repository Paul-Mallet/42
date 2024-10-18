/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:37 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/18 17:26:28 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*dst;
	unsigned char	*sc;

	i = ft_strlen(src) - 1; //17
	printf("i: %zu\n", i);
	j = 0;
	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	while (i >= 0 && j < n)
	{
		dst[i] = (unsigned char)sc[i];
		i--;
		j++;
	}
	return (dst);
}

int	main(void)
{
	char str[100] = "Learningisfun";
	char *first, *second, *three;
	first = str;
	second = str;
	three = str;
	printf("original str: %s\n", str);

	// when overlap happens then it just ignore it
	memcpy(first + 8, first, 10);
	printf("memcpy overlap: %s\n", str);

	// when overlap it start from first position
	memmove(second + 8, first, 10);
	printf("memmove overlap: %s\n", str);

	printf("one: %s, second: %s, three: %s\n", first, second, three);
	ft_memmove(three + 8, first, 10);
	printf("ft_memmove overlap: %s\n", str);
	return (0);
}
