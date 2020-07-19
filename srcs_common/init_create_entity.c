/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create_entity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:00:12 by minckim           #+#    #+#             */
/*   Updated: 2020/07/18 15:20:48 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs_common/cub3d_common.h"

t_entity	create_wall(t_bitmap **texture)
{
	t_entity	wall;
	t_vec		a;
	t_vec		b;
	t_vec		c;
	t_vec		z;

	ft_memset(&wall, 0, sizeof(t_entity));
	wall.n_face = 4;
	wall.face = (t_face*)malloc(sizeof(t_face) * 4);
	a = vec_new(WALL_WIDTH / 2, -WALL_WIDTH / 2, 0);
	b = vec_new(WALL_WIDTH / 2, WALL_WIDTH / 2, 0);
	c = vec_new(WALL_WIDTH / 2, -WALL_WIDTH / 2, CEILLING_HEIGHT);
	z = vec_new(0, 0, 0);
	wall.face[0] = face_new(&a, &b, &c, RECTANGLE);
	wall.face[1] = face_new(&a, &b, &c, RECTANGLE);
	wall.face[2] = face_new(&a, &b, &c, RECTANGLE);
	wall.face[3] = face_new(&a, &b, &c, RECTANGLE);
	face_rot(&(wall.face[1]), &z, M_PI / 2, 0);
	face_rot(&(wall.face[2]), &z, M_PI, 0);
	face_rot(&(wall.face[3]), &z, M_PI * 3 / 2, 0);
	wall.face[0].img = texture[TEXTURE_EAST];
	wall.face[1].img = texture[TEXTURE_NORTH];
	wall.face[2].img = texture[TEXTURE_WEST];
	wall.face[3].img = texture[TEXTURE_SOUTH];
	return (wall);
}

t_entity	create_floor_ceilling(int *color)
{
	t_entity	floor;
	t_vec		a;
	t_vec		b;
	t_vec		c;
	t_vec		z;

	ft_memset(&floor, 0, sizeof(t_entity));
	floor.n_face = 2;
	floor.face = (t_face*)malloc(sizeof(t_face) * 2);
	a = vec_new(-WALL_WIDTH / 2, -WALL_WIDTH / 2, 0);
	b = vec_new(WALL_WIDTH / 2, -WALL_WIDTH / 2, 0);
	c = vec_new(-WALL_WIDTH / 2, WALL_WIDTH / 2, 0);
	z = vec_new(0, 0, CEILLING_HEIGHT / 2);
	floor.face[0] = face_new(&a, &b, &c, RECTANGLE);
	floor.face[1] = floor.face[0];
	face_rot(floor.face + 1, &z, 0, M_PI);
	floor.face[0].color = color[0];
	floor.face[1].color = color[1];
	return (floor);
}

t_entity	create_sprite(t_bitmap **texture)
{
	t_entity	sprite;
	t_vec		a;
	t_vec		b;
	t_vec		c;

	ft_memset(&sprite, 0, sizeof(t_entity));
	sprite.n_face = 1;
	sprite.face = (t_face*)malloc(sizeof(t_face) * 1);
	a = vec_new(0, -500, 0);
	b = vec_new(0, 500, 0);
	c = vec_new(0, -200, 2000);
	sprite.face[0] = face_new(&a, &b, &c, RECTANGLE);
	sprite.face[0].img = texture[TEXTURE_SPRITE];
	return (sprite);
}

t_entity	create_non(void)
{
	t_entity	non;

	non.n_face = 0;
	return (non);
}
