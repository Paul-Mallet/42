/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:36:01 by paul_mall         #+#    #+#             */
/*   Updated: 2025/02/03 13:20:04 by pamallet         ###   ########.fr       */
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
	int	*arr;
	int	len;
	int	capacity;
}		t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_stack	cpy;
	char	**log_ops;
	int	log_index;
	int	nb_ops;
	int	*input;
	int	len;
}		t_data;

void	init_stack(t_stack *stk, char **av, char name);
void	bubble_sort(t_stack *stk);
void	fill_stack(t_stack *stk, char **av);
void	refill_stack(t_stack *stk, t_stack *cpy);

void	swap(t_stack *stk);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stk, t_data *data);
void	rev_rotate(t_stack *stk, t_data *data);

int	count_ints(char *s);
void	print_log_ops(t_data *data);


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

void	turk_sort(t_data *data);
void	cheap_sort(t_data *data);
void	three_sort(t_data *data);

#endif
