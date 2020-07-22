/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:42:34 by minckim           #+#    #+#             */
/*   Updated: 2020/07/22 18:45:59 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
			if (map[i][j] == '0' || ft_strchr("NEWS23456", map[i][j]))
				g->entity[i][j] = entity_copy(&g->floor, &v);
			if (map[i][j] == '1')
				g->entity[i][j] = entity_copy(&g->wall, &v);
			if (map[i][j] == ' ')
				g->entity[i][j] = entity_copy(&g->non, &v);
			if (ft_strchr("NEWS", map[i][j]))
				g->player.origin = v;
		}
	}
	g->lst_ent = entity_to_list(g);
}

void	copy_items(char **map, t_gamedata *g)
{
	int			i;
	int			j;
	t_vec		v;
	t_entity	*tmp;

	g->lst_item = 0;
	i = -1;
	while (++i < g->size_x)
	{
		j = -1;
		while (++j < g->size_y)
		{
			if (ft_strchr("234", map[i][j]) == 0)
				continue ;
			tmp = (t_entity*)malloc(sizeof(t_entity));
			v = vec_new(i * WALL_WIDTH, j * WALL_WIDTH, 0);
			if (map[i][j] == '2')
				*tmp = entity_copy(&g->sprite_ap, &v);
			if (map[i][j] == '3')
				*tmp = entity_copy(&g->sprite_42, &v);
			if (map[i][j] == '4')
				*tmp = entity_copy(&g->sprite_an, &v);
			ft_lstadd_front(&g->lst_item, ft_lstnew(tmp));
		}
	}
}

void	copy_door(char **map, t_gamedata *g)
{
	int			i;
	int			j;
	t_vec		v;
	t_entity	*tmp;

	g->lst_door = 0;
	i = -1;
	while (++i < g->size_x)
	{
		j = -1;
		while (++j < g->size_y)
		{
			if (ft_strchr("56", map[i][j]) == 0)
				continue ;
			tmp = (t_entity*)malloc(sizeof(t_entity));
			v = vec_new(i * WALL_WIDTH, j * WALL_WIDTH, 0);
			if (map[i][j] == '5')
				*tmp = entity_copy(&g->door, &v);
			if (map[i][j] == '6')
				*tmp = entity_copy(&g->secret_door, &v);
			ft_lstadd_front(&g->lst_door, ft_lstnew(tmp));
		}
	}
}

void	init_player(t_gamedata *g_data)
{
	g_data->player.run = 0;
	g_data->player.jump = 0;
	g_data->player.crouch = 0;
	g_data->player.life = 100;
	if (g_data->player.origin.x == 0)
		exit_message("%sPlayer start point missing.","");
}

void	init_entity(t_gamedata *g, char **map_arr)
{
	g->wall = create_wall(g->texture);
	g->floor = create_floor_ceilling(g->texture);
	g->sprite_ap = create_sprite(g->texture + IMG_AP_0, TYPE_SPRITE_AP);
	g->sprite_42 = create_sprite(g->texture + IMG_42_0, TYPE_SPRITE_42);
	g->sprite_an = create_sprite(g->texture + IMG_AN_0, TYPE_SPRITE_AN);
	g->door = create_door(g->texture + IMG_DO);
	g->secret_door = create_door(g->texture + IMG_SD);
	g->non = create_non();
	g->wall.type = TYPE_WALL;
	g->entity = (t_entity**)malloc(sizeof(t_entity*) * g->size_x);
	copy_entities(map_arr, g);
	copy_items(map_arr, g);
	copy_door(map_arr, g);
	init_player(g);
}
