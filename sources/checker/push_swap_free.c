/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:33:24 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 13:28:01 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			free_stack(t_stack *stack)
{
	t_stack		*track_next;
	t_stack		*delete;

	if (stack)
	{
		track_next = stack->next;
		while (track_next != stack)
		{
			delete = track_next;
			track_next = track_next->next;
			free(delete);
		}
		free(track_next);
	}
}

void			free_data(t_data *ptr)
{
	if (ptr)
	{
		if (ptr->a)
			free_stack(ptr->a);
		if (ptr->b)
			free_stack(ptr->b);
		free(ptr);
	}
}

void			push_swap_free(t_data *ptr)
{
	free_data(ptr);
}
