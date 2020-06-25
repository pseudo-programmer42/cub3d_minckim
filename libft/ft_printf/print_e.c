/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:50:40 by minckim           #+#    #+#             */
/*   Updated: 2020/06/24 14:15:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

char	*put_point_e(t_option *o, char *s, t_big num)
{
	char	e[3];
	char	*zero;
	int		exp;
	int		exp_sign;

	zero = memset_malloc(o->precision + 1, '0');
	s = str_insert(s, zero, -1);
	free(zero);
	s = my_round(s, o->precision + 1);
	exp = ft_strlen(s) + num.exp - 2 - o->precision;
	exp_sign = exp >= 0 ? 1 : -1;
	exp = exp >= 0 ? exp : -exp;
	e[2] = 0;
	e[1] = exp % 10 + '0';
	e[0] = exp / 10 + '0';
	s = str_cut(s, 0, o->precision + 1);
	if (o->precision || o->extra)
		s = str_insert(s, ".", 1);
	if (exp_sign > 0)
		s = str_insert(s, "e+", -1);
	else
		s = str_insert(s, "e-", -1);
	s = str_insert(s, e, -1);
	return (s);
}

void	print_e(t_option *o, va_list *ap, int *res)
{
	t_big	num;
	char	*str;

	if (o->specifier != 'e')
		return ;
	if (o->precision == -1)
		o->precision = 6;
	num = float_big(va_arg(*ap, double));
	str = big_str(num);
	str = put_point_e(o, str, num);
	str = apply_sign_f(o, str, &num);
	str = apply_zero_arr_width_f(o, str);
	*res = count_putstr(str);
	free(str);
}
