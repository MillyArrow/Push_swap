/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:33:33 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:33:35 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void		push_swap(t_data *ptr)
{
	valid(ptr);
	t_stack *start = ptr->a;
	t_stack *end = ptr->a->prev;
	ptr->do_write = 1;
	int len = stack_len(ptr,'a');
	if (sorted(ptr) || len == 1)
		return ;
/*	ft_printf("MID NUMBER = %d\n", mid_number(ptr,'a'));
	while (start)
	{
		ft_printf("%d\n", start->nbr);
		if (start == end)
			break;
		start = start->next;
	}
	ft_printf("start sort\n");*/
	if (len <= 5)
		small_cases(ptr);
	else if (len <= 100)
		sort_hundred(ptr);
	else
		sort_big(ptr);
	if (sorted(ptr))
		ft_printf("SORTED\n");
	start = ptr->a;
	end = ptr->a->prev;
	while (start)
	{
		ft_printf("%d\n", start->nbr);
		if (start == end)
			break;
		start = start->next;
	}
}
