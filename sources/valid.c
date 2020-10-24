#include "push_swap.h"

int valid(int ac, char **av)
{
	int i;
	int j;
	char **split_str;

	i = 0;
	while (av[i])
	{
		j = 0;
		split_str = ft_strsplit(av[i],' ');
		while (split_str[j])
		{
			if (!ft_isint(split_str[j]))
				return (FALSE);
			++j;
		}
		++i;
	}
	return (TRUE);
}