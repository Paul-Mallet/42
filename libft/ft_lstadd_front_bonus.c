/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:41:41 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/01 17:40:05 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*new;

	lst = ft_lstnew(ft_strdup("old"));
	new = ft_lstnew(ft_strdup("new"));
	(void)ac;
	(void)av;
	//if (ac == 2)
	//{
		ft_lstadd_front(&lst, new);
		printf("%s\n", (char *)lst->next->content);
	//}
	return (0);
}
*/
