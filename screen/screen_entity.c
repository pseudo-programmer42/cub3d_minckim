/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:15:49 by minckim           #+#    #+#             */
/*   Updated: 2020/07/28 21:33:34 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include <time.h>

int		screen_entity(t_screen *s, t_entity *e)
{
	int		i;
	t_face	tmp;
	t_mat	mat_r;
	int		visible;

	visible = 0;
	i = 0;
	mat_r = mat_rot(e->h, e->v);
	while (i < e->n_face)
	{
		tmp = *(e->face + i++);
		mat_vec(&mat_r, &(tmp.a));
		mat_vec(&mat_r, &(tmp.b));
		mat_vec(&mat_r, &(tmp.c));
		mat_vec(&mat_r, &(tmp.u));
		mat_vec(&mat_r, &(tmp.v));
		mat_vec(&mat_r, &(tmp.n));
		tmp.shade = vec_dot(&s->gi, &tmp.n);
		tmp.shade = tmp.shade > 0 ? tmp.shade : -tmp.shade;
		face_move(&tmp, &(e->origin));
		visible += screen_face(s, &tmp);
	}
	if (visible)
		return (1);
	return (0);
}

int		screen_item(t_screen *s, t_entity *e)
{
	static clock_t	t[2];
	t_mat			mat_r;
	int				i;
	t_face			f;

	if (!t[0])
		t[0] = clock();
	mat_r = mat_rot(s->h - M_PI, 0);
	t[1] = clock();
	i = (int)((double)(t[1] - t[0]) / 0.2 / CLOCKS_PER_SEC) % e->n_face;
	f = e->face[i];
	mat_vec(&mat_r, &f.a);
	mat_vec(&mat_r, &f.b);
	mat_vec(&mat_r, &f.c);
	mat_vec(&mat_r, &f.u);
	mat_vec(&mat_r, &f.v);
	mat_vec(&mat_r, &f.n);
	face_move(&f, &(e->origin));
	return (screen_face(s, &f));
}
