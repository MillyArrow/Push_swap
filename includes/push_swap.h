/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:34:42 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:34:42 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "libft.h"
# include "ft_printf.h"



typedef struct		s_stack
{
	int		nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;


typedef struct		s_data
{
	t_stack			*a;
	t_stack			*b;

	int				do_write;

	char			**argv;
	char			*line;
	char			*str;

	t_stack			*min_forward;
	t_stack			*min_backward;
	int				min_next;
	int				min_prev;
	int				min_push;

	t_stack			*max_forward;
	t_stack			*max_backward;
	int				max_next;
	int				max_prev;

	int				after_rotate;
}					t_data;




int					stack_len(t_data *ptr, char stack_name);
void				sort_small_cases(t_data *ptr);

/*
** Common functions (for checker and push_swap)
*/

t_data				*initialize(t_data *ptr, char **argv);

void				push_swap_free(t_data *ptr);
void				ft_error(t_data *ptr);
void				fill_stack_a(t_data *ptr);
void				stack_add_end(t_data *ptr, char stack_name, int n);
void				stack_add_top(t_data *ptr, char stack_name, int n);
void				stack_del_top(t_data *ptr, char stack_name);

void				do_pa(t_data *ptr);
void				do_pb(t_data *ptr);
void				do_ra(t_data *ptr);
void				do_rb(t_data *ptr);
void				do_rr(t_data *ptr);
void				do_sa(t_data *ptr);
void				do_sb(t_data *ptr);
void				do_ss(t_data *ptr);
void				do_rra(t_data *ptr);
void				do_rrb(t_data *ptr);
void				do_rrr(t_data *ptr);

void				valid(t_data *ptr);
void				push_swap(t_data *ptr);
int					sorted(t_data *ptr);
int					min_stack(t_stack *stack);
int					max_stack(t_stack *stack);
int					mid_number(t_data *ptr, char stack_name);
#endif
