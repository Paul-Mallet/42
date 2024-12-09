/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:16:40 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/09 17:30:16 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* int	main(int ac, char **av) */
/* { */
/* 	t_list	*head; */
/* 	t_list	*body; */
/* 	t_list	*tale; */
/* 	char	*content_head; */
/* 	char	*content_body; */
/* 	char	*content_tale; */
/* 	int	size; */

/* 	(void)ac; */
/* 	content_head = ft_strdup(av[1]); */
/* 	content_body = ft_strdup(av[2]); */
/* 	content_tale = ft_strdup(av[3]); */
/* 	head = ft_lstnew(content_head); */
/* 	body = ft_lstnew(content_body); */
/* 	tale = ft_lstnew(content_tale); */
/* 	ft_lstadd_front(&tale, body); */
/* 	ft_lstadd_front(&body, head); */
/* 	size = ft_lstsize(head); */

/* 	printf("%s\n", (char *)ft_lstlast(head)->content); */
/* 	printf("size: %d\n", size); */
/* 	free(content_head); */
/* 	free(head); */
/* 	return (0); */
/* } */

