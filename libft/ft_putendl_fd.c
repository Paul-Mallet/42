/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:34:31 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:21:29 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
		ft_putendl_fd(av[1], ft_atoi(av[2]));
	else
		printf("Must have 2 valid arguments!");
	return (0);
}
*/
