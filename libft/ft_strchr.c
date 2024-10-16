/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:21:12 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/16 18:56:55 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = "\0";
	if (c == '\0')
		return (str);
	i = 0;
	str = (char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_strchr("test", 's'));
	printf("%s\n", strchr("test", 's'));
	return (0);
}
*/
