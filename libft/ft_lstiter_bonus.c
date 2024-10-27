/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:43 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/27 14:31:11 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static void	ft_to_upper(void *content)
{
	unsigned char	*str;
	int				i;

	str = (unsigned char *)content;
	i = 0;
	while (str[i])
	{
		str[i] -= 32;
		i++;
	}
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL && (*f) != NULL)
	{
		while (lst != NULL)
		{
			(*f)(lst->content);
			lst = lst->next;
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
	ft_lstadd_back(&head, tail);
	ft_lstiter(head, ft_to_upper);
	if (ac == 4)
	{
		while (head != NULL)
		{
			printf("%s\n", (char *)head->content);
			head = head->next;
		}
		head = ft_lstlast(head);
		printf("%s\n", (char *)head->content);
	}
	else
		printf("Invalid arguments!");
	return (0);
}
*/
