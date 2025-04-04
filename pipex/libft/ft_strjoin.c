/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:45:55 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/14 20:12:28 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	i = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[ft_strlen(s1) + i] = (char)s2[i];
		i++;
	}
	str[ft_strlen(s1) + i] = '\0';
	return (str);
}
