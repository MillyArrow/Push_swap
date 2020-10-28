/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:34:03 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:34:03 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int		partition(int *arr, int l,int r)
{
	int x;
	int less;
	int	i;

	x = arr[r];
	less = l;
	i = l;
	while(i < r)
	{
		if (arr[i] <= x)
		{
			swap(&arr[i],&arr[less]);
			++less;
		}
		++i;
	}
	swap(&arr[less],&arr[r]);
	return (less);
}

static void		quick_sort(int *arr, int l, int r)
{
	int q;

	if (l < r)
	{
		q = partition(arr, l, r);
		quick_sort(arr, l, q -1);
		quick_sort(arr,q + 1, r);
	}
}

static void		sort(int *arr, int len)
{
	int i = 0;
	if (arr)
		quick_sort(arr,0,len - 1);
}

int				mid_number(t_data *ptr, char stack_name)
{
	t_stack *start;
	t_stack *end;
	int len;
	int *arr;
	int i;

	len = stack_len(ptr,stack_name);
	if (!(arr = (int *)ft_memalloc(sizeof(int) * len)))
		ft_error(ptr);
	i = 0;
	start = ptr->a;
	end = ptr->a->prev;
	while(start)
	{
		arr[i++] = start->nbr;
		if (start == end)
			break ;
		start = start->next;
	}
	sort(arr,len);
	len = arr[(len / 2) - 1];
	free(arr);
	return (len);
}
