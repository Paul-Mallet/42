/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:03:12 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/09 17:26:46 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/* int	main(int ac, char **av) */
/* { */
/* 	t_list	*head; */
/* 	char	*content_head; */
/* 	int	size; */

/* 	(void)ac; */
/* 	content_head = ft_strdup(av[1]); */
/* 	head = ft_lstnew(content_head); */
/* 	size = ft_lstsize(head); */

/* 	printf("size: %d\n", size); */
/* 	free(content_head); */
/* 	free(head); */
/* 	return (0); */
/* } */
