/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:38:43 by minckim           #+#    #+#             */
/*   Updated: 2020/07/13 05:38:12 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_face	face_new(t_vec *a, t_vec *b, t_vec *c, int type)
{
	t_face	r;

	r.a = *a;
	r.b = *b;
	r.c = *c;
	r.u = *b;
	r.v = *c;
	vec_sub(&r.u, a);
	vec_sub(&r.v, a);
	r.n = vec_cross(&r.u, &r.v);
	vec_unit(&r.n);
	r.color = DEF_COLOR;
	r.img = 0;
	r.type = type;
	return (r);
}

t_face	face_copy(t_face *f, t_vec *v)
{
	t_face		r;

	r = *f;
	vec_add(&r.a, v);
	vec_add(&r.b, v);
	vec_add(&r.c, v);
	return (r);
}

t_face	*face_move(t_face *f, t_vec *v)
{
	vec_add(&(f->a), v);
	vec_add(&(f->b), v);
	vec_add(&(f->c), v);
	return (f);
}

t_face	*face_rot(t_face *f, t_vec *center, t_real h, t_real v)
{
	t_mat	mat_r;

	vec_sub(&(f->a), center);
	vec_sub(&(f->b), center);
	vec_sub(&(f->c), center);
	mat_r = mat_rot(h, v);
	mat_vec(&mat_r, &(f->a));
	mat_vec(&mat_r, &(f->b));
	mat_vec(&mat_r, &(f->c));
	vec_add(&(f->a), center);
	vec_add(&(f->b), center);
	vec_add(&(f->c), center);
	mat_vec(&mat_r, &(f->u));
	mat_vec(&mat_r, &(f->v));
	mat_vec(&mat_r, &(f->n));
	return (f);
}

t_face	*face_rot_rc(t_face *f, t_vec *center, t_real h, t_real v)
{
	t_mat	mat_r;

	vec_sub(&(f->a), center);
	vec_sub(&(f->b), center);
	vec_sub(&(f->c), center);
	mat_r = mat_rot_rc(h, v);
	mat_vec(&mat_r, &(f->a));
	mat_vec(&mat_r, &(f->b));
	mat_vec(&mat_r, &(f->c));
	mat_vec(&mat_r, &(f->u));
	mat_vec(&mat_r, &(f->v));
	mat_vec(&mat_r, &(f->n));
	return (f);
}