/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:27:23 by minckim           #+#    #+#             */
/*   Updated: 2020/07/02 04:57:58 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	*vector_new(double p0, double p1, double p2, double *r)
{
	r[0] = p0;
	r[1] = p1;
	r[2] = p2;
	return (r);
}

double	*vector_copy(double *v, double *r)
{
	r[0] = v[0];
	r[1] = v[1];
	r[2] = v[2];
	return (r);
}

double	*vector_mat_mul(double *mat, double *v)
{
	double	r[3];

	r[0] = v[0];
	r[1] = v[1];
	r[2] = v[2];
	v[0] = mat[0] * r[0] + mat[1] * r[1] + mat[2] * r[2];
	v[1] = mat[3] * r[0] + mat[4] * r[1] + mat[5] * r[2];
	v[2] = mat[6] * r[0] + mat[7] * r[1] + mat[8] * r[2];
	return (v);
}

double	*vector_rot_h(double *v, double angle)
{
	double	c;
	double	s;
	double	r[2];

	angle = angle * PI / 180;
	r[0] = v[0];
	r[1] = v[1];
	c = cos(angle);
	s = sin(angle);
	v[0] = c * r[0] - s * r[1];
	v[1] = c * r[1] + s * r[0];
	return (v);
}

double	*vector_rot_v(double *v, double angle_h, double angle_v)
{
	double	ch;
	double	sh;
	double	cv;
	double	sv;
	double	m[12];

	angle_h = angle_h * PI / 180;
	angle_v = angle_v * PI / 180;
	ch = cos(angle_h);
	sh = sin(angle_h);
	cv = cos(angle_v);
	sv = sin(angle_v);
	m[0] = ch * ch * cv + sh * sh;
	m[1] = ch * sh * cv - ch * sh;
	m[2] = -ch * sv;
	m[3] = m[1];
	m[4] = sh * sh * cv + ch * ch;
	m[5] = -sh * sv;
	m[6] = -m[2];
	m[7] = -m[5];
	m[8] = cv;
	return (vector_mat_mul(m, v));
}

double	*vector_rot(double *v, double angle_h, double angle_v)
{
	double	ch;
	double	sh;
	double	cv;
	double	sv;
	double	r[3];

	angle_h = angle_h * PI / 180;
	angle_v = angle_v * PI / 180;
	ch = cos(angle_h);
	sh = sin(angle_h);
	cv = cos(angle_v);
	sv = sin(angle_v);
	r[0] = v[0];
	r[1] = v[1];
	r[2] = v[2];
	v[0] = ch * cv * r[0] - sh * r[1] - ch * sv * r[2];
	v[1] = sh * cv * r[0] + ch * r[1] - sh * sv * r[2];
	v[2] = sv * r[0] + cv * r[2];
	return (v);
}

double	*vector_add(double *v1, double *v2)
{
	v1[0] += v2[0];
	v1[1] += v2[1];
	v1[2] += v2[2];
	return (v1);
}

double	*vector_sub(double *v1, double *v2)
{
	v1[0] -= v2[0];
	v1[1] -= v2[1];
	v1[2] -= v2[2];
	return (v2);
}