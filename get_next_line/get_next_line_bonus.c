/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:01:47 by paul_mall         #+#    #+#             */
/*   Updated: 2024/12/07 23:58:20 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat_bufs(char *buf, char *tmp_buf)
{
	char	*tmp_line;

	tmp_line = ft_strjoin(buf, tmp_buf);
	free(buf);
	return (tmp_line);
}

char	*read_file(char *buf, int fd)
{
	char	*tmp_buf;
	int		size;

	if (!buf)
		buf = ft_calloc(1, 1);
	tmp_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buf)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, tmp_buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(tmp_buf);
			return (NULL);
		}
		tmp_buf[size] = '\0';
		buf = concat_bufs(buf, tmp_buf);
		if (ft_strchr(tmp_buf, '\n'))
			break ;
	}
	free(tmp_buf);
	return (buf);
}

char	*extract_line(char *buf)
{
	char	*line;
	int		len;

	len = 0;
	if (!buf[len]) //?
		return (NULL);
	while (buf[len] && buf[len] != '\n')
		len++;
	line = (char *)malloc(((len + 1) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (buf[len] && buf[len] != '\n')
	{
		line[len] = buf[len];
		len++;
	}
	if (buf[len] && buf[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

char	*buffer_rest(char *buf)
{
	char	*next_buf;
	int		len;
	int		i;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (!buf[len])
	{
		free(buf);
		return (NULL);
	}
	next_buf = (char *)malloc(((ft_strlen(buf) - len) + 1) * sizeof(char));
	if (!next_buf)
		return (NULL);
	len++;
	i = 0;
	while (buf[len])
		next_buf[i++] = buf[len++];
	next_buf[i] = '\0';
	free(buf);
	return (next_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0) //?
		return (NULL);
	buf = read_file(buf, fd);
	if (!buf)
		return (NULL);
	line = extract_line(buf);
	buf = buffer_rest(buf);
	return (line);
}

int	main(int ac, char **av)
{
	int		i;
	int		*fds;
	char	**lines;

	fds = (int *)malloc(((ac - 1) + 1) * sizeof(int));
	lines = (char **)malloc(((ac - 1) + 1) * sizeof(char *));
	if (ac > 1)
	{
		i = -1;
		while (++i < (ac - 1)) //i = 0, ac = 2...
		{
			fds[i] = open(av[i + 1], O_RDONLY); //av[1]...
			if (fds[i] < 0)
				printf("Fd:%d not opened!", fds[i]);
		}
		fds[i] = -2;
	}
	else
	{
		fds[0] = 0;
		if (fds[0] < 0)
			printf("File not opened!");
	}
	while (1)
	{
		i = -1;
		while (++i < (ac - 1)) //?
		{
			lines[i] = get_next_line(fds[i]);
			if (!lines[i])
			{
				printf("(null)");
				free(lines[i]);
				break ;
			}
			printf("%s", lines[i]);
			free(lines[i]);
			lines[i] = NULL;
		}
	}
	i = -1;
	while (++i < (ac - 1))
	{
		if (close(fds[i]) == 0)
			printf("Fd:%d closed successfully.", fds[i]);
	}
	return (0);
}
