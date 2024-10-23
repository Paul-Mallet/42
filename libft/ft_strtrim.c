/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:39:51 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/21 10:40:32 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_is_set(char const *set, char const c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	low;
	size_t	high;
	size_t	i;

	low = 0;
	while (ft_is_set(set, s1[low]) && s1[low])
		low++;
	if (s1[low] == '\0')
		return ((char *)s1);
	high = ft_strlen(s1) - 1;
	while (ft_is_set(set, s1[high]))
		high--;
	trim = (char *)malloc((((high + 1) - low) + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (low <= high)
	{
		trim[i] = (char)s1[low];
		low++;
		i++;
	}
	trim[i] = '\0';
	return (trim);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_strtrim(av[1], av[2]));
	else
		printf("Must have 2 arguments!");
	return (0);
}
