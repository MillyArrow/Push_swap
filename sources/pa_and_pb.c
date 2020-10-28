/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_and_pb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:33:10 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:33:12 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			do_pa(t_data *ptr)
{
	int	tmp;

	if (ptr->b)
	{
		tmp = ptr->b->nbr;
		stack_del_top(ptr, 'b');
		stack_add_top(ptr, 'a', tmp);
	}
	if (ptr->do_write)
		write(1, "pa\n", 3);
}

void			do_pb(t_data *ptr)
{
	int	tmp;

	if (ptr->a)
	{
		tmp = ptr->a->nbr;
		stack_del_top(ptr, 'a');
		stack_add_top(ptr, 'b', tmp);
	}
	if (ptr->do_write)
		write(1, "pb\n", 3);
}
