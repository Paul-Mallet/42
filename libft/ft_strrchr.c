/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:57:01 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:32:00 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*str;

	str = (char *)s;
	i = ft_strlen(str);
	if (str[i] == (char)c)
		return (&str[i]);
	i--;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_strrchr("test", 'a'));
	printf("%s\n", strrchr("test", 'a'));
	return (0);
}
*/
