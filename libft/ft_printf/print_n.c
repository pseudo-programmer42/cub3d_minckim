/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:50:54 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 03:06:09 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

void	print_n(t_option *o, va_list *ap, int *res)
{
	int	*read_char;

	if (o->specifier != 'n')
		return ;
	read_char = va_arg(*ap, int*);
	*read_char = (int)*res;
}

char	*apply_zero_p(t_option *o, char *s)
{
	int		len;
	char	*space;

	len = o->width - ft_strlen(s);
	if (len <= 0 || !o->zero || o->precision != -1 || o->arrange)
		return (s);
	space = memset_malloc(len, '0');
	s = str_insert(s, space, 0);
	free(space);
	return (s);
}

void	print_percent(t_option *o, int *res)
{
	char	*str;

	if (o->specifier != '%')
		return ;
	str = ft_strdup("%");
	str = apply_zero_p(o, str);
	str = apply_arrange(o, str);
	*res = count_putstr(str);
	free(str);
}
