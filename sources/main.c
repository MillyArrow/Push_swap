/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:33:00 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:33:02 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
