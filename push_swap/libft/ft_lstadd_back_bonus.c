/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:43:14 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/01 17:41:04 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (lst != NULL && new != NULL)
	{
		if (*lst == NULL)
		{
			new->next = *lst;
			*lst = new;
		}
		else
		{
			curr = *lst;
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new;
		}
	}
}
/*
int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*tail;

	head = ft_lstnew(ft_strdup("head"));
	tail = ft_lstnew(ft_strdup("tail"));

	ft_lstadd_back(&head, tail);

	(void)ac;
	(void)av;
	printf("%s\n", (char *)ft_lstlast(head)->content);
	return (0);
}
*/
