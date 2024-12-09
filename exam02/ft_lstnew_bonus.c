/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:59:16 by paul_mall         #+#    #+#             */
/*   Updated: 2024/12/07 12:46:24 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int	main(int ac, char **av) */
/* { */
/* 	t_list	*header; */
/* 	char	*content; */

/* 	(void)ac; */
/* 	content = ft_strdup(av[1]); */
/* 	header = ft_lstnew(content); */

/* 	printf("content: %s\n", (char *)header->content); */

/* 	free(content); */
/* 	free(header); */
/* 	return (0); */
/* } */
