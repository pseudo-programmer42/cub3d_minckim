/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:37:29 by minckim           #+#    #+#             */
/*   Updated: 2020/07/07 04:54:19 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

t_vec	vec_new(t_real x, t_real y, t_real z)
{
	t_vec	r;

	r.x = x;
	r.y = y;
	r.z = z;
	return (r);
}

t_vec	*vec_add(t_vec *a, t_vec *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}

t_vec	*vec_sub(t_vec *a, t_vec *b)
{
	t_vec	r;

	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	return (a);
}

t_vec	*vec_inv(t_vec *a)
{
	a->x = -a->x;
	a->y = -a->y;
	a->z = -a->z;
	return (a);
}

t_real	vec_dot(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
