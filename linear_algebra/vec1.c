/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:37:32 by minckim           #+#    #+#             */
/*   Updated: 2020/07/07 04:54:45 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

t_vec	vec_cross(t_vec *a, t_vec *b)
{
	t_vec	r;

	r.x = a->y * b->z - a->z * b->y;
	r.y = a->z * b->x - a->x * b->z;
	r.z = a->x * b->y - a->y * b->x;
	return (r);
}

t_vec	*vec_rot(t_vec *a, t_real h, t_real v)
{
	t_real	ch;
	t_real	sh;
	t_real	cv;
	t_real	sv;
	t_vec	r;

	r = vec_new(a->x, a->y, a->z);
	ch = cos(h);
	sh = sin(h);
	cv = cos(v);
	sv = sin(v);
	a->x = ch * cv * r.x - sh * r.y - ch * sv * r.z;
	a->y = sh * cv * r.x + ch * r.y - sh * sv * r.z;
	a->z = sv * r.x + cv * r.z;
	return (a);
}

t_vec	*vec_rot_rc(t_vec *a, t_real h, t_real v)
{
	t_real	ch;
	t_real	sh;
	t_real	cv;
	t_real	sv;
	t_vec	r;

	r = vec_new(a->x, a->y, a->z);
	ch = cos(h);
	sh = sin(h);
	cv = cos(v);
	sv = sin(v);
	a->x = cv * ch * r.x + cv * ch * r.y + sv * r.z;
	a->y = -sh * r.x + ch * r.y;
	a->z = -sv * ch * r.x + -sv * sh * r.y + cv * r.z;
	return (a);
}

t_vec	*vec_mul(t_vec *a, t_real b)
{
	a->x *= b;
	a->y *= b;
	a->z *= b;
	return (a);
}
