/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:26:38 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/04 16:44:42 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)++s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int	i;

	i = ft_strlen(str);
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int	i;

	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i++])
	{
		printf("%d\n", i);
		s[i] = s1[i];
	}
	i = 0;
	while (s2[i++])
	{
		printf("%d\n", i);
		s[ft_strlen(s1) + i] = s2[i];
	}
	s[ft_strlen(s1) + i] = '\0';
	return (s);
}
