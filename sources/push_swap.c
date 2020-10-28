
#include "push_swap.h"

int				sorted(t_data *ptr)
{
	t_stack		*start;
	t_stack		*end;

	if (!ptr->a || ptr->b)
		return (FALSE);
	start = ptr->a;
	end = ptr->a->prev;
	while (start != end)
	{
		if (start->nbr > start->next->nbr)
			return (FALSE);
		start = start->next;
	}
	return (TRUE);
}

void		push_swap(t_data *ptr)
{
	valid(ptr); //validation for digits
	t_stack *start = ptr->a;
	t_stack *end = ptr->a->prev;
	ptr->do_write = 1;
	if (sorted(ptr) || stack_len(ptr, 'a') == 1)
		return ;
	ft_printf("MID NUMBER = %d\n", mid_number(ptr,'a'));
	while (start)
	{
		ft_printf("%d\n", start->nbr);
		if (start == end)
			break;
		start = start->next;
	}
	ft_printf("start sort\n");
	sort_small_cases(ptr);
	if (sorted(ptr))
		ft_printf("SORTED\n");
	start = ptr->a;
	end = ptr->a->prev;
	while (start)
	{
		ft_printf("%d\n", start->nbr);
		if (start == end)
			break;
		start = start->next;
	}
}
	/*if (!sorted(ptr))
	{
		// to_do
		// if stack_len < 5 or 6
		//	sort_small_cases

int				main(int argc, char **argv)
{
	t_data		*ptr;

	ptr = NULL;
	if (argc < 2)
		return (1);
	ptr = initialize(ptr, argv);
	push_swap(ptr);
	return (0);
}*/
