/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:26:38 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/11 11:35:23 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;

	arr = (char *)malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;

	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	i = -1;
	while (s2[++i])
		s[ft_strlen(s1) + i] = s2[i];
	s[ft_strlen(s1) + i] = '\0';
	return (s);
}
