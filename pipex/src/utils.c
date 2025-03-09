/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:22:09 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/09 19:18:52 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		printf("cmd[%d]: %s\n", i, args[i]);
}

int	valid_len(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (i == 1 || i == (ac - 1)) //file1 or file2
		{
			while (av[i][j]) //handle pathname(paht + file) < 4096
				j++;
			if (j >= 255) //filename
				return (0);
		}
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_is_spechar(char c)
{
	return (c == '-' || c == '_' || c == '.' || c == '/');
}