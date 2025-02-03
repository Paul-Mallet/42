/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:19:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 10:53:50 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
}
/*
int	main(void)
{
	char buff[5] = "test";

	ft_bzero(buff, 2); //cast void* to int* at the begin
	//bzero(buff, 2);
	printf("%s\n", buff);
	return (0);
}
*/
