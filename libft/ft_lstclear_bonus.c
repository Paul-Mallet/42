/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:08 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/27 14:26:42 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static void	ft_lstdel(void *content)
{
	free(content);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst != NULL && del != NULL)
	{
		temp = *lst;
		while (temp != NULL)
		{
			temp = temp->next;
			ft_lstdelone(*lst, (*del));
			*lst = temp;
		}
	}
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
	ft_lstclear(&tail, ft_lstdel); //head->null
	if (ac == 4)
	{
		//if (tail == NULL)
		//	printf("Head deleted successfully!\n");
		while (head != NULL)
		{
			printf("%s\n", (char *)head->content);
			head = head->next;
		}
	}
	else
		printf("Invalid arguments!");
	return (0);
}
*/
