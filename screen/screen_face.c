/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_face.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:03:07 by minckim           #+#    #+#             */
/*   Updated: 2020/07/14 00:47:54 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

t_real	set_distance(t_face *f)
{
	t_mat	r;
	t_vec	a;
	t_real	det;

	r = mat_new_vec(&f->u, &f->v, &f->n);
	a = vec_new(-f->a.x, -f->a.y, -f->a.z);
	mat_inverse_det(&r, &det);
	mat_vec(&r, &a);
	vec_div(&a, det);
	return (-a.z);
}

void	pixel_face(t_pixel *pixel, t_face *f)
{
	t_vec	a;
	t_mat	r;
	t_real	det;
	int		color;

	a = vec_new(-f->a.x, -f->a.y, -f->a.z);
	r = mat_new_vec(&f->u, &f->v, &(pixel->ray));
	mat_inverse_det(&r, &det);
	mat_vec(&r, &a);
	vec_div(&a, det);
	a.z = -a.z;
	if (a.x < 0 || 1 < a.x || a.y < 0 || 1 < a.y || a.z < 0 || \
		a.z > pixel->distance)
		return ;
	if (f->type == TRIANGLE && a.x + a.y > 1)
		return ;
	if (f->img)
	{
		color = bitmap_pixel_color(f->img, a.x * ((t_bitmap*)(f->img))->width, \
		a.y * ((t_bitmap*)(f->img))->height);
		*(pixel->color) = color == 0x00ffffff ? *(pixel->color) : color;
	}
	else
		*(pixel->color) = (f->color);
	pixel->distance = a.z;
}

void	screen_face(t_screen *s, t_face *f)
{
	int		boundary[4];
	t_real	point[8];
	int		i;
	int		j;
	t_real	near_distance;

	face_rot_rc(f, &(s->origin), s->h, s->v);
	near_distance = set_distance(f);
	if (f->n.x > s->cos_cam)
		return ;
	if (set_boundary_f(s, f, boundary, point) == 0)
		return ;
	i = boundary[0] - 1;
	while (++i < boundary[2])
	{
		j = boundary[1] - 1;
		while (++j < boundary[3])
		{
			if (s->pixel[i][j].distance > near_distance)
				pixel_face(&((s->pixel)[i][j]), f);
		}
	}
}
