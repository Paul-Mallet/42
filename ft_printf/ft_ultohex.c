/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:47:09 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/07 11:21:04 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrhlen(unsigned long n)
{
	int	n_len;

	n_len = 1;
	while (n > 15)
	{
		n /= 16;
		n_len++;
	}
	return (n_len);
}

char	*ft_ultohex(unsigned long n)
{
	char	*s;
	int	n_len;
	int	i;

	n_len = ft_nbrhlen(n);
	s = (char *)malloc((n_len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = n_len - 1;
	while (n > 15)
	{
		s[i] = (n % 16) + 48;
		n /= 16;
		i--;
	}
	s[i] = (n % 16) + 48;
	s[n_len] = '\0';
	return (s);
}
