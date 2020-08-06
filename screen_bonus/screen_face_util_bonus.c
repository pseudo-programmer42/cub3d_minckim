/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_face_util_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:09:08 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:21:35 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen_bonus.h"

int		screen_point(t_screen *s, t_vec *restrict v, t_real *point)
{
	if (v->x < 0)
	{
		*point++ = v->y > 0 ? 0 : s->rx;
		*point = v->z > 0 ? 0 : s->ry;
		return (0);
	}
	else
	{
		*point++ = s->rx / 2 - v->y * s->distance / v->x;
		*point = s->ry / 2 - v->z * s->distance / v->x;
	}
	return (1);
}

int		screen_face_point(t_screen *s, t_face *f, t_real *point)
{
	t_vec	d;
	int		visible;

	visible = 0;
	visible += screen_point(s, &(f->a), point);
	visible += screen_point(s, &(f->b), point + 2);
	visible += screen_point(s, &(f->c), point + 4);
	if (f->type == RECTANGLE)
	{
		d = f->b;
		vec_add(&d, &f->c);
		vec_sub(&d, &f->a);
		visible += screen_point(s, &(d), point + 6);
	}
	if (visible == 0)
		return (0);
	else
		return (1);
}

void	set_boundary(int *boundary, t_real *point)
{
	boundary[0] = boundary[0] > point[0] ? point[0] : boundary[0];
	boundary[1] = boundary[1] > point[1] ? point[1] : boundary[1];
	boundary[2] = boundary[2] < point[0] ? point[0] : boundary[2];
	boundary[3] = boundary[3] < point[1] ? point[1] : boundary[3];
	boundary[2]++;
	boundary[3]++;
}

int		set_boundary_f(t_screen *s, t_face *f, int *boundary, t_real *point)
{
	boundary[0] = s->rx;
	boundary[1] = s->ry;
	boundary[2] = 0;
	boundary[3] = 0;
	if (screen_face_point(s, f, point) == 0)
	{
		return (0);
	}
	set_boundary(boundary, point);
	set_boundary(boundary, point + 2);
	set_boundary(boundary, point + 4);
	if (f->type == RECTANGLE)
		set_boundary(boundary, point + 6);
	boundary[0] = boundary[0] < 0 ? 0 : boundary[0];
	boundary[1] = boundary[1] < 0 ? 0 : boundary[1];
	boundary[2] = boundary[2] > s->rx ? s->rx : boundary[2];
	boundary[3] = boundary[3] > s->ry ? s->ry : boundary[3];
	return (1);
}
