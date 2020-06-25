/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:52:28 by minckim           #+#    #+#             */
/*   Updated: 2020/05/12 01:48:51 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

/*
** if (o.specifier == 0) err
*/

char	*get_option(const char *s, t_option *o, va_list *ap)
{
	s++;
	ft_memset(o, 0, sizeof(*o));
	s = get_flag(s, o);
	s = get_width(s, o, ap);
	s = get_precision(s, o, ap);
	s = get_length(s, o);
	if (is_in(*s, FT_PRINTF_SPECIFIER))
		o->specifier = *(s);
	else
		o->specifier = 0;
	return ((char*)s);
}

char	*get_flag(const char *s, t_option *o)
{
	while (is_in(*s, "+ #0-"))
	{
		if (*s == '+')
			o->sign = '+';
		else if (*s == ' ' && o->sign != '+')
			o->sign = ' ';
		else if (*s == '0')
			o->zero = '0';
		else if (*s == '#')
			o->extra = '#';
		else if (*s == '-')
			o->arrange = '-';
		(s)++;
	}
	return ((char*)s);
}

char	*get_width(const char *s, t_option *o, va_list *ap)
{
	if (*s == '*')
	{
		o->width = va_arg(*ap, int);
		s++;
	}
	else
	{
		while (is_in(*s, "0123456789"))
		{
			o->width = o->width * 10 + *s++ - '0';
		}
	}
	return ((char*)s);
}

char	*get_precision(const char *s, t_option *o, va_list *ap)
{
	o->precision = -1;
	if (*s == '.')
	{
		o->precision = 0;
		s++;
		if (*s == '*')
		{
			o->precision = va_arg(*ap, int);
			s++;
		}
		while (is_in(*s, "0123456789"))
		{
			o->precision = o->precision * 10 + *s++ - '0';
		}
	}
	return ((char*)s);
}

char	*get_length(const char *s, t_option *o)
{
	ft_memset(&o->length, 0, sizeof(o->length));
	if (*s == 'l')
	{
		ft_memset(&o->length, 0xff, sizeof(long));
		s++;
		if (*s == 'l')
		{
			ft_memset(&o->length, 0xff, sizeof(long long));
			s++;
		}
	}
	else if (*s == 'h')
	{
		s++;
		if (*s == 'h')
		{
			ft_memset(&o->length, 0xff, sizeof(char));
			s++;
		}
		else
			ft_memset(&o->length, 0xff, sizeof(short));
	}
	else
		ft_memset(&o->length, 0xff, sizeof(int));
	return ((char*)s);
}
