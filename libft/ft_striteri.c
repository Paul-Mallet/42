/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:39:04 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/21 10:44:03 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
/*
static char	ft_to_upper(unsigned int i, char *s)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char			*str;
	unsigned int	i;

	i = ft_strlen(s);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(i, &s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_strmapi(av[1], ft_to_upper));
	else
		printf("Must have 1 valid argument!");
	return (0);
}
*/
