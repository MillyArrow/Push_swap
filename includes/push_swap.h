/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:34:42 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 13:37:22 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_data
{
	t_stack			*a;
	t_stack			*b;
	int				do_write;
	char			**argv;
	int				flag;
	char			*line;
	t_stack			*min_forward;
	t_stack			*min_backward;
	int				min_next;
	int				min_prev;
	int				min_push;
	t_stack			*max_forward;
	t_stack			*max_backward;
	int				max_next;
	int				max_prev;
	int				rotate;
}					t_data;

int					stack_len(t_data *ptr, char stack_name);

t_data				*initialize(t_data *ptr, char **argv);

void				free_stack(t_stack *stack);
void				free_data(t_data *ptr);
void				push_swap_free(t_data *ptr);
void				ft_error(t_data *ptr);
void				stack_add_end(t_data *ptr, char stack_name, int n);
void				stack_add_top(t_data *ptr, char stack_name, int n);
void				stack_del_top(t_data *ptr, char stack_name);
void				pa(t_data *ptr);
void				pb(t_data *ptr);
void				ra(t_data *ptr);
void				rb(t_data *ptr);
void				rr(t_data *ptr);
void				sa(t_data *ptr);
void				sb(t_data *ptr);
void				ss(t_data *ptr);
void				rra(t_data *ptr);
void				rrb(t_data *ptr);
void				rrr(t_data *ptr);
void				push_swap(t_data *ptr);
void				check_duplicates(t_data *ptr);
void				valid(t_data *ptr);
int					sorted(t_data *ptr);
int					min_stack(t_stack *stack);
int					max_stack(t_stack *stack);
void				swap(int *a, int *b);
int					partition(int *arr, int l, int r);
void				quick_sort(int *arr, int l, int r);
void				sort(int *arr, int len);
int					mid_number(t_data *ptr, char stack_name);
void				reset(t_data *frame);
void				reset_big(t_data *frame);
void				get_move(t_data *frame);
void				get_min_max(t_data *frame);
void				two(t_data *ptr);
void				three(t_data *ptr);
void				four(t_data *ptr);
void				five(t_data *ptr);
void				small_cases(t_data *ptr);
void				move_hundred(t_data *frame);
void				insert_hundred(t_data *ptr);
void				mid_split(t_data *ptr);
void				again_split(t_data *frame);
void				sort_hundred(t_data *frame);
void				mid_split_big(t_data *ptr);
void				end_split_big(t_data *ptr);
void				again_split_big(t_data *ptr);
void				move_big(t_data *ptr);
void				insert_big(t_data *ptr);
void				insert_mid_big(t_data *ptr);
void				sort_big(t_data *frame);
#endif
