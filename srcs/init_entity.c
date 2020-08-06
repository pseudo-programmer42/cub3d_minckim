/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:42:34 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 17:26:41 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_entities(char **map, t_gamedata *g)
{
	int		i;
	int		j;
	t_vec	v;

	i = -1;
	while (++i < g->size_x)
	{
		g->entity[i] = (t_entity*)malloc(sizeof(t_entity) * g->size_y);
		j = -1;
		while (++j < g->size_y)
		{
			v = vec_new(i * WALL_WIDTH, j * WALL_WIDTH, 0);
			if (map[i][j] == '0' || ft_strchr("NEWS2", map[i][j]))
				g->entity[i][j] = entity_copy(&g->floor, &v);
			if (map[i][j] == '1')
				g->entity[i][j] = entity_copy(&g->wall, &v);
			if (map[i][j] == '2')
				g->item[g->n_item++] = entity_copy(&g->sprite, &v);
			if (map[i][j] == ' ')
				g->entity[i][j] = entity_copy(&g->non, &v);
			if (ft_strchr("NEWS", map[i][j]))
				g->player.origin = v;
		}
	}
}

void	init_player(t_gamedata *g_data)
{
	g_data->player.run = 0;
}

void	init_entity(t_gamedata *g, char **map_arr)
{
	g->wall = create_wall(g->texture);
	g->floor = create_floor_ceilling(g->color);
	g->sprite = create_sprite(g->texture);
	g->non = create_non();
	g->wall.origin = vec_new(0, 0, 0);
	g->floor.origin = vec_new(0, 0, 0);
	g->sprite.origin = vec_new(0, 0, 0);
	g->n_item = 0;
	g->entity = (t_entity**)malloc(sizeof(t_entity*) * g->size_x);
	copy_entities(map_arr, g);
	split_del(map_arr);
	init_player(g);
}
