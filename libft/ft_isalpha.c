/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:59:19 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 10:56:36 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1024);
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_isalpha(98));
	printf("%d\n", isalpha('b'));
	printf("%d\n", isalpha('c'));
	printf("%d\n", isalpha('d'));
	return (0);
}
*/
