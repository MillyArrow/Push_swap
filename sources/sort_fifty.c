
#include "push_swap.h"

static void		reset_moves(t_data *frame)
{
	frame->min_forward = NULL;
	frame->min_backward = NULL;
	frame->min_next = 0;
	frame->min_prev = 0;
	frame->min_push = 0;
	frame->max_forward = NULL;
	frame->max_backward = NULL;
	frame->max_next = 0;
	frame->max_prev = 0;
}

static void		execute_push(t_data *frame)
{
	if (frame->min_backward->nbr == frame->min_backward->next->nbr)
	{
		do_pa(frame);
		do_ra(frame);
		return ;
	}
	else if (frame->min_next && (frame->min_push = 1))
		while (frame->min_next--)
			do_rrb(frame);
	else if (frame->min_prev && (frame->min_push = 1))
		while (frame->min_prev--)
			do_rb(frame);
	else if (frame->max_next)
		while (frame->max_next--)
			do_rrb(frame);
	else if (frame->max_prev)
		while (frame->max_prev--)
			do_rb(frame);
	do_pa(frame);
	if (frame->min_push)
		do_ra(frame);
	else
		frame->after_rotate++;
}

static void		get_moves(t_data *frame)
{
	int i;

	i = 0;
	while (++i)
	{
		if (frame->min_forward == frame->b)
			frame->min_next = i;
		frame->min_forward = frame->min_forward->next;
		if (frame->min_backward == frame->b)
			frame->min_prev = i;
		frame->min_backward = frame->min_backward->prev;
		if (frame->max_forward == frame->b)
			frame->max_next = i;
		frame->max_forward = frame->max_forward->next;
		if (frame->max_backward == frame->b)
			frame->max_prev = i;
		frame->max_backward = frame->max_backward->prev;
		if (frame->min_next || frame->min_prev ||
			frame->max_next || frame->max_prev)
			break ;
	}
}

static void		get_min_max(t_data *frame)
{
	t_stack		*min;
	t_stack		*max;

	min = frame->b;
	max = frame->b;
	while (1)
	{
		min = min->next;
		if (min->nbr == min_stack(frame->b))
			break ;
	}
	while (1)
	{
		max = max->next;
		if (max->nbr == max_stack(frame->b))
			break ;
	}
	frame->min_forward = min->next;
	frame->min_backward = min->prev;
	frame->max_forward = max->next;
	frame->max_backward = max->prev;
}

void			fifty_insert(t_data *frame)
{
	t_stack		*stack_b;

	stack_b = frame->b;
	frame->after_rotate = 0;
	if (stack_b)
	{
		while (frame->b)
		{
			reset_moves(frame);
			get_min_max(frame);
			get_moves(frame);
			execute_push(frame);
		}
		while (frame->after_rotate--)
			do_ra(frame);
	}
}
void			solution_fifty_split_median(t_data *frame)
{
	t_stack		*stack_a_end;
	int			flag;
	long int	median;

	if (sorted(frame))
		return ;
	stack_a_end = frame->a->prev;
	median = mid_number(frame, 'a');
	flag = 0;
	while (1)
	{
		if (frame->a == stack_a_end)
			flag = 1;
		if (frame->a->nbr <= median)
			do_pb(frame);
		else
			do_ra(frame);
		if (flag)
			break ;
	}
}
void	solution_fifty_split_rest(t_data *frame)
{
	long int	min;
	long int	median;

	median = mid_number(frame, 'a');
	min = min_stack(frame->a);
	while (frame->a->nbr != min)
	{
		if (frame->a && frame->a->nbr > median)
			do_pb(frame);
		else
			do_ra(frame);
	}
}

void	sort_fifty(t_data *frame)
{
	if (sorted(frame))
		return ;
	solution_fifty_split_median(frame);
	fifty_insert(frame);
	solution_fifty_split_rest(frame);
	fifty_insert(frame);
}