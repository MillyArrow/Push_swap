/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_and_sb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:33:57 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:33:58 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			sa(t_data *ptr)
{
	long int	tmp;

	if (ptr->a && ptr->a->next != ptr->a)
	{
		tmp = ptr->a->nbr;
		ptr->a->nbr = ptr->a->next->nbr;
		ptr->a->next->nbr = tmp;
	}
	if (ptr->do_write)
		write(1, "sa\n", 3);
}

void			sb(t_data *ptr)
{
	long int	tmp;

	if (ptr->b && ptr->b->next != ptr->b)
	{
		tmp = ptr->b->nbr;
		ptr->b->nbr = ptr->b->next->nbr;
		ptr->b->next->nbr = tmp;
	}
	if (ptr->do_write)
		write(1, "sb\n", 3);
}

void			ss(t_data *ptr)
{
	int			do_write;

	do_write = ptr->do_write;
	ptr->do_write = 0;
	sa(ptr);
	sb(ptr);
	ptr->do_write = do_write;
	if (ptr->do_write)
		write(1, "ss\n", 3);
}
