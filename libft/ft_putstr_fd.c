/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:38:42 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:22:22 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
		ft_putstr_fd(av[1], ft_atoi(av[2]));
	else
		printf("Must have 2 valid arguments!");
	return (0);
}
*/
