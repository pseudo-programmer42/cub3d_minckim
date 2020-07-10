/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:03:07 by minckim           #+#    #+#             */
/*   Updated: 2020/07/10 19:56:43 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void		pixel_face(t_pixel *pixel, t_face *f)
{
	t_vec	u;
	t_vec	v;
	t_vec	a;
	t_mat	r;

	a = vec_new(-f->a.x, -f->a.y, -f->a.z);
	u = f->b;
	v = f->c;
	vec_add(&u, &a);
	vec_add(&v, &a);
	r = mat_new_vec(&u, &v, &(pixel->ray));
	mat_inverse(&r);
	mat_vec(&r, &a);
	if (a.x < 0 || 1 < a.x || a.y < 0 || 1 < a.y || a.z > 0 || a.z < pixel->distance)
		return ;
	if (f->type == TRIANGLE && a.x + a.y > 1)
		return ;
	if (f->img)
		*(pixel->color) = bitmap_pixel_color(f->img, \
			a.x * ((t_bitmap*)(f->img))->width, \
			a.y * ((t_bitmap*)(f->img))->height);
	else
		*(pixel->color) = (f->color);
	pixel->distance = a.z;
}

void		screen_face(t_screen *s, t_face *f)
{
	int		boundary[4];
	t_real	point[8];
	t_face	tmp;
	int		i;
	int		j;

	tmp = *f;
	face_rot_rc(&tmp, &(s->origin), s->h, s->v);
	if (set_boundary_f(s, &tmp, boundary, point) == 0)
		return ;
	i = boundary[0] - 1;
	while (++i < boundary[2])
	{
		j = boundary[1] - 1;
		while (++j < boundary[3])
		{
			pixel_face(&((s->pixel)[i][j]), &tmp);
		}
	}
}

void		screen_entity(t_screen *s, t_entity *e)
{
	int		i;
	t_face	tmp;
	t_mat	mat_r;

	i = 0;
	while (i < e->n_face)
	{
		tmp = *(e->face + i++);
		mat_r = mat_rot(e->h, e->v);
		mat_vec(&mat_r, &(tmp.a));
		mat_vec(&mat_r, &(tmp.b));
		mat_vec(&mat_r, &(tmp.c));
		face_move(&tmp, &(e->origin));
		screen_face(s, &tmp);
	}
}