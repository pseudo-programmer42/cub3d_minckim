/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:34:14 by minckim           #+#    #+#             */
/*   Updated: 2020/07/07 04:34:15 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

t_vec	vec_cross(t_vec a, t_vec b)
{
	t_vec	r;

	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return (r);
}

t_vec	vec_rot(t_vec v, real angle_h, real angle_v)
{
	real	ch;
	real	sh;
	real	cv;
	real	sv;
	t_vec	r;

	ch = cos(angle_h);
	sh = sin(angle_h);
	cv = cos(angle_v);
	sv = sin(angle_v);
	r.x = ch * cv * v.x - sh * v.y - ch * sv * v.z;
	r.y = sh * cv * v.x + ch * v.y - sh * sv * v.z;
	r.z = sv * v.x + cv * v.z;
	return (r);
}

t_vec	vec_mul(t_vec a, real b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}
