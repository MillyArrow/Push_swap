#include "push_swap.h"

void		reset(t_data *frame)
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

void		reset_big(t_data *frame)
{
	frame->min_forward = NULL;
	frame->min_backward = NULL;
	frame->min_next = 0;
	frame->min_prev = 0;
	frame->max_forward = NULL;
	frame->max_backward = NULL;
	frame->max_next = 0;
	frame->max_prev = 0;
}

void		get_move(t_data *frame)
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

void		get_min_max(t_data *frame)
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

