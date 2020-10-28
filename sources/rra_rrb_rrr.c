
#include "push_swap.h"

void	do_rra(t_data *ptr)
{
	if (ptr->a)
		ptr->a = ptr->a->prev;
	if (ptr->do_write)
		write(1, "rra\n", 4);
}

void	do_rrb(t_data *ptr)
{
	if (ptr->b)
		ptr->b = ptr->b->prev;
	if (ptr->do_write)
		write(1, "rrb\n", 4);
}

void	do_rrr(t_data *ptr)
{
	int	do_write;

	do_write = ptr->do_write;
	ptr->do_write = 0;
	do_rra(ptr);
	do_rrb(ptr);
	ptr->do_write = do_write;
	if (ptr->do_write)
		write(1, "rrr\n", 4);
}
