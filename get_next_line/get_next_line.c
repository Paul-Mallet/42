/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:58:59 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/06 11:25:36 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *line, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(line, buf); //not more than '\n'
	free(line);
	return (tmp);
}

char	*read_line(int fd, char *buf)
{
	char		*line;
	ssize_t		size;

	line = "";
	size = 1;
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE); //B_S = 2
		if (size < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[size] = '\0';
		line = next_line(line, buf);
		if (ft_includes(buf, '\n'))
		{
			buf = ft_strchr(buf, '\n');
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	//buf never ! after 1rst call, "\nr", will start over with strchr at "r..."
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
	char		*line;

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
		//printf("%s", line);
		free(line);
		line = NULL;
	}
	cl = close(fd);
	if (cl < 0)
		printf("Close error!\n");
	return (0);
}
