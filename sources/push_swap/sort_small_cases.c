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

void		two(t_data *ptr)
{
	if (ptr->a->nbr > ptr->a->next->nbr)
		sa(ptr);
}

void		three(t_data *ptr)
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
		rra(ptr);
		sa(ptr);
	}
	else if (a > b && a < c && b < c)
		sa(ptr);
	else if (a < b && a > c && b > c)
		rra(ptr);
	else if (a > b && a > c && b < c)
		ra(ptr);
	else if (a > b && a > c && b > c)
	{
		ra(ptr);
		sa(ptr);
	}
}

void		four(t_data *ptr)
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
			pb(ptr);
		else
			ra(ptr);
	}
	three(ptr);
	pa(ptr);
}

void		five(t_data *ptr)
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
			pb(ptr);
		else
			ra(ptr);
	}
	three(ptr);
	if (ptr->b->nbr < ptr->b->next->nbr)
		sb(ptr);
	pa(ptr);
	pa(ptr);
}

void			small_cases(t_data *ptr)
{
	int len;

	len = stack_len(ptr,'a');
	if (!ptr->a)
		ft_error(ptr);
	if (len == 2)
		two(ptr);
	if (len == 3)
		three(ptr);
	if (len == 4)
		four(ptr);
	if (len == 5)
		five(ptr);
}
