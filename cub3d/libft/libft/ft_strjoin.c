/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:05:24 by ebroudic          #+#    #+#             */
/*   Updated: 2025/02/20 12:40:01 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dsa;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	dsa = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dsa == NULL)
		return (NULL);
	ft_strcpy(dsa, (char *)s1);
	ft_strcpy(dsa + ft_strlen(s1), (char *)s2);
	return (dsa);
}
/* int main()
{
	printf("%s\n",ft_strjoin("hello"," world"));
	return (0);
} */