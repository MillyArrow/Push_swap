#include "push_swap.h"

void		reset(t_data *ptr)
{
	ptr->min_forward = NULL;
	ptr->min_backward = NULL;
	ptr->min_next = 0;
	ptr->min_prev = 0;
	ptr->min_push = 0;
	ptr->max_forward = NULL;
	ptr->max_backward = NULL;
	ptr->max_next = 0;
	ptr->max_prev = 0;
}

void		reset_big(t_data *ptr)
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

void		get_move(t_data *ptr)
{
	int i;

	i = 0;
	while (++i)
	{
		if (ptr->min_forward == ptr->b)
			ptr->min_next = i;
		ptr->min_forward = ptr->min_forward->next;
		if (ptr->min_backward == ptr->b)
			ptr->min_prev = i;
		ptr->min_backward = ptr->min_backward->prev;
		if (ptr->max_forward == ptr->b)
			ptr->max_next = i;
		ptr->max_forward = ptr->max_forward->next;
		if (ptr->max_backward == ptr->b)
			ptr->max_prev = i;
		ptr->max_backward = ptr->max_backward->prev;
		if (ptr->min_next || ptr->min_prev ||
			ptr->max_next || ptr->max_prev)
			break ;
	}
}

void		get_min_max(t_data *ptr)
{
	t_stack		*min;
	t_stack		*max;

	min = ptr->b;
	max = ptr->b;
	while (1)
	{
		min = min->next;
		if (min->nbr == min_stack(ptr->b))
			break ;
	}
	while (1)
	{
		max = max->next;
		if (max->nbr == max_stack(ptr->b))
			break ;
	}
	ptr->min_forward = min->next;
	ptr->min_backward = min->prev;
	ptr->max_forward = max->next;
	ptr->max_backward = max->prev;
}

