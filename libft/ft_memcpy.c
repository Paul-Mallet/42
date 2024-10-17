/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:11:07 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/17 16:20:18 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
/*
void	*ft_memcpy(void *dest, const void src, size_t n)
{
	//
}
*/
int	main(void)
{
	char	dest[50] = "test"; //4
	char	*src = "de test"; //7

	printf("before: %s\n", dest);
	//ft_memcpy(dest, src, 3));
	memcpy(dest, src, ); //overwrite || end at src[i] = '\0'

	printf("after: %s\n", dest);
	return (0);
}

