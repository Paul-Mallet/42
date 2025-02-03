/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:30:37 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/01 12:45:50 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sc;

	if (dest == NULL && src == NULL)
		return (dest);
	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (dest <= src)
	{
		while (n--)
			*dst++ = *sc++;
	}
	else
	{
		dst += n - 1;
		sc += n - 1;
		while (n--)
			*dst-- = *sc--;
	}
	return (dest);
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("original str: %s\n", av[1]);

		memmove(av[1] + 10, av[1], ft_strlen(av[1]));
		printf("memmove overlap: %s\n", av[1]);

		ft_memmove(av[1] + 10, av[1], ft_strlen(av[1]));
		printf("ft_memmove overlap: %s\n", av[1]);
	}
	else
		printf("Need valid arguments!");
	return (0);
}
*/
