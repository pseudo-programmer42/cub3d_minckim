/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:51:11 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 03:06:09 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

char	*apply_zero_x(t_option *o, char *s)
{
	int		len;
	char	*space;

	len = o->width - ft_strlen(s);
	if (len <= 0 || !o->zero || o->precision != -1 || o->arrange)
		return (s);
	space = memset_malloc(len, '0');
	if (o->extra)
		s = str_insert(s, space, 2);
	else
		s = str_insert(s, space, 0);
	free(space);
	return (s);
}

char	*apply_extra_x(t_option *o, char *s)
{
	if (!o->extra)
		return (s);
	if (o->specifier == 'x' || o->specifier == 'p')
		s = str_insert(s, "0x", 0);
	else if (o->specifier == 'X')
		s = str_insert(s, "0X", 0);
	return (s);
}

void	print_x(t_option *o, va_list *ap, int *res)
{
	char	*str;

	if (o->specifier == 'x')
		str = u_str(va_arg(*ap, ssize_t), "0123456789abcdef", o);
	else if (o->specifier == 'X')
		str = u_str(va_arg(*ap, ssize_t), "0123456789ABCDEF", o);
	else
		return ;
	if (*str == '0' && o->precision == 0)
		*str = 0;
	if (*str == 0 || *str == '0')
	{
		str = apply_precision_d(o, str);
	}
	else
	{
		str = apply_precision_d(o, str);
		str = apply_extra_x(o, str);
	}
	str = apply_zero_x(o, str);
	str = apply_arrange(o, str);
	*res = count_putstr(str);
	free(str);
}
