/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:58:59 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/03 13:30:50 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *buf)//,len?
{
	//implement strchr(), strjoin()
}

char	*read_line(int fd, char *buf)
{
	char		*line;
	ssize_t		size;

	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[size] = '\0';
	printf("%s\n", buf);
	//buf = "My\nfirst\0"[8 + 1]
	//line = "My\n"
	line = next_line(buf);//len = 3, buf = 8 + 1
	return (line); //line
}
//free buf OK, not line...
char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0) //here + B_S < 1?
		return (NULL);
	//if (buf)
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf);
	return (line);
}

int	main(int ac, char **av)
{
	int		fd;
	int		cl;
	char	*line;

	(void)ac;
	if (av[1])
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("(null)");
			break ;
		}
		printf("%s", line);
		free(line);
		line = NULL;
	}
	cl = close(fd);
	if (cl < 0)
		printf("Close error!\n");
	return (0);
}
