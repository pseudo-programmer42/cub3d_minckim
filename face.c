/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 01:06:37 by minckim           #+#    #+#             */
/*   Updated: 2020/07/02 05:32:41 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_face		*face_new(t_image *img, int color, double *u, double *v)
{
	t_face	*result;

	result = (t_face*)malloc(sizeof(t_face));
	if (img)
		result->img = img;
	else
	{
		result->color = color;
		result->img = 0;
	}
	result->p[0] = 0;
	result->p[1] = 0;
	result->p[2] = 0;
	result->p[3] = u[0];
	result->p[4] = u[1];
	result->p[5] = u[2];
	result->p[6] = v[0];
	result->p[7] = v[1];
	result->p[8] = v[2];
	return (result);
}

void	*face_deepcopy(void *face)
{
	t_face	*new_face;

	if (!(new_face = (t_face*)malloc(sizeof(t_face))))
		return (0);
	ft_memcpy(new_face, face, sizeof(t_face));
	// face_print_coord(face);
	// face_print_coord(new_face);
	return (new_face);
}

void	face_del(void *face)
{
	free((t_face*)face);
}

t_face	*face_copy(t_face *face, double *dir)
{
	t_face	*new_face;
	int		i;

	new_face = (t_face*)malloc(sizeof(t_face));
	new_face->instance_type  = face->instance_type;
	new_face->img = face->img;
	new_face->color = face->color;
	i = -1;
	while (++i < 9)
	{
		(new_face->p)[i] = (face->p)[i] + dir[i % 3];
	}
	return (new_face);
}

t_face	*face_move(t_face *face, double *dir)
{
	int		i;

	i = -1;
	while (++i < 9)
	{
		(face->p)[i] += dir[i % 3];
	}
	return (face);
}

t_face	*face_rot_h(t_face *face, double *origin, double angle)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		vector_sub(face->p + i, origin);
		vector_rot_h(face->p + i, angle);
		vector_add(face->p + i, origin);
		i += 3;
	}
	return (face);
}

t_face	*face_rot_v(t_face *face, double *origin, double angle_h, \
			double angle_v)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		vector_sub(face->p + i, origin);
		vector_rot_v(face->p + i, angle_h, angle_v);
		vector_add(face->p + i, origin);
		i += 3;
	}
	return (face);
}