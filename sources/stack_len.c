#include "push_swap.h"

int			stack_len(t_data *ptr, char stack_name)
{
	int		stack_len;
	t_stack	*stack;
	t_stack	*end;

	stack_len = 0;
	stack = (stack_name == 'a') ? ptr->a : ptr->b;
	if (stack)
		end = (stack_name == 'a') ? ptr->a->prev : ptr->b->prev;
	while (stack)
	{
		stack_len++;
		if (stack == end)
			break ;
		stack = stack->next;
	}
	return (stack_len);
}
