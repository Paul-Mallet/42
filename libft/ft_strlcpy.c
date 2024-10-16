/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:03:23 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/16 13:14:29 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//libft.h with ft_strlen

size_t	ft_strlcpy(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1); //dest: 4
	while (s2[i] && i < size) //src not null
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[s1_len + i] = '\0';
	return (ft_strlen(s2));
}

int	main(void)
{
	const char	*s1 = "test";
	const char	*s2 = "de test";

	printf("%zu\n", ft_strlcpy(s1, s2, 5));
	printf("%d\n", strlcpy(s1, s2, 5));
	return (0);
}
