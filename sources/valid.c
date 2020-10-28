#include "push_swap.h"

static void		check_duplicates(t_data *ptr)
{
	t_stack		*slow;
	t_stack		*fast;

	slow = ptr->a;
	while (slow != ptr->a->prev)
	{
		fast = slow->next;
		while (fast != ptr->a)
		{
			if (slow->nbr == fast->nbr)
				ft_error(ptr);
			fast = fast->next;
		}
		slow = slow->next;
	}
}

void			valid(t_data *ptr)
{
	int i;
	int j;
	char **split_str;

	i = 1;
	while (ptr->argv[i])
	{
		j = 0;
		split_str = ft_strsplit(ptr->argv[i],' ');
		while (split_str[j])
		{
			if (!ft_isint(split_str[j]))
				ft_error(ptr);
			stack_add_end(ptr,'a',ft_atoi(split_str[j]));
			++j;
		}
		ft_arrdel((void ***)&split_str);
		++i;
	}
	check_duplicates(ptr);
}