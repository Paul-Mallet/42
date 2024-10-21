/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:45:11 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/21 10:45:35 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned int	i;

	sub_s = (char *)malloc(len * sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		sub_s[i] = (char)s[start];
		start++;
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
/*
int	main(int ac, char **av)
{
	if (ac == 4 && ft_atoi(av[2]) >= 0 && ft_atoi(av[3]) >= 0)
		printf("%s\n", ft_substr(av[1], ft_atoi(av[2]), ft_atoi(av[3])));
	else
		printf("Must have 3 valid arguments!");
	return (0);
}
*/
