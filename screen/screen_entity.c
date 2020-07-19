/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:15:49 by minckim           #+#    #+#             */
/*   Updated: 2020/07/18 13:50:51 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

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
		face_move(&tmp, &(e->origin));
		visible += screen_face(s, &tmp);
	}
	if (visible)
		return (1);
	return (0);
}

int		screen_item(t_screen *s, t_entity *e)
{
	int			i;
	t_entity	copied_e;
	t_face		tmp;
	t_mat		mat_r;
	int			visible;

	visible = 0;
	i = 0;
	copied_e = *e;
	mat_r = mat_rot(s->h - M_PI, 0);
	while (i < copied_e.n_face)
	{
		tmp = *(copied_e.face + i++);
		mat_vec(&mat_r, &(tmp.a));
		mat_vec(&mat_r, &(tmp.b));
		mat_vec(&mat_r, &(tmp.c));
		mat_vec(&mat_r, &(tmp.u));
		mat_vec(&mat_r, &(tmp.v));
		mat_vec(&mat_r, &(tmp.n));
		face_move(&tmp, &(e->origin));
		visible += screen_face(s, &tmp);
	}
	if (visible)
		return (1);
	return (0);
}
