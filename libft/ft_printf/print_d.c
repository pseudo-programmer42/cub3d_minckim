/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:49:56 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 03:06:09 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

char	*apply_arrange(t_option *o, char *s)
{
	int		len;
	char	*space;

	len = o->width - ft_strlen(s);
	if (len <= 0)
		return (s);
	space = memset_malloc(len, ' ');
	if (o->arrange == '-')
		s = str_insert(s, space, -1);
	else
		s = str_insert(s, space, 0);
	free(space);
	return (s);
}

char	*apply_zero_d(t_option *o, char *s)
{
	int		len;
	char	*space;

	len = o->width - ft_strlen(s);
	if (len <= 0 || !o->zero || o->precision != -1 || o->arrange)
		return (s);
	space = memset_malloc(len, '0');
	if (is_in(*s, " +-"))
		s = str_insert(s, space, 1);
	else
		s = str_insert(s, space, 0);
	free(space);
	return (s);
}

char	*apply_precision_d(t_option *o, char *s)
{
	char	*tmp;
	int		len;
	int		num_of_0;

	len = ft_strlen(s);
	if (is_in(*s, " +-"))
		num_of_0 = o->precision - len + 1;
	else
		num_of_0 = o->precision - len;
	if (num_of_0 > 0)
	{
		tmp = memset_malloc(num_of_0, '0');
		if (is_in(*s, " +-"))
			s = str_insert(s, tmp, 1);
		else
			s = str_insert(s, tmp, 0);
		free(tmp);
		return (s);
	}
	else
		return (s);
}

char	*apply_sign(t_option *o, char *s)
{
	if (is_in(o->specifier, "uxXcs"))
		return (s);
	if (*s != '-' && o->sign == '+')
		s = str_insert(s, "+", 0);
	else if (*s != '-' && o->sign == ' ')
		s = str_insert(s, " ", 0);
	return (s);
}

void	print_di(t_option *o, va_list *ap, int *res)
{
	char	*str;

	if (o->specifier != 'd' && o->specifier != 'i')
		return ;
	str = s_str(va_arg(*ap, ssize_t), "0123456789", o);
	if (*str == '0' && o->precision == 0)
		*str = 0;
	str = apply_sign(o, str);
	str = apply_precision_d(o, str);
	str = apply_zero_d(o, str);
	str = apply_arrange(o, str);
	*res = count_putstr(str);
	free(str);
}
