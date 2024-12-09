/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:22:50 by paul_mall         #+#    #+#             */
/*   Updated: 2024/12/07 12:44:05 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	main(int ac, char **av)
{
	t_list	*old_header;
	t_list	*new_header;
	char	*old_content;
	char	*new_content;

	(void)ac;
	old_content = ft_strdup(av[1]);
	new_content = ft_strdup(av[2]);
	old_header = ft_lstnew(old_content);
	new_header = ft_lstnew(new_content);

	ft_lstadd_front(&old_header, new_header);

	printf("%s\n", (char *)new_header->next->content);

	return (0);
}
