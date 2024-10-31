/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:45:11 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:33:16 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		sub_s = (char *)malloc(1 * sizeof(char));
		if (sub_s == NULL)
			return (NULL);
		sub_s[0] = '\0';
		return (sub_s);
	}
	i = 0;
	while (s[start + i] && i < len)
		i++;
	sub_s = (char *)malloc((i + 1) * sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub_s[i] = (char)s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
/*
int	main(int ac, char **av)
{
	if (ac == 4)
		printf("%s\n", ft_substr(av[1], ft_atoi(av[2]), ft_atoi(av[3])));
	else
		printf("Must have 3 valid arguments!");
	return (0);
}
*/
