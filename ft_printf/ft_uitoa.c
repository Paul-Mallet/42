/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:27:54 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/06 17:41:20 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_nbrlen(unsigned int n)
{
	int	n_len;

	n_len = 1;
	while (n > 9)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_uitoa(unsigned int n)
{
	char		*s;
	int		n_len;
	unsigned int	i;

	n_len = ft_nbrlen(n);
	s = (char *)malloc((n_len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = n_len - 1;
	while (n > 9)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	s[i] = (n % 10) + 48;
	s[n_len] = '\0';
	return (s);
}
