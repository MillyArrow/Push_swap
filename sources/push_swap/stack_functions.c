/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:34:12 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:34:12 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			stack_add_end(t_data *ptr, char stack_name, int n)
{
	t_stack		**top;
	t_stack		*tmp;

	top = (stack_name == 'a') ? &ptr->a : &ptr->b;
	if (*top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(ptr);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->nbr = n;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(ptr);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->nbr = n;
	}
}

void			stack_add_top(t_data *ptr, char stack_name, int n)
{
	t_stack		**top;
	t_stack		*tmp;

	top = (stack_name == 'a') ? &ptr->a : &ptr->b;
	if (*top)
	{
		if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(ptr);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->nbr = n;
		*top = (*top)->prev;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error(ptr);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->nbr = n;
	}
}

void			stack_del_top(t_data *ptr, char stack_name)
{
	t_stack		**top;
	t_stack		*tmp;

	top = (stack_name == 'a') ? &ptr->a : &ptr->b;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			*top = (*top)->next;
			tmp->prev->next = *top;
			(*top)->prev = tmp->prev;
			free(tmp);
		}
	}
}

int				max_stack(t_stack *stack)
{
	t_stack *start;
	t_stack *end;
	int max;

	start = stack;
	end = stack->prev;
	max = 0;
	while (start)
	{
		if (start->nbr > max)
			max = start->nbr;
		if (start == end)
			break ;
		start = start->next;
	}
	return (max);
}

int				min_stack(t_stack *stack)
{
	t_stack *start;
	t_stack *end;
	int min;

	start = stack;
	end = stack->prev;
	min = INT_MAX;
	while (start)
	{
		if (start->nbr < min)
			min = start->nbr;
		if (start == end)
			break ;
		start = start->next;
	}
	return (min);
}
