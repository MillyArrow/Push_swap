
#include "push_swap.h"

static void		free_stack(t_stack *stack)
{
	t_stack		*track_next;
	t_stack		*delete;

	if (stack)
	{
		track_next = stack->next;
		while (track_next != stack)
		{
			delete = track_next;
			track_next = track_next->next;
			free(delete);
		}
		free(track_next);
	}
}

static void		free_data(t_data *ptr)
{
	if (ptr)
	{
		if (ptr->a)
			free_stack(ptr->a);
		if (ptr->b)
			free_stack(ptr->b);
		if (ptr->line)
			free(ptr->line);
		if (ptr->str)
			free(ptr->str);
		free(ptr);
	}
}

void			push_swap_free(t_data *ptr)
{
	free_data(ptr);
}