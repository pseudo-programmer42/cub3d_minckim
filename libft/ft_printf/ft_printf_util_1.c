/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 01:38:30 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 02:18:06 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

int			is_in(char c, char *str)
{
	while (*str)
		if (c == *str++)
			return (c);
	return (0);
}

ssize_t		count_putstr(char *str)
{
	int		n;

	n = 0;
	while (*str)
	{
		if (write(1, str++, 1) < 0)
		{
			return (-1);
		}
		n++;
	}
	return (n);
}

char		*str_insert(char *d, char *s, int i)
{
	char	*d_orig;
	char	*r;
	char	*c;

	if (i < 0)
		i = ft_strlen(d) + i + 1;
	if (!(r = (char*)malloc(sizeof(char) * (ft_strlen(d) + ft_strlen(s) + 1))))
		return (0);
	d_orig = d;
	c = r;
	while (*d && i--)
		*c++ = *d++;
	while (*s)
		*c++ = *s++;
	while (*d)
		*c++ = *d++;
	*c = 0;
	free(d_orig);
	return (r);
}

char		*str_cut(char *d, int a, int b)
{
	char	*d_orig;
	char	*r;
	char	*c;
	int		size;

	size = b > a ? b - a : a - b;
	if (!(r = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	c = r;
	d_orig = d;
	d += a;
	if (b > a)
		while (size-- && *d)
			*c++ = *d++;
	else
		while (size-- && d != d_orig)
			*c++ = *d--;
	*c = 0;
	free(d_orig);
	return (r);
}

char		*memset_malloc(size_t n, char d)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (n + 1))))
		return (0);
	ft_memset(res, d, n * sizeof(char));
	*(res + n) = 0;
	return (res);
}
