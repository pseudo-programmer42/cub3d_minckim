/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:43:21 by minckim           #+#    #+#             */
/*   Updated: 2020/07/08 02:51:07 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

t_mat	mat_new_vec(t_vec *a, t_vec *b, t_vec *c)
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
	return r;
}