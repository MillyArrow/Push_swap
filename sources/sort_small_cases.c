/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:34:31 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:34:33 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		case_for_two(t_data *ptr)
{
	if (ptr->a->nbr > ptr->a->next->nbr)
		do_sa(ptr);
}

static void		case_for_three(t_data *ptr)
{
	int		a;
	int		b;
	int		c;

	if (sorted(ptr))
		return ;
	a = ptr->a->nbr;
	b = ptr->a->next->nbr;
	c = ptr->a->next->next->nbr;
	if (a < b && a < c && b > c)
	{
		do_rra(ptr);
		do_sa(ptr);
	}
	else if (a > b && a < c && b < c)
		do_sa(ptr);
	else if (a < b && a > c && b > c)
		do_rra(ptr);
	else if (a > b && a > c && b < c)
		do_ra(ptr);
	else if (a > b && a > c && b > c)
	{
		do_ra(ptr);
		do_sa(ptr);
	}
}

static void		case_for_four(t_data *ptr)
{
	int min;
	int	i;
	int len;

	min = min_stack(ptr->a);
	len = stack_len(ptr,'a');
	i = -1;
	while (++i < len)
	{
		if (ptr->a->nbr == min)
			do_pb(ptr);
		else
			do_ra(ptr);
	}
	case_for_three(ptr);
	do_pa(ptr);
}

static void		case_for_five(t_data *ptr)
{
	int		i;
	int		mid_num;
	int		len;

	i = -1;
	len = stack_len(ptr,'a');
	mid_num = mid_number(ptr,'a');
	while(++i < len)
	{
		if (ptr->a->nbr <= mid_num)
			do_pb(ptr);
		else
			do_ra(ptr);
	}
	case_for_three(ptr);
	if (ptr->b->nbr < ptr->b->next->nbr)
		do_sb(ptr);
	do_pa(ptr);
	do_pa(ptr);
}

void			sort_small_cases(t_data *ptr)
{
	int len;

	len = stack_len(ptr,'a');
	if (!ptr->a)
		ft_error(ptr);
	if (len == 2)
		case_for_two(ptr);
	if (len == 3)
		case_for_three(ptr);
	if (len == 4)
		case_for_four(ptr);
	if (len == 5)
		case_for_five(ptr);
}
