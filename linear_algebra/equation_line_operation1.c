/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_line_operation1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 00:26:56 by minckim           #+#    #+#             */
/*   Updated: 2020/07/16 00:37:59 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

void	line_sub3(t_real *a, t_real *b)
{
	a[1] -= b[1];
	a[2] -= b[2];
	a[3] -= b[3];
	a[0] = 0;
}

void	line_sub2(t_real *a, t_real *b)
{
	a[1] -= b[1];
	a[2] -= b[2];
	a[0] = 0;
}

int		equation2(t_real *a, t_real *b)
{
	if (!(*a) && !(*b))
		return (0);
	if (!(*a) && *b)
		return (equation2(b, a));
	if (*a && *a != 1)
		line_div2(a, *a);
	if (*b && *b != 1)
		line_div2(b, *b);
	if (*b)
		line_sub2(b, a);
	if (!b[1])
		return (0);
	b[2] /= b[1];
	b[1] = 1;
	a[2] -= b[2] * a[1];
	a[1] = 0;
	return (1);
}

void	line_swap(t_real **a, t_real **b)
{
	t_real *tmp;

	tmp = *a;
	*a = *b;
	*b = *a;
}
