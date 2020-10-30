/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:28:38 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 13:28:39 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				sorted(t_data *ptr)
{
	t_stack		*start;
	t_stack		*end;

	if (!ptr->a || ptr->b)
		return (FALSE);
	start = ptr->a;
	end = ptr->a->prev;
	while (start != end)
	{
		if (start->nbr > start->next->nbr)
			return (FALSE);
		start = start->next;
	}
	return (TRUE);
}
