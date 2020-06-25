/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:50:50 by minckim           #+#    #+#             */
/*   Updated: 2020/06/24 14:15:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

char	*expstr(int e)
{
	char	*s;
	char	d[3];

	if (e >= 0)
	{
		e--;
		s = ft_strdup("e+");
		d[0] = e / 10 + '0';
		d[1] = e % 10 + '0';
		d[2] = 0;
	}
	else
	{
		s = ft_strdup("e-");
		d[0] = -e / 10 + '0';
		d[1] = -e % 10 + '0';
		d[2] = 0;
	}
	return (str_insert(s, d, -1));
}

char	*apply_precsion_g(t_option *o, char *s, t_big num)
{
	int		exp;
	char	*space;

	s = my_round(s, o->precision);
	exp = num.exp - o->precision + ft_strlen(s);
	s = str_cut(s, 0, o->precision);
	if ((-exp > o->precision) || (exp > o->precision))
	{
		space = expstr(exp);
		s = str_insert(s, ".", 1);
		s = str_insert(s, space, -1);
		free(space);
	}
	else if (exp <= 0)
	{
		space = memset_malloc(-exp + 1, '0');
		space = str_insert(space, ".", 1);
		s = str_insert(s, space, 0);
		free(space);
	}
	if (o->extra || (size_t)exp != ft_strlen(s))
	{
		s = str_insert(s, ".", exp);
	}
	return (s);
}

char	*apply_extra_f(t_option *o, char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!o->extra && is_in('.', s))
	{
		i = ft_strlen(s) - 1;
		while (s[i] == '0')
			s[i++] = 0;
		if (s[i] == '.')
			s[i] = 0;
	}
	if (!o->extra && is_in('e', s))
	{
		i = o->precision;
		tmp = str_cut(ft_strdup(s), i + 1, ft_strlen(s));
		s[i + 1] = 0;
		while (s[i] == '0')
			s[i++] = 0;
		if (s[i] == '.')
			s[i] = 0;
		s = str_insert(s, tmp, -1);
		free(tmp);
	}
	return (s);
}

void	print_g(t_option *o, va_list *ap, int *res)
{
	t_big	num;
	char	*str;
	char	*space;

	if (o->specifier != 'g')
		return ;
	if (o->precision == -1)
		o->precision = 6;
	num = float_big(va_arg(*ap, double));
	str = big_str(num);
	space = memset_malloc(o->precision, '0');
	str = str_insert(str, space, -1);
	free(space);
	str = apply_precsion_g(o, str, num);
	str = apply_extra_f(o, str);
	str = apply_sign_f(o, str, &num);
	str = apply_zero_arr_width_f(o, str);
	*res = count_putstr(str);
	free(str);
}
