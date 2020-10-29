#include "checker.h"

int		instruction(t_data *ptr, char *line)
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
		return (FALSE);
	return (TRUE);
}