/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:55 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/27 19:00:44 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_to_upper(void *content) //strdup + toupper
{
	unsigned char	*str;
	unsigned char	*c;
	int				i;

	str = (unsigned char *)malloc((ft_strlen((const char *)content) + 1) * sizeof(unsigned char));
	if (str == NULL)
		return (NULL);
	c = (unsigned char *)content;
	i = 0;
	while (c[i])
	{
		str[i] = c[i];
		str[i] -= 32;
		i++;
	}
	return (str);
}
/*
static void	ft_lstfree(t_list *lst)
{
	//free all nodes
}
*/
static void	ft_lstdel(void *content)
{
	free(content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*temp;

	nlst = (t_list *)malloc(sizeof(t_list));
	if (nlst == NULL)
		return (NULL);
	if (lst != NULL && (*f) != NULL && (*del) != NULL)
	{
		//if lst have only 1 node(head) head->mid->tail
		temp = lst;
		while (temp != NULL)
		{
			temp = temp->next;
			nlst->content = (*f)(lst->content); //if (nlst->content == NULL)
			nlst->next = lst->next;
			lst = temp;
		}
	}
	return (nlst);
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*mid;
	t_list	*tail;
	t_list	*newhead;

	head = ft_lstnew(av[1]);
	mid = ft_lstnew(av[2]);
	tail = ft_lstnew(av[3]);
	ft_lstadd_back(&head, mid);
	ft_lstadd_back(&head, tail);
	newhead = ft_lstmap(head, ft_to_upper, ft_lstdel);
	if (ac == 4)
	{
		while (newhead != NULL) //newhead
		{
			printf("%s\n", (unsigned char *)newhead->content);
			//printf("%s\n", (unsigned char *)head->content);
			newhead = newhead->next;
			//head = head->next;
		}
		//...
	}
	else
		printf("Invalid arguments!");
	return (0);
}
