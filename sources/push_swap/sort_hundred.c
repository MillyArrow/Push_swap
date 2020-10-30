/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:20:15 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 13:23:49 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			move_hundred(t_data *frame)
{
	if (frame->min_backward->nbr == frame->min_backward->next->nbr)
	{
		pa(frame);
		ra(frame);
		return ;
	}
	else if (frame->min_next && (frame->min_push = 1))
		while (frame->min_next--)
			rrb(frame);
	else if (frame->min_prev && (frame->min_push = 1))
		while (frame->min_prev--)
			rb(frame);
	else if (frame->max_next)
		while (frame->max_next--)
			rrb(frame);
	else if (frame->max_prev)
		while (frame->max_prev--)
			rb(frame);
	pa(frame);
	if (frame->min_push)
		ra(frame);
	else
		frame->rotate++;
}

void			insert_hundred(t_data *ptr)
{
	t_stack		*stack_b;

	stack_b = ptr->b;
	ptr->rotate = 0;
	if (stack_b)
	{
		while (ptr->b)
		{
			reset(ptr);
			get_min_max(ptr);
			get_move(ptr);
			move_hundred(ptr);
		}
		while (ptr->rotate--)
			ra(ptr);
	}
}

void			mid_split(t_data *ptr)
{
	int			len;
	int			i;
	long int	mid;

	if (sorted(ptr))
		return ;
	i = 0;
	mid = mid_number(ptr, 'a');
	len = stack_len(ptr, 'a');
	while (i++ < len)
	{
		if (ptr->a->nbr <= mid)
			pb(ptr);
		else
			ra(ptr);
	}
}

void			again_split(t_data *frame)
{
	long int	min;
	long int	mid;

	mid = mid_number(frame, 'a');
	min = min_stack(frame->a);
	while (frame->a->nbr != min)
	{
		if (frame->a && frame->a->nbr > mid)
			pb(frame);
		else
			ra(frame);
	}
}

void			sort_hundred(t_data *frame)
{
	if (sorted(frame))
		return ;
	mid_split(frame);
	insert_hundred(frame);
	again_split(frame);
	insert_hundred(frame);
}
