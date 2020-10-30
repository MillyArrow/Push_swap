/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:32:22 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 13:33:33 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		instruction(t_data *ptr, char *line)
{
	if (!ft_strcmp(line, "ss") && (ptr->line = "ss"))
		ss(ptr);
	else if (!ft_strcmp(line, "rra") && (ptr->line = "rra"))
		rra(ptr);
	else if (!ft_strcmp(line, "rrb") && (ptr->line = "rrb"))
		rrb(ptr);
	else if (!ft_strcmp(line, "rrr") && (ptr->line = "rrr"))
		rrr(ptr);
	else if (!ft_strcmp(line, "pa") && (ptr->line = "pa"))
		pa(ptr);
	else if (!ft_strcmp(line, "pb") && (ptr->line = "pb"))
		pb(ptr);
	else if (!ft_strcmp(line, "ra") && (ptr->line = "ra"))
		ra(ptr);
	else if (!ft_strcmp(line, "rb") && (ptr->line = "rb"))
		rb(ptr);
	else if (!ft_strcmp(line, "rr") && (ptr->line = "rr"))
		rr(ptr);
	else if (!ft_strcmp(line, "sa") && (ptr->line = "sa"))
		sa(ptr);
	else if (!ft_strcmp(line, "sb") && (ptr->line = "sb"))
		sb(ptr);
	else
		return (FALSE);
	return (TRUE);
}
