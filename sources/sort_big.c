#include "push_swap.h"

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

static void		move_big(t_data *ptr)
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


void	sort_big(t_data *ptr)
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
