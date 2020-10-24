/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 02:56:18 by marrow            #+#    #+#             */
/*   Updated: 2020/10/24 03:42:18 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *s)
{
	int i;

	i = 0;
	if (!s || !*s)
		return (FALSE);
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (i == 0 && s[++i])
				;
			else
				return (FALSE);
		}
		if (!ft_isdigit(s[i]))
			return (FALSE);
		++i;
	}
	return(TRUE);
}
