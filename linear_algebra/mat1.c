/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:37:14 by minckim           #+#    #+#             */
/*   Updated: 2020/07/07 04:56:46 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

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

t_mat		*mat_inverse(t_mat *m)
{
	t_real	det;
	t_mat	r;

	r.a = m->e * m->i - m->f * m->h;
	r.b = m->h * m->c - m->i * m->b;
	r.c = m->b * m->f - m->c * m->e;
	r.d = m->f * m->g - m->d * m->i;
	r.e = m->i * m->a - m->g * m->c;
	r.f = m->c * m->d - m->a * m->f;
	r.g = m->d * m->h - m->e * m->g;
	r.h = m->g * m->b - m->h * m->a;
	r.i = m->a * m->e - m->b * m->d;
	det = m->a * r.a + m->d * r.b + m->g * r.c;
	m->a = r.a / det;
	m->b = r.b / det;
	m->c = r.c / det;
	m->d = r.d / det;
	m->e = r.e / det;
	m->f = r.f / det;
	m->g = r.g / det;
	m->h = r.h / det;
	m->i = r.i / det;
	return (m);
}

t_mat		mat_rot(t_real ah, t_real av)
{
	t_real	ch;
	t_real	sh;
	t_real	cv;
	t_real	sv;
	t_mat	r;

	ch = cos(ah);
	sh = sin(ah);
	cv = cos(av);
	sv = sin(av);
	r.a = ch * cv;
	r.b = -sh;
	r.c = -ch * sv;
	r.d = sh * cv;
	r.e = ch;
	r.f = -sh * sv;
	r.g = sv;
	r.h = 0;
	r.i = cv;
	return (r);
}

t_mat		mat_rot_rc(t_real ah, t_real av)
{
	t_real	ch;
	t_real	sh;
	t_real	cv;
	t_real	sv;
	t_mat	r;

	ch = cos(ah);
	sh = sin(ah);
	cv = cos(av);
	sv = sin(av);
	r.a = cv * ch;
	r.b = cv * sh;
	r.c = sv;
	r.d = -sh;
	r.e = ch;
	r.f = 0;
	r.g = -sv * ch;
	r.h = -sv * sh;
	r.i = cv;
	return (r);
}
