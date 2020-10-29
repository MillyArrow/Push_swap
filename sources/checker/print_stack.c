#include "checker.h"

int 				check_flag(char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == 'v' && !argv[1][2])
		return(TRUE);
	return(FALSE);
}

void			print_two_stacks(t_data *frame, char *line)
{

}
