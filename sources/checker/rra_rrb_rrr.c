/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:33:49 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:33:50 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_data *ptr)
{
	if (ptr->a)
		ptr->a = ptr->a->prev;
	if (ptr->do_write)
		write(1, "rra\n", 4);
}

void	rrb(t_data *ptr)
{
	if (ptr->b)
		ptr->b = ptr->b->prev;
	if (ptr->do_write)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *ptr)
{
	int	do_write;

	do_write = ptr->do_write;
	ptr->do_write = 0;
	rra(ptr);
	rrb(ptr);
	ptr->do_write = do_write;
	if (ptr->do_write)
		write(1, "rrr\n", 4);
}
