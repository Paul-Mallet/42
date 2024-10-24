/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:41:41 by pamallet          #+#    #+#             */
/*   Updated: 2024/10/24 18:54:20 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	lst->next = new;
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//if (ac == 2)
	//{
		ft_lstadd_front(&ft_lstnew("1rst"), ft_lstnew("2nd"));
	//}
	return (0);
}
