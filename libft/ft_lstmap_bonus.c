/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:55 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/28 12:54:09 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static void	*ft_to_upper(void *content)
{
	unsigned char	*str;
	const char	*c;
	int				i;
	size_t		c_len;

	c = (const char *)content;
	c_len = ft_strlen(c);
	str = (unsigned char *)malloc((c_len + 1) * sizeof(unsigned char)); //free?
	if (str == NULL)
		return (NULL);
	i = 0;
	while (c[i])
	{
		str[i] = c[i];
		str[i] -= 32;
		i++;
	}
	return (str);
}

static void	ft_lstdel(void *content)
{
	free(content);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*curr;

	nlst = NULL;
	if (lst != NULL && (*f) != NULL && (*del) != NULL)
	{
		while (lst != NULL)
		{
			curr = ft_lstnew((*f)(lst->content));
			if (curr == NULL)
			{
				ft_lstclear(&nlst, del);
				return (NULL);
			}
			ft_lstadd_back(&nlst, curr);
			lst = lst->next;
		}
	}
	return (nlst);
}
/*
int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*mid;
	t_list	*tail;
	t_list	*newhead;

	(void)av;
	head = ft_lstnew(av[1]);
	mid = ft_lstnew(av[2]);
	tail = ft_lstnew(av[3]);
	ft_lstadd_back(&head, mid);
	ft_lstadd_back(&head, tail);
	newhead = ft_lstmap(head, ft_to_upper, ft_lstdel);
	if (ac == 4)
	{
		while (newhead != NULL)
		{
			printf("%s\n", (unsigned char *)newhead->content);
			newhead = newhead->next;
		}
	}
	else
		printf("Invalid arguments!");
	return (0);
}
*/
/*
nlst = (t_list *)malloc(sizeof(t_list));
if (nlst == NULL)
	return (NULL);
*/
