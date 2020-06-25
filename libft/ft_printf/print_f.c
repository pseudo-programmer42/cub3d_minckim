/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:49:20 by minckim           #+#    #+#             */
/*   Updated: 2020/06/24 14:12:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

char	*apply_zero_arr_width_f(t_option *o, char *s)
{
	int		len;
	char	*space;

	len = ft_strlen(s);
	if (len >= o->width)
		return (s);
	if (o->zero && !o->arrange)
	{
		space = memset_malloc(o->width - len, '0');
		if (is_in(*s, " +-"))
			s = str_insert(s, space, 1);
		else
			s = str_insert(s, space, 0);
	}
	else
	{
		space = memset_malloc(o->width - len, ' ');
		if (o->arrange)
			s = str_insert(s, space, -1);
		else
			s = str_insert(s, space, 0);
	}
	free(space);
	return (s);
}

char	*apply_sign_f(t_option *o, char *s, t_big *num)
{
	if (num->sign)
		s = str_insert(s, "-", 0);
	s = apply_sign(o, s);
	return (s);
}

char	*apply_precsion_f(t_option *o, char *s)
{
	int		point;
	char	*c;
	char	*zero;

	zero = memset_malloc(o->precision + 1, '0');
	s = str_insert(s, zero, -1);
	free(zero);
	c = s;
	while (*c != '.' && *c)
		c++;
	point = c - s;
	s = my_round(s, point + o->precision + 1);
	c = s;
	while (*c != '.' && *c)
		c++;
	point = c - s;
	if (o->precision == 0 && !o->extra)
		s = str_cut(s, 0, point + o->precision);
	else
		s = str_cut(s, 0, point + o->precision + 1);
	return (s);
}

char	*put_point_f(char *s, t_big *num)
{
	int		point;
	int		len;
	char	*zero;

	len = ft_strlen(s);
	point = len + num->exp;
	if (point <= 0)
	{
		zero = memset_malloc(-point + 1, '0');
		s = str_insert(s, zero, 0);
		free(zero);
		s = str_insert(s, ".", 1);
	}
	else if (0 < point && point <= len)
	{
		s = str_insert(s, ".", point);
	}
	else if (len < point)
	{
		zero = memset_malloc(point - len, '0');
		s = str_insert(s, zero, -1);
		free(zero);
	}
	return (s);
}

void	print_f(t_option *o, va_list *ap, int *res)
{
	t_big	num;
	char	*str;

	if (o->specifier != 'f')
		return ;
	if (o->precision == -1)
		o->precision = 6;
	num = float_big(va_arg(*ap, double));
	str = big_str(num);
	str = put_point_f(str, &num);
	str = apply_precsion_f(o, str);
	str = apply_sign_f(o, str, &num);
	str = apply_zero_arr_width_f(o, str);
	*res = count_putstr(str);
	free(str);
}
