#include "checker.h"

void	check(t_data *ptr)
{
	char 	*line;

	line = NULL;
	if (ptr->flag)
		print_two_stacks(ptr,line);
	while(get_next_line(0,&line) > 0)
	{
		if (!instruction(ptr,line))
		{
			ft_error(ptr);
			ft_memdel((void  **)&line);
		}
		if (ptr->flag)
			print_two_stacks(ptr,line);
		ft_memdel((void **)&line);
	}
}

void	checker(t_data *ptr, char **argv)
{
	if (check_flag(argv))
		ptr->flag = TRUE;
	valid(ptr);
	check(ptr);
	if (sorted(ptr))
		ft_printf("OK");
	else
		ft_printf("KO");
	push_swap_free(ptr);
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
