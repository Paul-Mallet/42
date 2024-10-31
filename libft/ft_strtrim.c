/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:59 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:32:46 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		low;
	int		high;

	low = 0;
	while (ft_is_set(s1[low], set))
		low++;
	high = ft_strlen(s1) - 1;
	while (ft_is_set(s1[high], set))
		high--;
	trim = ft_substr(s1, low, (high - low) + 1);
	return (trim);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_strtrim(av[1], av[2]));
	else
		printf("Need valid arguments!");
	return (0);
}
*/
