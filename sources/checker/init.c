/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 06:32:51 by marrow            #+#    #+#             */
/*   Updated: 2020/10/28 06:32:52 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data		*initialize(t_data *ptr, char **argv)
{
	if (!(ptr = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	ptr->a = NULL;
	ptr->b = NULL;
	ptr->do_write = 0;
	ptr->argv = argv;
	ptr->flag = 0;
	ptr->min_forward = NULL;
	ptr->min_backward = NULL;
	ptr->min_next = 0;
	ptr->min_prev = 0;
	ptr->min_push = 0;
	ptr->max_forward = NULL;
	ptr->max_backward = NULL;
	ptr->max_next = 0;
	ptr->max_prev = 0;
	ptr->rotate = 0;
	return (ptr);
}
