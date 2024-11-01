/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:48:08 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:26:28 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	if (size > dst_len)
	{
		while (src[i] && i < (size - dst_len - 1))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (dst_len + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
/*
int	main(void)
{
	char	dest[50] = "test"; //4
	char	src[] = " de test"; //8

	printf("%zu\n", ft_strlcat(dest, src, 0));
	//printf("%zu\n", strlcat(dest, src, 0));
	printf("%s\n", dest);
	return (0);
}
*/
