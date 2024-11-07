/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:34:17 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/07 11:55:47 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
		ft_putchar_fd(av[1][0], ft_atoi(av[2]));
	else
		printf("Must have 2 valid arguments!");
	return (0);
}
*/
