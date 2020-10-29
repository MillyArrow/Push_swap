#include "checker.h"

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

void	check(t_data *ptr)
{
	char *line;

	line = NULL;
	while(get_next_line(0,&line) > 0)
	{

		if (ft_strstr(line,"ss"))
			ss(ptr);
		else if (ft_strstr(line,"rra"))
			rra(ptr);
		else if (ft_strstr(line,"rrb"))
			rrb(ptr);
		else if (ft_strstr(line,"rrr"))
			rrr(ptr);
		else if (ft_strstr(line,"pa"))
			pa(ptr);
		else if (ft_strstr(line,"pb"))
			pb(ptr);
		else if (ft_strstr(line,"ra"))
			ra(ptr);
		else if (ft_strstr(line,"rb"))
			rb(ptr);
		else if (ft_strstr(line,"rr"))
			rr(ptr);
		else if (ft_strstr(line,"sa"))
			sa(ptr);
		else if (ft_strstr(line,"sb"))
			sb(ptr);
		else
			ft_error(ptr);
		ft_memdel((void **)&line);
	}
}

void	checker(t_data *ptr, char **argv)
{
	valid(ptr);
	check(ptr);
	if (sorted(ptr))
		ft_printf("OK");
	else
		ft_printf("KO");
	push_swap_free(ptr);
}

void	ft_error(t_data *ptr)
{
	write(2, "Error\n", 6);
	push_swap_free(ptr);
	exit(-1);
}

int 	main(int argc, char **argv)
{
	t_data	*ptr;

	ptr = NULL;
	ptr = initialize(ptr,argv);
	if (argc < 2)
		return (1);
	checker(ptr,argv);
	return (0);
}
