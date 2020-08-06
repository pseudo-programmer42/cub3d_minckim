/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:43:21 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:22:36 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra_bonus.h"

static void	swap(t_real *a, t_real *b)
{
	t_real	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_mat		*mat_transpose(t_mat *a)
{
	swap(&a->b, &a->d);
	swap(&a->c, &a->g);
	swap(&a->f, &a->h);
	return (a);
}

t_mat		mat_new_vec(t_vec *a, t_vec *b, t_vec *c)
{
	t_mat	r;

	r.a = a->x;
	r.d = a->y;
	r.g = a->z;
	r.b = b->x;
	r.e = b->y;
	r.h = b->z;
	r.c = c->x;
	r.f = c->y;
	r.i = c->z;
	return (r);
}
