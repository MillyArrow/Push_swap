/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:28:48 by marrow            #+#    #+#             */
/*   Updated: 2020/10/30 15:28:22 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int					check_flag(char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == 'v' && !argv[1][2])
		return (TRUE);
	return (FALSE);
}

void				print_two_stacks(t_data *ptr)
{
	t_stack			*a;
	t_stack			*b;

	a = ptr->a;
	b = ptr->b;
	(ptr->line) ? ft_printf("\n  Instruction:%5s\n", ptr->line) : 0;
	ft_printf("  _______   _______\n");
	ft_printf("|    A    |    B    |\n");
	ft_printf(" __________________\n");
	while (1)
	{
		(a) ? ft_printf("|  %3d    |", a->nbr) :
		ft_printf("|    #    |");
		(b) ? ft_printf("  %3d    |\n", b->nbr) :
		ft_printf("    #    |\n");
		(a || b) ? ft_printf(" __________________\n") :
		ft_printf(" __________________\n\n\n");
		if (!a && !b)
			break ;
		a = (a && a != ptr->a->prev) ? a->next : NULL;
		b = (b && b != ptr->b->prev) ? b->next : NULL;
	}
}
