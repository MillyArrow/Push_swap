
#include "push_swap.h"

void			do_pa(t_data *ptr)
{
	int	tmp;

	if (ptr->b)
	{
		tmp = ptr->b->nbr;
		stack_del_top(ptr, 'b');
		stack_add_top(ptr, 'a', tmp);
	}
	if (ptr->do_write)
		write(1, "pa\n", 3);
}

void			do_pb(t_data *ptr)
{
	int	tmp;

	if (ptr->a)
	{
		tmp = ptr->a->nbr;
		stack_del_top(ptr, 'a');
		stack_add_top(ptr, 'b', tmp);
	}
	if (ptr->do_write)
		write(1, "pb\n", 3);
}
