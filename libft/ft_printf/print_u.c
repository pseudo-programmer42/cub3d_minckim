/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:51:06 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 02:17:38 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

void	print_u(t_option *o, va_list *ap, int *res)
{
	char	*str;

	if (o->specifier != 'u')
		return ;
	str = u_str(va_arg(*ap, ssize_t), "0123456789", o);
	if (*str == '0' && o->precision == 0)
		*str = 0;
	str = apply_precision_d(o, str);
	str = apply_zero_d(o, str);
	str = apply_arrange(o, str);
	*res = count_putstr(str);
	free(str);
}
