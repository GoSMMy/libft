/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocathern <ocathern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 08:51:00 by ocathern          #+#    #+#             */
/*   Updated: 2019/11/29 08:51:15 by ocathern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*len_calc(va_list *ap, int n)
{
	int			i;
	char		*s;
	va_list		aplen;
	size_t		len;

	va_copy(aplen, *ap);
	i = -1;
	len = 0;
	while (++i < n)
	{
		s = va_arg(aplen, char *);
		len += ft_strlen(s);
	}
	va_end(aplen);
	if (!(s = ft_strnew(len + 1)))
		return (NULL);
	return (s);
}

char			*ft_strnjoin(int n, ...)
{
	int			i;
	va_list		ap;
	char		*s;
	char		*add_me;

	if (!n)
		return (NULL);
	va_start(ap, n);
	if (!(s = len_calc(&ap, n)))
	{
		va_end(ap);
		return (NULL);
	}
	i = -1;
	while (++i < n)
	{
		add_me = va_arg(ap, char *);
		ft_strcat(s, add_me);
	}
	va_end(ap);
	return (s);
}
