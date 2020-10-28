#include "push_swap.h"

t_data		*initialize(t_data *ptr, char **argv)
{
	if (!(ptr = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	ptr->a = NULL;
	ptr->b = NULL;
	ptr->do_write = 0;
	ptr->argv = argv;
	ptr->line = NULL;
	ptr->str = NULL;
	ptr->min_forward = NULL;
	ptr->min_backward = NULL;
	ptr->min_next = 0;
	ptr->min_prev = 0;
	ptr->min_push = 0;
	ptr->max_forward = NULL;
	ptr->max_backward = NULL;
	ptr->max_next = 0;
	ptr->max_prev = 0;
	ptr->after_rotate = 0;
	return (ptr);
}