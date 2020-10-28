
#include "push_swap.h"

static void		case_for_two(t_data *ptr)
{
	if (ptr->a->nbr > ptr->a->next->nbr)
		do_sa(ptr);
}

static void		case_for_three(t_data *ptr)
{
	long int		a1;
	long int		a2;
	long int		a3;

	if (sorted(ptr))
		return ;
	a1 = ptr->a->nbr;
	a2 = ptr->a->next->nbr;
	a3 = ptr->a->next->next->nbr;
	if (a1 < a2 && a1 < a3 && a2 > a3)
	{
		do_rra(ptr);
		do_sa(ptr);
	}
	else if (a1 > a2 && a1 < a3 && a2 < a3)
		do_sa(ptr);
	else if (a1 < a2 && a1 > a3 && a2 > a3)
		do_rra(ptr);
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		do_ra(ptr);
	else if (a1 > a2 && a1 > a3 && a2 > a3)
	{
		do_ra(ptr);
		do_sa(ptr);
	}
}

static void		case_for_four(t_data *ptr)
{
	int min;
	int	i;

	min = min_stack(ptr->a);
	i = 0;
	while (i++ < stack_len(ptr, 'a'))
	{
		if (ptr->a->nbr == min)
			do_pb(ptr);
		else
			do_ra(ptr);
	}
	case_for_three(ptr);
	do_pa(ptr);
}

static void		case_for_five(t_data *ptr)
{
	t_stack *end;
	int		mid_num;

	end = ptr->a->prev;
	mid_num = mid_number(ptr,'a');
	while(1)
	{
		if (ptr->a->nbr <= mid_num)
			do_pb(ptr);
		else
			do_ra(ptr);
		if (ptr->a == end)
			break ;
	}
	case_for_three(ptr);
	if (ptr->b->nbr < ptr->b->next->nbr)
		do_sb(ptr);
	do_pa(ptr);
	do_pa(ptr);
}

void			sort_small_cases(t_data *ptr)
{
	int len;

	len = stack_len(ptr,'a');
	if (!ptr->a)
		ft_error(ptr);
	if (len == 2)
		case_for_two(ptr);
	if (len == 3)
		case_for_three(ptr);
	if (len == 4)
		case_for_four(ptr);
	if (len == 5)
		case_for_five(ptr);
}
