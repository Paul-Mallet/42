/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:30:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/09 18:07:38 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*body;
	t_list	*tale;
	char	*content_head;
	char	*content_body;
	char	*content_tale;
	int	size;

	(void)ac;
	content_head = ft_strdup(av[1]);
	content_body = ft_strdup(av[2]);
	content_tale = ft_strdup(av[3]);
	head = ft_lstnew(content_head);
	body = ft_lstnew(content_body);
	tale = ft_lstnew(content_tale);
	ft_lstadd_front(&body, head);
	ft_lstadd_back(&head, tale); //
	size = ft_lstsize(head);

	printf("%s\n", (char *)ft_lstlast(head)->content);
	printf("size: %d\n", size);
	free(content_head);
	free(head);
	return (0);
}
