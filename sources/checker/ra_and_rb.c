/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_and_rb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:33:43 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:33:44 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_data *ptr)
{
	if (ptr->a)
		ptr->a = ptr->a->next;
	if (ptr->do_write)
		write(1, "ra\n", 3);
}

void	rb(t_data *ptr)
{
	if (ptr->b)
		ptr->b = ptr->b->next;
	if (ptr->do_write)
		write(1, "rb\n", 3);
}

void	rr(t_data *ptr)
{
	int	do_write;

	do_write = ptr->do_write;
	ptr->do_write = 0;
	ra(ptr);
	rb(ptr);
	ptr->do_write = do_write;
	if (ptr->do_write)
		write(1, "rr\n", 3);
}
