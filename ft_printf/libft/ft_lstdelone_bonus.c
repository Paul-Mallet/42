/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:43:53 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 12:49:41 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	ft_lstdel(void *content)
{
	free(content);
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		(*del)(lst->content);
		free(lst);
	}
}
/*
int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*mid;
	t_list	*tail;

	head = ft_lstnew(ft_strdup(av[1]));
	mid = ft_lstnew(ft_strdup(av[2]));
	tail = ft_lstnew(ft_strdup(av[3]));
	ft_lstadd_back(&head, mid);
	ft_lstadd_back(&head, tail);
	ft_lstdelone(tail, ft_lstdel);
	if (ac == 5)
		printf("%s\n", (char *)ft_lstlast(head)->content);
	else
		printf("Invalid arguments!");
	return (0);
}
*/
