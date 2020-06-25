/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:50:58 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 02:17:38 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

void	print_p(t_option *o, va_list *ap, int *res)
{
	char	*str;

	if (o->specifier != 'p')
		return ;
	o->extra = '#';
	ft_memset(&o->length, 0xff, sizeof(void*));
	str = s_str(va_arg(*ap, size_t), "0123456789abcdef", o);
	if (*str == '0' && o->precision == 0)
		*str = 0;
	str = apply_precision_d(o, str);
	str = str_insert(str, "0x", 0);
	str = apply_sign(o, str);
	str = apply_zero_x(o, str);
	str = apply_arrange(o, str);
	*res = count_putstr(str);
	free(str);
}
