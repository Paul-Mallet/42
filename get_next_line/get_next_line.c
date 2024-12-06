/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:58:59 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/06 17:30:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *buf)
{
	char	*line;
	int	i;

	line = (char *)malloc((ft_line_size(buf) + 1 ) * sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	printf("line extracted: %s\n", line);
	return (line);
}

char	*next_line(char *line, char *buf)
{
	char	*tmp_line;
	char	*tmp_buf;

	tmp_buf = extract_line(buf);
	tmp_line = ft_strjoin(line, tmp_buf); //include '\n'
	free(line); //?
	free(tmp_buf);
	return (tmp_line);
}

char	*read_line(int fd, char *buf)
{
	char		*line;
	ssize_t		size;

	line = NULL;
	size = 1;
	while (size > 0) //?
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[size] = '\0';
		/* printf("size: %zd\n", size); */
		/* printf("buf: %s\n", buf); */
		line = next_line(line, buf);
		if (ft_includes(buf, '\n'))
		{
			buf = ft_strchr(buf, '\n');
			printf("buf after strchr: %s\n", buf);
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
	if (!buf)
	{
		printf("1rst alloc");
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	}
	if (!buf)
		return (NULL);
	line = read_line(fd, buf);
	return (line);
}

int	main(int ac, char **av)
{
	int		fd;
	//int		fd[ac - 1]; (bonus)
	int		cl;
	char		*line;

	(void)av;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("(null)");
			free(line);
			break ;
		}
		//printf("line: %s\n", line);
		free(line);
		line = NULL;
	}
	cl = close(fd);
	if (cl < 0)
		printf("Close error!\n");
	return (0);
}
