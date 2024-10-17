/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:11:07 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/17 19:06:51 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*sc;

	i = 0;
	dst = (char *)dest;
	sc = (char *)src;
	if (ft_strlen(dest) < n)
	{
		while (sc[i]) //i < n
		{
			dst[i] = (char)sc[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}

int	main(void)
{
	char	dest1[50] = "test"; //4
	char	dest2[50] = "test"; //4
	char	*src = "okok"; //4

	printf("before: %s\n", dest1);
	ft_memcpy(dest1, src, 5 * sizeof(char));
	printf("after: %s\n", dest1);

	printf("before: %s\n", dest2);
	memcpy(dest2, src, 5 * sizeof(char)); //overwrite || end at src[i] = '\0'
	printf("after: %s\n", dest2);
	return (0);
}
