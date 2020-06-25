/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:49:46 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 02:17:38 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

void	print_null(t_option *o, int *res)
{
	char	*str;

	if (o->width)
	{
		str = memset_malloc(o->width - 1, ' ');
		if (o->arrange == '-')
		{
			write(1, "\0", 1);
			*res = count_putstr(str) + 1;
		}
		else
		{
			*res = count_putstr(str) + 1;
			write(1, "\0", 1);
		}
		free(str);
	}
	else
	{
		write(1, "\0", 1);
		(*res)++;
	}
}

void	print_c(t_option *o, va_list *ap, int *res)
{
	char	*str;
	char	c;

	if (o->specifier != 'c')
		return ;
	c = va_arg(*ap, int);
	if (!c)
	{
		print_null(o, res);
		return ;
	}
	if (o->width)
	{
		str = memset_malloc(o->width, ' ');
		if (o->arrange == '-')
			*str = c;
		else
			str[o->width - 1] = c;
	}
	else
		str = memset_malloc(1, c);
	*res = count_putstr(str);
	free(str);
}
