/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:55 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 18:04:12 by pamallet         ###   ########.fr       */
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
	str[i] = '\0';
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
			if (!nlst && !curr)
				return (NULL);
			if (!curr)
			{
				free(curr->content);
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
	t_list	*n_list;

	head = ft_lstnew(ft_strdup(av[1])); //1 free
	mid = ft_lstnew(ft_strdup(av[2]));
	tail = ft_lstnew(ft_strdup(av[3]));
	ft_lstadd_back(&head, mid);
	ft_lstadd_back(&head, tail);
	newhead = ft_lstmap(head, ft_to_upper, ft_lstdel);
	if (ac == 4)
	{
		n_list = newhead;
		while (n_list != NULL)
		{
			printf("%s\n", (unsigned char *)n_list->content);
			n_list = n_list->next;
		}
	}
	else
		printf("Invalid arguments!");
	printf("%s\n", (char *)head->content);
	printf("%s\n", (char *)newhead->content);
	ft_lstclear(&head, ft_lstdel);
	ft_lstclear(&newhead, ft_lstdel);
	return (0);
}
*/
/*
nlst = (t_list *)malloc(sizeof(t_list));
if (nlst == NULL)
	return (NULL);
*/
