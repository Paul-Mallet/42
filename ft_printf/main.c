/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:19:23 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/13 23:08:24 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main( int ac, char **av )
{
	(void)ac;
	void*	ptr = NULL;
	int		int42 = 42;
	int*	ptr42 = &int42;

	ft_printf("%%c: %c\n", 'c');
	printf("%%c: %c\n", 'c');

	ft_printf("%%s: %s\n", "String");
	printf("%%s: %s\n", "String");

	ft_printf("%%p: %p\n", ptr);
	printf("%%p: %p\n", ptr);

	ft_printf("%%p: %p\n", ptr42);
	printf("%%p: %p\n", ptr42);

	ft_printf("%%d: %d\n", ft_atoi(av[1]));
	printf("%%d: %d\n", atoi(av[1]));

	ft_printf("%%i: %i\n", ft_atoi(av[1]));
	printf("%%i: %i\n", atoi(av[1]));

	ft_printf("%%u: %u\n", (unsigned int)2500000000);
	printf("%%u: %u\n", (unsigned int)2500000000);

	ft_printf("%%x: %x\n", 42);
	printf("%%x: %x\n", 42);

	ft_printf("%%X: %X\n", 42);
	printf("%%X: %X\n", 42);

	ft_printf("%%: %%\n");
	printf("%%: %%\n");

	return (0);
}