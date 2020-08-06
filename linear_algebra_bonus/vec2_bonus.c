/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:55:17 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:22:36 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra_bonus.h"

t_vec	*vec_div(t_vec *a, t_real b)
{
	a->x /= b;
	a->y /= b;
	a->z /= b;
	return (a);
}

t_real	vec_distance2(t_vec *a, t_vec *b)
{
	t_vec	tmp;
	t_real	distance;

	tmp = *a;
	vec_sub(&tmp, b);
	distance = tmp.x * tmp.x + tmp.y * tmp.y + tmp.z * tmp.z;
	return (distance);
}

t_real	vec_distance(t_vec *a, t_vec *b)
{
	t_real	distance;

	distance = vec_distance2(a, b);
	return (sqrt(distance));
}
