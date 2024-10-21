/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:45:55 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/21 10:45:59 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;

	i = (ft_strlen(s1) + ft_strlen(s2));
	s = (char *)malloc((i + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = (char)s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s[ft_strlen(s1) + i] = (char)s2[i];
		i++;
	}
	s[ft_strlen(s1) + i] = '\0';
	return (s);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_strjoin(av[1], av[2]));
	else
		printf("Must have 2 arguments!");
	return (0);
}
*/
