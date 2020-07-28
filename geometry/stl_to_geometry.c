/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_to_geometry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:09:24 by minckim           #+#    #+#             */
/*   Updated: 2020/07/28 21:39:38 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "geometry.h"
#include <stdio.h>

void		byte_to_face(char *buff, t_face *f)
{
	t_vec	v[4];
	float	*buff_flaot;
	int		i;

	i = -1;
	buff_flaot = (float*)buff;
	while (++i < 4)
	{
		v[i] = vec_new(buff_flaot[2] * 3, buff_flaot[1] * 3, buff_flaot[0] * 3);
		buff_flaot += 3;
	}
	*f = face_new(v + 1, v + 2, v + 3, 0);
	f->side = SIDE_DOUBLE;
	f->color = 0xffff00;
}

t_entity	stl_to_geometry(char *path)
{
	int			fd;
	char		buff[100];
	int			n_face;
	t_face		*f;
	t_entity	e;

	if ((fd = open(path, O_RDONLY)) < 0)
	{
		write(1, "Can not open the stl file\n", 23);
		return (entity_new(0, 0));
	}
	read(fd, buff, 80);
	read(fd, buff, 4);
	n_face = *(int*)buff;
	e.face = malloc(sizeof(t_face) * n_face);
	f = e.face;
	while (read(fd, buff, 50) > 0)
	{
		byte_to_face(buff, f++);
	}
	e = entity_new(e.face, n_face);
	e.v = M_PI_2;
	return (e);
}
