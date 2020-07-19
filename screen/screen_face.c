/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_face.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:03:07 by minckim           #+#    #+#             */
/*   Updated: 2020/07/18 14:41:22 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

t_real	set_distance(t_face *f)
{
	return (equation_vector(&f->u, &f->v, &f->n, &f->a).z);
}

void	pixel_face(t_pixel *pixel, t_face *f)
{
	t_vec	a;
	int		color;
	t_vec	b;

	b = vec_new(-f->a.x, -f->a.y, -f->a.z);
	a = equation_vector(&pixel->ray, &f->u, &f->v, &b);
	a.x = -a.x;
	if (a.z < 0 || 1 < a.z || a.y < 0 || 1 < a.y || a.x < 0 || \
		a.x > pixel->distance)
		return ;
	if (f->type == TRIANGLE && a.y + a.z > 1)
		return ;
	if (f->img)
	{
		color = bitmap_pixel_color(f->img, a.y * ((t_bitmap*)(f->img))->width,\
		a.z * ((t_bitmap*)(f->img))->height);
		*(pixel->color) = color == 0x00ffffff ? *(pixel->color) : color;
	}
	else
		*(pixel->color) = (f->color);
	pixel->distance = a.x;
}

int		screen_face(t_screen *s, t_face *f)
{
	int		boundary[4];
	t_real	point[8];
	int		i;
	int		j;
	t_real	near_distance;

	face_rot_rc(f, &(s->origin), s->h, s->v);
	near_distance = set_distance(f);
	if (f->n.x > s->cos_cam)
		return (0);
	if (set_boundary_f(s, f, boundary, point) == 0)
		return (0);
	i = boundary[1] - 2;
	i = i % 2 ? i + 1 : i;
	i += s->odd;
	while ((i += 2) < boundary[3])
	{
		j = boundary[0] - 1;
		while (++j < boundary[2])
			if (s->pixel[j][i].distance > near_distance)
				pixel_face(&((s->pixel)[j][i]), f);
	}
	return (1);
}
