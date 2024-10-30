/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:11:07 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/23 18:19:52 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;

	if ((char *)dest == NULL && (char *)src == NULL)
		return ((char *)dest);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return ((char *)dest);
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
