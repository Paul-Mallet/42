/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:33:53 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:01:41 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	n_len;

	n_len = 1;
	if (n < 0)
		n_len++;
	while (n < -9 || n > 9)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

static char	*ft_handle_min_int(char *s, int n, unsigned int n_len)
{
	unsigned int	i;

	s[0] = '-';
	s[n_len - 1] = '8';
	n /= 10;
	n *= -1;
	i = n_len - 2;
	while (n != 0)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	s[n_len] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	n_len;
	unsigned int	i;

	n_len = ft_nbrlen(n);
	s = (char *)malloc((n_len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = n_len - 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_handle_min_int(s, n, n_len));
		s[0] = '-';
		n *= -1;
	}
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
/*
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_itoa(ft_atoi(av[1])));
	else
		printf("Must have 1 valid argument!");
	return (0);
}
*/
