/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:30:19 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:23:03 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry_bonus.h"

t_face	*face_0_rot(t_face *f, t_angle h, t_angle v)
{
	t_mat	mat_r;

	mat_r = mat_rot(h, v);
	mat_vec(&mat_r, &(f->a));
	mat_vec(&mat_r, &(f->b));
	mat_vec(&mat_r, &(f->c));
	mat_vec(&mat_r, &(f->u));
	mat_vec(&mat_r, &(f->v));
	mat_vec(&mat_r, &(f->n));
	return (f);
}

t_face	*face_0_rot_rc(t_face *f, t_angle h, t_angle v)
{
	t_mat	mat_r;

	mat_r = mat_rot_rc(h, v);
	mat_vec(&mat_r, &(f->a));
	mat_vec(&mat_r, &(f->b));
	mat_vec(&mat_r, &(f->c));
	mat_vec(&mat_r, &(f->u));
	mat_vec(&mat_r, &(f->v));
	mat_vec(&mat_r, &(f->n));
	return (f);
}

t_face	*face_mat(t_face *f, t_mat *m)
{
	mat_vec(m, &(f->a));
	mat_vec(m, &(f->b));
	mat_vec(m, &(f->c));
	mat_vec(m, &(f->u));
	mat_vec(m, &(f->v));
	mat_vec(m, &(f->n));
	return (f);
}
