/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:58:59 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/30 17:21:50 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1]; //static, 1 + 1 +...
	int		size;

	size = read(fd, buf, BUFFER_SIZE); //13
	printf("size: %d\n", size);
	buf[size] = '\0';

	return (buf);
}

int	main(void)
{
	int	fd;
	int	cl;
	char	*line;

	fd = open("line.txt", O_RDONLY);
	if (fd >= 0)
		printf("Fd opened: %d\n", fd);

	while (get_next_line(fd))
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	//free(line);
	}
	cl = close(fd);
	if (cl >= 0)
		printf("Fd closed: %d\n", cl);
	return (0);
}
