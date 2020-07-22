/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:04:51 by minckim           #+#    #+#             */
/*   Updated: 2020/07/22 19:20:25 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_collision_door(t_gamedata *g_data, t_vec *m)
{
	t_list		*lst_item;
	t_vec		tmp;

	tmp = *m;
	vec_add(&tmp, &g_data->player.origin);
	lst_item = g_data->lst_door;
	while (lst_item)
	{
		if (is_point_in(&tmp, lst_item->content)
		&& ((t_entity*)(lst_item->content))->origin.z < CEILLING_HEIGHT)
			return (1);
		lst_item = lst_item->next;
	}
	return (0);
}

void	player_opendoor(t_gamedata *g)
{
	static clock_t	t[2];
	t_list			*curr;
	t_vec			v;
	t_entity		*tmp;

	curr = g->lst_door;
	while (curr)
	{
		tmp = curr->content;
		if (tmp->origin.x - WALL_WIDTH < g->player.origin.x \
		&& g->player.origin.x < tmp->origin.x + WALL_WIDTH \
		&& tmp->origin.y - WALL_WIDTH < g->player.origin.y \
		&& g->player.origin.y < tmp->origin.y + WALL_WIDTH)
			break ;
		curr = curr->next;
	}
	if (!curr)
		return ;
	t[1] = clock();
	v = vec_new(0, 0, MOVE_WALK);
	if (is_pressed(KEY_F, g->keys) \
	&& (double)(t[1] - t[0]) / CLOCKS_PER_SEC > TIME_SEGMENT)
		entity_move(curr->content, &v);
	tmp->origin.z = tmp->origin.z > CEILLING_HEIGHT ? \
	CEILLING_HEIGHT : tmp->origin.z;
}

void	player_closedoor(t_gamedata *g)
{
	static clock_t	t[2];
	t_list			*curr;
	t_vec			v;
	t_entity		*tmp;

	curr = g->lst_door;
	while (curr)
	{
		tmp = curr->content;
		if (tmp->origin.x - WALL_WIDTH < g->player.origin.x \
		&& g->player.origin.x < tmp->origin.x + WALL_WIDTH \
		&& tmp->origin.y - WALL_WIDTH < g->player.origin.y \
		&& g->player.origin.y < tmp->origin.y + WALL_WIDTH)
			break ;
		curr = curr->next;
	}
	if (!curr)
		return ;
	t[1] = clock();
	v = vec_new(0, 0, -MOVE_WALK);
	if (is_pressed(KEY_G, g->keys) \
	&& (double)(t[1] - t[0]) / CLOCKS_PER_SEC > TIME_SEGMENT
	&& tmp->origin.z >= 0)
		entity_move(curr->content, &v);
	tmp->origin.z = tmp->origin.z < 0 ? 0 : tmp->origin.z;
}
