/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:08 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/24 14:44:32 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	curr = *lst;
	while (curr != NULL)
	{
		temp = curr->next;
		ft_lstdelone(curr, del);
		curr = temp;
	}
	curr = NULL;
}
/*
int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*mid;
	t_list	*tail;

	head = ft_lstnew(av[1]);
	mid = ft_lstnew(av[2]);
	tail = ft_lstnew(av[3]);
	ft_lstadd_back(&head, mid);
	ft_lstadd_back(&head, tail); //head->mid->tail
	ft_lstclear(&head, ft_lstdel); //head->null
	if (ac == 4)
		printf("%s\n", (char *)ft_lstlast(head)->content);
	else
		printf("Invalid arguments!");
	return (0);
}
*/
