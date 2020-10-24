/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrow <marrow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 03:37:39 by marrow            #+#    #+#             */
/*   Updated: 2020/10/24 04:35:31 by marrow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isint(char *s)
{
	int str_len;

	if (!s || !*s)
		return (FALSE);
	str_len = ft_strlen(s);
	if (str_len > 11 || !ft_isnumber(s))
		return (FALSE);
	if (str_len == 10)
	{
		if (*s == '-' || *s == '+')
			return (TRUE);
		else if (ft_strcmp(SINT_MAX, s) < 0)
			return (FALSE);
	}
	if (str_len == 11)
	{
		if (*s == '-')
			return ((ft_strcmp(SINT_MIN, s) < 0) ? FALSE : TRUE);
		else if (*s == '+')
			return ((ft_strcmp(SINT_MAX_P, s) < 0) ? FALSE : TRUE);
		else
			return (FALSE);
	}
	return (TRUE);
}
