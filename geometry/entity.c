/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:15:47 by minckim           #+#    #+#             */
/*   Updated: 2020/07/14 00:06:50 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <stdlib.h>

t_entity	entity_new(t_face *face, int n)
{
	t_entity	r;

	r.n_face = n;
	r.face = face;
	r.h = 0;
	r.v = 0;
	r.origin = vec_new(0, 0, 0);
	return (r);
}

t_entity	entity_copy(t_entity *e, t_vec *v)
{
	t_entity	r;

	r = *e;
	entity_move(&r, v);
	return (r);
}

t_entity	entity_deepcopy(t_entity *e, t_vec *v)
{
	t_entity	r;
	int			i;

	r.n_face = e->n_face;
	r.face = (t_face*)malloc(sizeof(t_face) * r.n_face);
	r.h = e->h;
	r.v = e->v;
	i = -1;
	while (++i < r.n_face)
	{
		(r.face)[i] = (e->face)[i];
	}
	vec_add(&(r.origin), v);
	return (r);
}

t_entity	*entity_move(t_entity *e, t_vec *v)
{
	vec_add(&(e->origin), v);
	return (e);
}

t_entity	*entity_rot(t_entity *e, t_real h, t_real v)
{
	e->h += h;
	e->h += v;
	return (e);
}
