/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:35:06 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 13:36:10 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

t_data				*initialize(t_data *ptr, char **argv);

void				check_duplicates(t_data *ptr);
void				valid(t_data *ptr);
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
int					instruction(t_data *ptr, char *line);
int					sorted(t_data *ptr);
int					check_flag(char **argv);
void				print_two_stacks(t_data *frame, char *line);
#endif
