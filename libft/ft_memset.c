/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:02:32 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/17 15:47:56 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
		ptr[i++] = c;
	return (ptr);
}
/*
void static	ft_printArr(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		printf("%d ", arr[i++]);
}

int	main(void)
{
	int		n = 5;
	//char	s[5] = "test";
	int		arr[n];

	//printf("before: %s\n", s);
	ft_printArr(arr, n);

	//memset(s + 4, '.', n * sizeof(char));
	//ft_memset(s + 4, '.', n * sizeof(char));
	ft_memset(arr, 1, n * sizeof(int)); //works with char too
	//ft_memset(arr, 0, n * sizeof(int));

	//printf("after: %s\n", s);
	ft_printArr(arr, n);
	return (0);
}
*/
