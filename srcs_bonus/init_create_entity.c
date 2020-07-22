/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create_entity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:00:12 by minckim           #+#    #+#             */
/*   Updated: 2020/07/22 16:53:21 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_entity	create_wall(t_bitmap **texture)
{
	t_entity	wall;
	t_vec		v[4];

	ft_memset(&wall, 0, sizeof(t_entity));
	wall.n_face = 4;
	wall.face = (t_face*)malloc(sizeof(t_face) * wall.n_face);
	ft_memset(wall.face, 0, sizeof(t_face) * wall.n_face);
	v[0] = vec_new(WALL_WIDTH / 2, -WALL_WIDTH / 2, 0);
	v[1] = vec_new(WALL_WIDTH / 2, WALL_WIDTH / 2, 0);
	v[2] = vec_new(WALL_WIDTH / 2, -WALL_WIDTH / 2, CEILLING_HEIGHT);
	v[3] = vec_new(0, 0, 0);
	wall.face[0] = face_new(&v[0], &v[1], &v[2], RECTANGLE);
	wall.face[1] = face_new(&v[0], &v[1], &v[2], RECTANGLE);
	wall.face[2] = face_new(&v[0], &v[1], &v[2], RECTANGLE);
	wall.face[3] = face_new(&v[0], &v[1], &v[2], RECTANGLE);
	face_rot(&(wall.face[1]), &v[3], M_PI / 2, 0);
	face_rot(&(wall.face[2]), &v[3], M_PI, 0);
	face_rot(&(wall.face[3]), &v[3], M_PI * 3 / 2, 0);
	wall.face[0].img = texture[IMG_EAST];
	wall.face[1].img = texture[IMG_NORTH];
	wall.face[2].img = texture[IMG_WEST];
	wall.face[3].img = texture[IMG_SOUTH];
	return (wall);
}

t_entity	create_door(t_bitmap **texture)
{
	t_entity	door;
	t_vec		a;
	t_vec		b;
	t_vec		c;

	ft_memset(&door, 0, sizeof(t_entity));
	door.type = TYPE_DOOR;
	door.n_face = 1;
	door.face = (t_face*)malloc(sizeof(t_face) * 1);
	ft_memset(door.face, 0, sizeof(t_face) * door.n_face);
	a = vec_new(WALL_WIDTH / 2, -WALL_WIDTH / 2, 0);
	b = vec_new(WALL_WIDTH / 2, WALL_WIDTH / 2, 0);
	c = vec_new(WALL_WIDTH / 2, -WALL_WIDTH / 2, CEILLING_HEIGHT);
	door.face[0] = face_new(&a, &b, &c, RECTANGLE);
	door.face[0].img = texture[0];
	door.face[0].side = SIDE_DOUBLE;
	return (door);
}

t_entity	create_floor_ceilling(t_bitmap **texture)
{
	t_entity	floor;
	t_vec		a;
	t_vec		b;
	t_vec		c;
	t_vec		z;

	ft_memset(&floor, 0, sizeof(t_entity));
	floor.type = TYPE_FLOOR;
	floor.n_face = 2;
	floor.face = (t_face*)malloc(sizeof(t_face) * floor.n_face);
	ft_memset(floor.face, 0, sizeof(t_face) * floor.n_face);
	a = vec_new(-WALL_WIDTH / 2, -WALL_WIDTH / 2, 0);
	b = vec_new(WALL_WIDTH / 2, -WALL_WIDTH / 2, 0);
	c = vec_new(-WALL_WIDTH / 2, WALL_WIDTH / 2, 0);
	z = vec_new(0, 0, CEILLING_HEIGHT / 2);
	floor.face[0] = face_new(&a, &b, &c, RECTANGLE);
	floor.face[1] = floor.face[0];
	face_rot(floor.face + 1, &z, 0, M_PI);
	floor.face[0].img = texture[IMG_FLOOR];
	floor.face[1].img = texture[IMG_CEILLING];
	return (floor);
}

t_entity	create_sprite(t_bitmap **texture, int type)
{
	t_entity	sprite;
	t_vec		a;
	t_vec		b;
	t_vec		c;
	int			i;

	ft_memset(&sprite, 0, sizeof(t_entity));
	sprite.n_face = 3;
	sprite.face = (t_face*)malloc(sizeof(t_face) * sprite.n_face);
	ft_memset(sprite.face, 0, sizeof(t_face) * sprite.n_face);
	a = vec_new(0, -500, 0);
	b = vec_new(0, 500, 0);
	c = vec_new(0, -200, 2000);
	sprite.face[0] = face_new(&a, &b, &c, RECTANGLE);
	sprite.face[1] = face_new(&a, &b, &c, RECTANGLE);
	sprite.face[2] = face_new(&a, &b, &c, RECTANGLE);
	sprite.type = type;
	i = -1;
	while (++i < sprite.n_face)
	{
		sprite.face[i].img = texture[i];
	}
	return (sprite);
}

t_entity	create_non(void)
{
	t_entity	non;

	non.n_face = 0;
	return (non);
}
