/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:58:59 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/30 15:03:05 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf; //static, 1 + 1 +...
	int			size;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));

	size = read(fd, buf, BUFFER_SIZE); //13
	buf[size] = '\0';

	return (buf);
}

int	main(void)
{
	int		fd;
	int		cl;
	char	*line;

	fd = open("line.txt", O_RDONLY);
	if (fd >= 0)
		printf("Fd opened: %d\n", fd);

	while (get_next_line(fd) != NULL)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
	cl = close(fd);
	if (cl >= 0)
		printf("Fd closed: %d\n", cl);
	return (0);
}
