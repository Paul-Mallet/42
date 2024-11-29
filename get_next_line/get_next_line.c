/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:58:59 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/29 16:59:09 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf; //static, 1 + 1 +...
	int	size;

	size = read(fd, buf, BUFFER_SIZE); //13
	buf[size] = '\0';
	return (buf);
}

int	main(int ac, char **av)
{
	int	fd;
	int	cl;

	fd = open("line.txt", O_RDONLY);
	if (fd >= 0)
		printf("fd = %d\n", fd);
	size = 0;
	if (ac == 2)
	{
		//while ()
			get_next_line(fd);
	}
	else
		printf("Invalid arguments!\n");
	cl = close(fd);
	if (cl >= 0)
		printf("Fd closed: %d\n", cl);
	return (0);
}
