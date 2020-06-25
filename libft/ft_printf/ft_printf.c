/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:51:59 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 02:17:38 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

ssize_t	print_num(t_option *o, va_list *ap, int *n)
{
	int	res;

	res = 0;
	print_di(o, ap, &res);
	print_x(o, ap, &res);
	print_u(o, ap, &res);
	print_p(o, ap, &res);
	print_c(o, ap, &res);
	print_s(o, ap, &res);
	print_f(o, ap, &res);
	print_e(o, ap, &res);
	print_g(o, ap, &res);
	print_n(o, ap, n);
	print_percent(o, &res);
	return (res);
}

int		print_normal_str(const char **s)
{
	int	n;

	n = 0;
	while (**s && **s != '%')
	{
		if (write(1, *s, 1) < 0)
			return (-1);
		(*s)++;
		n++;
	}
	return (n);
}

int		ft_printf(const char *s, ...)
{
	int			n;
	int			tmp;
	t_option	o;
	va_list		ap;

	va_start(ap, s);
	n = 0;
	while (*s)
	{
		if ((tmp = print_normal_str(&s)) < 0)
			return (-1);
		n += tmp;
		if (*s == '%')
		{
			s = get_option(s, &o, &ap);
			if (o.specifier == 0)
				return (-1);
			if ((tmp = print_num(&o, &ap, &n)) < 0)
				return (-1);
			n += tmp;
			s++;
		}
	}
	va_end(ap);
	return (n);
}
