/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:33:00 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 13:14:51 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					check_flag(char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == 'v' && !argv[1][2])
		return (TRUE);
	return (FALSE);
}

int					main(int argc, char **argv)
{
	t_data		*data;

	data = NULL;
	if (argc < 2)
		return (1);
	if (!(data = initialize(data, argv)))
		ft_error(data);
	if (check_flag(argv))
		data->flag = TRUE;
	push_swap(data);
	push_swap_free(data);
	return (0);
}
