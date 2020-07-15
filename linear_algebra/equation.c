/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 00:26:56 by minckim           #+#    #+#             */
/*   Updated: 2020/07/16 00:35:23 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

int		equation3(t_real *a, t_real *b, t_real *c)
{
	if (!(*a) && !(*b) && !(*c))
		return (0);
	if (!(*a))
		return (equation3(b, c, a));
	if (*a && *a != 1)
		line_div3(a, *a);
	if (*b && *b != 1)
		line_div3(b, *b);
	if (*c && *c != 1)
		line_div3(c, *c);
	if (*c)
		line_sub3(c, a);
	if (*b)
		line_sub3(b, a);
	if (!(equation2(b + 1, c + 1)))
		return (0);
	if (c[3] < 0 || 1 < c[3] || b[3] < 0 || 1 < b[3])
		return (0);
	if (b[1])
		a[3] -= a[1] * b[3] + a[2] * c[3];
	else
		a[3] -= a[2] * b[3] + a[1] * c[3];
	a[1] = 0;
	a[2] = 0;
	return (1);
}

t_vec	arrange_answer(t_real *a, t_real *b, t_real *c)
{
	if (*a)
	{
		if (b[1] && c[2])
			return (vec_new(a[3], b[3], c[3]));
		return (vec_new(a[3], c[3], b[3]));
	}
	if (*b)
	{
		if (a[1] && c[2])
			return (vec_new(b[3], a[3], c[3]));
		return (vec_new(b[3], c[3], a[3]));
	}
	if (a[1] && b[2])
		return (vec_new(c[3], a[3], b[3]));
	return (vec_new(c[3], b[3], a[3]));
}

t_vec	equation_vector(t_vec *u, t_vec *v, t_vec *r, t_vec *x)
{
	t_real	a[4];
	t_real	b[4];
	t_real	c[4];

	a[0] = u->x;
	a[1] = v->x;
	a[2] = r->x;
	a[3] = x->x;
	b[0] = u->y;
	b[1] = v->y;
	b[2] = r->y;
	b[3] = x->y;
	c[0] = u->z;
	c[1] = v->z;
	c[2] = r->z;
	c[3] = x->z;
	if (equation3(a, b, c))
		return (arrange_answer(a, b, c));
	else
		return (vec_new(-1, -1, -1));
}
