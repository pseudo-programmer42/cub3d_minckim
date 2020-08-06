/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 01:18:46 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:53:39 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

char	*float_str(double f)
{
	size_t	*t;
	int		exp;
	size_t	mts;
	t_big	num;

	t = (size_t*)&f;
	exp = ((*t & 0x7ff0000000000000L) >> 52) - ((1 << 10) - 1);
	mts = (*t & 0x000fffffffffffffL) + (1L << 52);
	num = mts_big(mts, exp);
	return (big_str(num));
}

char	*big_str(t_big digit)
{
	int		i;
	char	*curr;
	char	*prev;
	char	*tmp;

	i = FT_PRINTF_BIG_RANGE - 1;
	while (i && !digit.n[i])
		i--;
	prev = int_str(digit.n[i--], "0123456789");
	while (i >= 0)
	{
		curr = memset_malloc(8, '0');
		tmp = curr + 7;
		while (digit.n[i])
		{
			*tmp-- = digit.n[i] % 10 + '0';
			digit.n[i] /= 10;
		}
		prev = str_insert(prev, curr, -1);
		free(curr);
		i--;
	}
	return (prev);
}

char	*put_point(char *d, int exp)
{
	int		idx_point;
	char	*set_of_0;
	char	*res;

	idx_point = 0;
	while (d[idx_point] && d[idx_point] != '.')
		idx_point++;
	if (idx_point + exp > 0)
		res = str_insert(d, ".", exp - 1);
	else
	{
		set_of_0 = memset_malloc(-exp + 1 - idx_point, '0');
		res = str_insert(d, set_of_0, 0);
		res = str_insert(res, ".", exp - 1);
		free(set_of_0);
	}
	return (res);
}

t_big	float_big(double f)
{
	size_t	*t;
	t_big	num;
	int		i;

	ft_memset(&num, 0, sizeof(num));
	t = (size_t*)&f;
	num.sign = *t >> 63;
	num.exp = ((*t & 0x7ff0000000000000L) >> 52) - ((1 << 10) - 1);
	num.mts = (*t & 0x000fffffffffffffL) + (1L << 52);
	num.n[0] = num.mts % 100000000L;
	num.n[1] = num.mts / 100000000L;
	if (num.exp < 52)
	{
		i = num.exp;
		while (i++ < 52)
			bigmul(&num, 5);
	}
	else
	{
		i = 52;
		while (i++ < num.exp)
			bigmul(&num, 2);
	}
	num.exp = num.exp > 52 ? 0 : num.exp - 52;
	return (num);
}

t_big	mts_big(size_t a, int e)
{
	t_big	res;
	int		i;

	ft_memset(&res, 0, sizeof(res));
	res.n[0] = a % 100000000L;
	res.n[1] = a / 100000000L;
	res.exp = e - 52;
	if (e < 52)
	{
		i = e;
		while (i++ < 52)
			bigmul(&res, 5);
	}
	else
	{
		i = 52;
		while (i++ < e)
			bigmul(&res, 2);
	}
	return (res);
}
