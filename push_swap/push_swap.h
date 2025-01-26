/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:36:01 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/26 12:16:08 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

# define ERROR_MSG "Error\n"
# define BUFFER_SIZE 8

typedef struct s_stack
{
	char	name;
	int		*arr;
	int		len;
	int		capacity;
}		t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	int	*input;
	int	len;
}		t_data;

void	init_stack(t_stack *stk, char **av, char name);

void	swap(t_stack *stk);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stk);
void	rev_rotate(t_stack *stk);

int	ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
int	is_overflow(char *s);
int	ft_atoi(char *s);
int	is_duplicate(t_stack *stk, int k, int n);

void	handle_error(const char *s);
int	ft_strlen(const char *s);
int	is_space(const char c);
int	is_digit(const char c);
int	is_valid_input(char *s);

void	sort_three(t_stack *stk);
void	sort_five(t_stack *a, t_stack *b);
/* int		ft_quick_select(int *arr, int left, int right, int k); */
/* int		ft_partition(int *arr, int low, int high); */
/* void	ft_quick_sort(int *arr, int low, int high); */

#endif
