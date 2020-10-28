
#include "push_swap.h"

void	ft_error(t_data *ptr)
{
	write(2, "Error\n", 6);
	push_swap_free(ptr);
	exit(-1);
}
