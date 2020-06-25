/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:51:23 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 02:17:38 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

void	bigmul(t_big *a, size_t b)
{
	int		i;

	i = -1;
	while (++i < FT_PRINTF_BIG_RANGE)
		a->n[i] *= b;
	i = -1;
	while (++i < FT_PRINTF_BIG_RANGE)
	{
		if (a->n[i] > 99999999)
		{
			a->n[i + 1] += a->n[i] / 100000000;
			a->n[i] = a->n[i] % 100000000;
		}
	}
}

t_big	bigadd(t_big a, t_big b)
{
	int		i;
	size_t	tmp;
	t_big	res;

	ft_memset(&res, 0, sizeof(res));
	i = -1;
	res.n[0] = 0;
	while (++i < FT_PRINTF_BIG_RANGE)
	{
		tmp = a.n[i] + b.n[i] + res.n[i];
		if (99999999 < tmp)
		{
			res.n[i] = tmp % 100000000;
			res.n[i + 1] = tmp / 100000000;
		}
		else
		{
			res.n[i] = tmp;
		}
	}
	return (res);
}

char	*my_round(char *s, int i)
{
	if (s[i] >= '5')
	{
		s[i--] = '0';
		if (s[i] == '.')
			i--;
		s[i]++;
	}
	while (i >= 0 && s[i] > '9')
	{
		if (i == 0)
		{
			s = str_insert(s, "0", 0);
			i = 1;
		}
		s[i--] = '0';
		if (s[i] == '.')
			i--;
		s[i]++;
	}
	return (s);
}
