/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:51:50 by minckim           #+#    #+#             */
/*   Updated: 2020/06/24 16:38:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTIL_H
# define FT_PRINTF_UTIL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft.h"
# define FT_PRINTF_SPECIFIER "cspdiuxX%nfeg"
# define FT_PRINTF_BIG_RANGE 100

typedef struct	s_option{
	int			sign;
	int			arrange;
	int			zero;
	int			extra;
	int			width;
	int			precision;
	size_t		length;
	int			specifier;
}				t_option;

char			*get_option(const char *s, t_option *o, va_list *ap);
char			*get_flag(const char *s, t_option *o);
char			*get_width(const char *s, t_option *o, va_list *ap);
char			*get_precision(const char *s, t_option *o, va_list *ap);
char			*get_length(const char *s, t_option *o);

/*
**big numbers
*/
typedef struct	s_big{
	int			sign;
	int			exp;
	size_t		mts;
	char		*str;
	size_t		n[FT_PRINTF_BIG_RANGE];
}				t_big;
/*
**convert
*/
char			*u_str(size_t h, char *base, t_option *o);
char			*s_str(ssize_t h, char *base, t_option *o);
char			*big_str(t_big digit);
ssize_t			count_putstr(char *str);
t_big			float_big(double f);
t_big			mts_big(size_t a, int e);
char			*int_str(ssize_t h, char *base);
ssize_t			str_int(char *s, char *base);
char			*float_str(double f);
void			bigmul(t_big *a, size_t b);
void			str_add(char *s1, char *s2);
char			*my_round(char *s, int i);

/*
**util
*/
int				is_in(char c, char *str);
char			*str_insert(char *d, char *s, int i);
char			*str_cut(char *d, int a, int b);
char			*memset_malloc(size_t n, char d);
char			*put_point(char *d, int exp);
char			*get_option(const char *s, t_option *o, va_list *ap);
ssize_t			print_num(t_option *o, va_list *ap, int *n);
void			print_di(t_option *o, va_list *ap, int *res);
void			print_x(t_option *o, va_list *ap, int *res);
void			print_u(t_option *o, va_list *ap, int *res);
void			print_p(t_option *o, va_list *ap, int *res);
void			print_c(t_option *o, va_list *ap, int *res);
void			print_s(t_option *o, va_list *ap, int *res);
void			print_f(t_option *o, va_list *ap, int *res);
void			print_e(t_option *o, va_list *ap, int *res);
void			print_g(t_option *o, va_list *ap, int *res);
void			print_n(t_option *o, va_list *ap, int *res);
void			print_percent(t_option *o, int *res);
char			*apply_precision_d(t_option *o, char *s);
char			*apply_zero_d(t_option *o, char *s);
char			*apply_arrange(t_option *o, char *s);
char			*apply_zero_x(t_option *o, char *s);
char			*put_point_f(char *s, t_big *num);
char			*apply_zero_arr_width_d(t_option *o, char *s);
char			*apply_extra_x(t_option *o, char *s);
char			*apply_sign(t_option *o, char *s);
char			*apply_sign_f(t_option *o, char *s, t_big *num);
char			*apply_zero_arr_width_f(t_option *o, char *s);
#endif
