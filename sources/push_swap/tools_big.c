/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:25:28 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 13:27:19 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			reset_big(t_data *ptr)
{
	ptr->min_forward = NULL;
	ptr->min_backward = NULL;
	ptr->min_next = 0;
	ptr->min_prev = 0;
	ptr->max_forward = NULL;
	ptr->max_backward = NULL;
	ptr->max_next = 0;
	ptr->max_prev = 0;
}

void			mid_split_big(t_data *ptr)
{
	int			len;
	int			i;
	long int	mid;

	if (sorted(ptr))
		return ;
	mid = mid_number(ptr, 'a');
	i = 0;
	len = stack_len(ptr, 'a');
	while (i++ < len)
	{
		if (ptr->a->nbr <= mid)
		{
			if (ptr->b && ptr->b->nbr > mid / 2)
				rb(ptr);
			pb(ptr);
		}
		else
			(ptr->b && ptr->b->nbr > mid / 2) ? rr(ptr) : ra(ptr);
	}
}

void			end_split_big(t_data *ptr)
{
	long int	min;
	long int	max;
	long int	mid;
	long int	more_than;
	long int	half;

	mid = mid_number(ptr, 'a');
	more_than = (mid / 2 * 3);
	min = min_stack(ptr->a);
	max = max_stack(ptr->a);
	half = ((max - more_than) / 2) + more_than;
	while (ptr->a->nbr != min)
	{
		if (ptr->a && ptr->a->nbr >= more_than)
		{
			if (ptr->b && ptr->b->nbr > half)
				rrb(ptr);
			pb(ptr);
		}
		else
			(ptr->b && ptr->b->nbr > half) ? rrr(ptr) : rra(ptr);
	}
}

void			again_split_big(t_data *ptr)
{
	long int	min;
	long int	mid;
	long int	less_than;
	long int	half;

	mid = mid_number(ptr, 'a');
	less_than = (mid / 2 * 3);
	min = min_stack(ptr->a);
	half = ((mid - less_than) / 2) + less_than;
	while (ptr->a->nbr != min)
	{
		if (ptr->a && ptr->a->nbr > mid && ptr->a->nbr < less_than)
		{
			if (ptr->b && ptr->b->nbr > half)
				rb(ptr);
			pb(ptr);
		}
		else
			(ptr->b && ptr->b->nbr > half) ? rr(ptr) : ra(ptr);
	}
}
