/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:36:01 by paul_mall         #+#    #+#             */
/*   Updated: 2025/02/10 17:42:33 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define ERROR_MSG "Error\n"
# define BUFFER_SIZE 8
# define INDEX -1

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
	t_stack	cpy;
	char	**log_ops;
	int		log_index;
	int		nb_ops;
	int		len_log;
}		t_data;

void	init_stack(t_stack *stk, char **av, char name);
void	bubble_sort(t_stack *stk);
void	fill_stack(t_stack *stk, char **av);
void	refill_stack(t_stack *stk, t_stack *cpy);
void	init_log_ops(t_data *data);
void	ft_free_log_ops(t_data *data);
void	free_stacks(t_data *data);

void	swap(t_stack *stk);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stk, t_data *data, int is_final);
void	rev_rotate(t_stack *stk, t_data *data, int is_final);

int		count_ints(char *s);
int		optimal_count(int count, int count2);
void	count_cheap_total_ops(t_data *data, int is_first, int is_second);
int		cheap_index_from_a(int top_b, t_data *data);
int		above_bigger(t_stack *b);
int		cheap_index_from_b(int top_a, t_data *data);
int		cheap_index_from_a_to_b(t_data *data, int i);
void	first_desc_sort_b(t_stack *stk);
void	two_sort(t_data *data);
void	three_sort(t_data *data);
int		desc_rotate_len(int top_a, t_data *data);
int		dsc_rot_nb_ops(int top_a, t_data *data, int count, int is_r);
int		asc_rotate_nb_ops(int top_b, t_data *data);
void	final_asc_sort_a(t_data *data);
void	print_rotate_to_top_a(t_data *data, int cheap_i_a, int is_f_a_to_b);
void	print_stack(t_stack *stk);
void	print_rest(int n, int m, char *s1, char *s2);
void	print_all_log_ops(t_data *data);
void	print_log_ops(t_data *data);

int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
int		is_overflow(char *s);
int		ft_atoi(char *s);
int		is_duplicate(t_stack *stk, int k, int n);

int		ft_abs(int n);
void	handle_error(const char *s);
int		ft_isspace(const char c);
int		ft_issign(const char c);
int		is_valid_input(char *s);

void	turk_sort(t_data *data);
void	cheap_sort(t_data *data);
void	three_sort(t_data *data);

#endif
