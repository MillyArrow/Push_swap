#include "push_swap.h"

int main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	if (argc < 2)
		return(1);
	if (!(data = initialize(data, argv)))
		ft_error(data);
    push_swap(data);
    push_swap_free(data);
	return (0);
}