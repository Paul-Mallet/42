/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:42:37 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:06:36 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	if (curr == NULL)
		return (NULL);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}
/*
int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*l2;
	t_list	*l3;

	lst = ft_lstnew("1");
	l2 = ft_lstnew("2");
	l3 = ft_lstnew("3");
	ft_lstadd_front(&lst, l2);
	ft_lstadd_front(&lst, l3);

	(void)ac;
	(void)av;
	printf("%s\n", (char *)ft_lstlast(lst)->content); //"1"
	return (0);
}
*/
