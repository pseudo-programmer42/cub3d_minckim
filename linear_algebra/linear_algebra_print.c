/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:36:50 by minckim           #+#    #+#             */
/*   Updated: 2020/07/19 16:05:13 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "linear_algebra.h"
#define WD 15
#define PR 0

void	vec_print(t_vec *a)
{
	ft_printf("% 15.0f % 15.0f % 15.0f\n", a->x, a->y, a->z);
}

void	mat_print(t_mat *a)
{
	ft_printf("% 15.0f % 15.0f % 15.0f\n", a->a, a->b, a->c);
	ft_printf("% 15.0f % 15.0f % 15.0f\n", a->d, a->e, a->f);
	ft_printf("% 15.0f % 15.0f % 15.0f\n", a->g, a->h, a->i);
	ft_printf("-----------------------------------------\n");
}

void	equation3_print(t_real *a, t_real *b, t_real *c, char *message)
{
	ft_printf("% 15.0f % 15.0f % 15.0f | % 15.0f\n", a[0], a[1], a[2], a[3]);
	ft_printf("% 15.0f % 15.0f % 15.0f | % 15.0f\n", b[0], b[1], b[2], b[3]);
	ft_printf("% 15.0f % 15.0f % 15.0f | % 15.0f\n", c[0], c[1], c[2], c[3]);
	ft_printf("%s-----------\n\n", message);
}

void	equation2_print(t_real *a, t_real *b, char *message)
{
	ft_printf("% 15.0f % 15.0f | % 15.0f\n", a[0], a[1], a[2]);
	ft_printf("% 15.0f % 15.0f | % 15.0f\n", b[0], b[1], b[2]);
	ft_printf("%s-----------\n\n", message);
}
