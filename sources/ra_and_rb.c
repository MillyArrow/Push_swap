
#include "push_swap.h"

void	do_ra(t_data *ptr)
{
	if (ptr->a)
		ptr->a = ptr->a->next;
	if (ptr->do_write)
		write(1, "ra\n", 3);
}

void	do_rb(t_data *ptr)
{
	if (ptr->b)
		ptr->b = ptr->b->next;
	if (ptr->do_write)
		write(1, "rb\n", 3);
}

void	do_rr(t_data *ptr)
{
	int	do_write;

	do_write = ptr->do_write;
	ptr->do_write = 0;
	do_ra(ptr);
	do_rb(ptr);
	ptr->do_write = do_write;
	if (ptr->do_write)
		write(1, "rr\n", 3);
}
