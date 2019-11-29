/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 07:50:35 by ocathern          #+#    #+#             */
/*   Updated: 2019/11/29 07:50:42 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static int		find_base(char c, int base)
{
	int				i;
	static char		*def = "0123456789ABCDEF";

	i = 0;
	while (i < base)
	{
		if (def[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(const char *str, int base)
{
	int ret;
	int	sign;
	int	found;

	ret = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != ' ')
	{
		found = find_base(to_upper(*str), base);
		if (found != -1)
			ret = (ret * base) + found;
		str++;
	}
	return (sign * ret);
}
