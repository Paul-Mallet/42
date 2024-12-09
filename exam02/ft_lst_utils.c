/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:00:34 by paul_mall         #+#    #+#             */
/*   Updated: 2024/12/07 12:05:44 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	s = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = -1;
	while (str[++i])
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}
