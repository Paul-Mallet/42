/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:12:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 10:54:05 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;

	arr = (unsigned char *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
/*
int	main(int ac, char **av)
{
	char	*cpy;

	if (ac == 3)
	{
		int	i;

		cpy = (char *)ft_calloc((ft_strlen(av[1]) + 1), sizeof(char));
		printf("cpy before: %s\n", cpy);
		i = 0;
		while (av[1][i])
		{
			cpy[i] = av[1][i];
			i++;
		}
		cpy[i] = '\0';
		printf("cpy after: %s\n", cpy);
	}
	else
		printf("Need valid arguments!");
	return (0);
}
*/
