/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:19:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/16 17:47:38 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
	return ;
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
