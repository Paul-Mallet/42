/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:40:18 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/31 13:52:43 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
/*
int	main(int ac, char **av)
{
	char	*str = "test";
	int		*ptrn;
	int		n;

	n = 42;
	ptrn = &n;
	(void)ac;
	(void)av;
	//if (ac == 2);
	//{
		printf("%s\n", (char *)ft_lstnew(str)->content); //cast? *((int)n)
		printf("%d\n", *(int *)ft_lstnew(ptrn)->content);
	//}
	//else
	//	printf("Need valid arguments!");
	return (0);
}
*/
