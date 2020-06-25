/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:51:03 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 03:06:09 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

char	*apply_arr_width_s(t_option *o, char *s)
{
	char	*space;
	ssize_t	len;

	len = o->width - ft_strlen(s);
	if (len <= 0)
		return (s);
	space = memset_malloc(len, ' ');
	if (o->arrange)
		s = str_insert(s, space, -1);
	else
		s = str_insert(s, space, 0);
	free(space);
	return (s);
}

char	*apply_precision_s(t_option *o, char *s)
{
	if (o->precision == -1)
		return (s);
	s = str_cut(s, 0, o->precision);
	return (s);
}

void	print_s(t_option *o, va_list *ap, int *res)
{
	char	*str;

	if (o->specifier != 's')
		return ;
	str = va_arg(*ap, char*);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	str = apply_precision_s(o, str);
	str = apply_arr_width_s(o, str);
	*res = count_putstr(str);
	free(str);
}
