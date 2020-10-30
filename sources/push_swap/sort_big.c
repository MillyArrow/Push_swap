/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:20:22 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 13:27:14 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			move_big(t_data *ptr)
{
	if (ptr->min_next && (ptr->min_push = 1))
		while (ptr->min_next--)
			rrb(ptr);
	else if (ptr->min_prev && (ptr->min_push = 1))
		while (ptr->min_prev--)
			rb(ptr);
	else if (ptr->max_next)
		while (ptr->max_next--)
			rrb(ptr);
	else if (ptr->max_prev)
		while (ptr->max_prev--)
			rb(ptr);
	pa(ptr);
	(ptr->b) ? reset_big(ptr) : 0;
	(ptr->b) ? get_min_max(ptr) : 0;
	(ptr->b) ? get_move(ptr) : 0;
	if (ptr->min_prev && !ptr->min_next && !ptr->max_next &&
		!ptr->max_prev && ptr->min_push)
		rr(ptr);
	else if (ptr->min_push)
		ra(ptr);
	else
		ptr->rotate++;
}

void			insert_big(t_data *ptr)
{
	t_stack		*stack_b;

	stack_b = ptr->b;
	ptr->rotate = 0;
	if (stack_b)
	{
		while (ptr->b)
		{
			reset_big(ptr);
			get_min_max(ptr);
			get_move(ptr);
			move_big(ptr);
			ptr->min_push = 0;
		}
		while (ptr->rotate--)
			ra(ptr);
	}
}

void			insert_mid_big(t_data *ptr)
{
	t_stack		*stack_b;

	stack_b = ptr->b;
	ptr->rotate = 0;
	if (stack_b)
	{
		while (ptr->b)
		{
			reset_big(ptr);
			get_min_max(ptr);
			get_move(ptr);
			move_big(ptr);
			ptr->min_push = 0;
		}
	}
}

void			sort_big(t_data *ptr)
{
	if (sorted(ptr))
		return ;
	mid_split_big(ptr);
	insert_big(ptr);
	again_split_big(ptr);
	insert_mid_big(ptr);
	end_split_big(ptr);
	insert_big(ptr);
}
