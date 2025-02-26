/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:40:53 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/02/12 00:18:53 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    pipex(char **av)
{
    write(1, &av[1][0], 1);
}

int main(int ac, char **av, char **envp)
{
    (void)envp;
    if (ac > 1)
        pipex(av);
    return (0);
}