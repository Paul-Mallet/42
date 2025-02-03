/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:41:58 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 12:50:14 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c;

	c = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		c++;
	}
	return (c);
}
/*
int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*l2;

	lst = ft_lstnew(ft_strdup("1"));
	l2 = ft_lstnew(ft_strdup("2"));

	ft_lstadd_front(&lst, l2);
	(void)ac;
	(void)av;
	if (ac == 2)
	{
		printf("%d\n", ft_lstsize(lst));
	}
	else
		printf("Need valid arguments!");
	return (0);
}
*/
