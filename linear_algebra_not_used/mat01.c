/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:28:15 by minckim           #+#    #+#             */
/*   Updated: 2020/07/07 04:34:01 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

t_vec	vec_mat(t_mat m, t_vec v)
{
	t_vec	r;

	r.x = m.a * v.x + m.b * v.y + m.c * v.z;
	r.y = m.d * v.x + m.e * v.y + m.f * v.z;
	r.z = m.g * v.x + m.h * v.y + m.i * v.z;
	return (r);
}

t_mat	mat_transpose(t_mat a)
{
	t_mat	r;

	r.a = a.a;
	r.b = a.d;
	r.c = a.g;
	r.d = a.b;
	r.e = a.e;
	r.f = a.h;
	r.g = a.c;
	r.h = a.f;
	r.i = a.i;
	return (r);
}

t_mat	mat_inverse(t_mat m)
{
	real	det;
	t_mat	r;

	r.a = m.e * m.i - m.f * m.h;
	r.b = m.h * m.c - m.i * m.b;
	r.c = m.b * m.f - m.c * m.e;
	r.d = m.f * m.g - m.d * m.i;
	r.e = m.i * m.a - m.g * m.c;
	r.f = m.c * m.d - m.a * m.f;
	r.g = m.d * m.h - m.e * m.g;
	r.h = m.g * m.b - m.h * m.a;
	r.i = m.a * m.e - m.b * m.d;
	det = m.a * r.a + m.d * r.b + m.g * r.c;
	m.a = r.a / det;
	m.b = r.b / det;
	m.c = r.c / det;
	m.d = r.d / det;
	m.e = r.e / det;
	m.f = r.f / det;
	m.g = r.g / det;
	m.h = r.h / det;
	m.i = r.i / det;
	return (m);
}

t_mat	mat_rot(real ah, real av)
{
	real	ch;
	real	sh;
	real	cv;
	real	sv;
	t_mat	r;

	ch = cos(ah);
	sh = sin(ah);
	cv = cos(av);
	sv = sin(av);
	r.a = ch * cv;
	return (r);
}
