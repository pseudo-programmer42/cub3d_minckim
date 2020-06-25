/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 01:16:30 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 02:17:38 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

char	*u_str(size_t h, char *base, t_option *o)
{
	int		n_sys;
	char	digit[128];
	char	*c;
	char	*res;

	h &= o->length;
	n_sys = ft_strlen(base);
	c = digit;
	*c++ = base[h % n_sys];
	h /= n_sys;
	while (h)
	{
		*c++ = base[h % n_sys];
		h /= n_sys;
	}
	if (!(res = (char*)malloc(sizeof(char) * (c - digit + 1))))
		return (0);
	*c = 0;
	n_sys = 0;
	while (digit[n_sys])
		res[n_sys++] = *--c;
	res[n_sys] = 0;
	return (res);
}

char	*s_str(ssize_t h, char *base, t_option *o)
{
	char	*res;

	h &= o->length;
	if ((size_t)h > o->length / 2)
	{
		res = u_str(-h, base, o);
		res = str_insert(res, "-", 0);
	}
	else
		res = u_str(h, base, o);
	return (res);
}

ssize_t	str_int(char *s, char *base)
{
	int		i;
	ssize_t	res;
	int		sign;
	int		n_sys;

	n_sys = ft_strlen(base);
	sign = *s == '-' ? -1 : 1;
	s = *s == '-' ? s + 1 : s;
	res = 0;
	while (is_in(*s, base))
	{
		i = -1;
		while (base[++i])
			if (*s == base[i])
				break ;
		res = res * n_sys + i * sign;
		s++;
	}
	return (res);
}

char	*int_str(ssize_t h, char *base)
{
	t_option	o;

	ft_memset(&o.length, 0xff, sizeof(size_t));
	return (s_str(h, base, &o));
}
