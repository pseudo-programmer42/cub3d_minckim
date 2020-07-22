/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 09:00:10 by minckim           #+#    #+#             */
/*   Updated: 2020/07/21 16:43:35 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	pick_neighbors(t_entity *w, t_vec *m, t_gamedata *g_data)
{
	int		i;
	int		j;
	int		k;
	int		x;
	int		y;

	x = (m->x / WALL_WIDTH) - (int)(m->x / WALL_WIDTH) < 0.5 ? \
	(m->x / WALL_WIDTH) : (m->x / WALL_WIDTH) + 1;
	y = (m->y / WALL_WIDTH) - (int)(m->y / WALL_WIDTH) < 0.5 ? \
	(m->y / WALL_WIDTH) : (m->y / WALL_WIDTH) + 1;
	k = 0;
	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			w[k++] = g_data->entity[x + i][y + j];
		}
	}
}

int		is_point_in(t_vec *v, t_entity *e)
{
	int		i;
	int		is_in;

	is_in = 0;
	i = 0;
	if (e->type == TYPE_WALL || e->type == TYPE_DOOR)
		if ((e->origin.x) - WALL_WIDTH / 2 < v->x \
		&& v->x < e->origin.x + WALL_WIDTH / 2 \
		&& (e->origin.y) - WALL_WIDTH / 2 < v->y \
		&& v->y < e->origin.y + WALL_WIDTH / 2)
		{
			return (1);
		}
	if (e->type == TYPE_SPRITE_AN)
		if ((v->x - e->origin.x) * (v->x - e->origin.x) \
			+ (v->y - e->origin.y) * (v->y - e->origin.y) \
			< WALL_WIDTH * WALL_WIDTH / 4)
		{
			return (1);
		}
	return (0);
}

int		check_collision(t_gamedata *g_data, t_vec *m)
{
	t_vec		tmp;
	t_entity	walls[9];
	int			i;
	t_list		*lst_item;

	tmp = *m;
	vec_add(&tmp, &g_data->player.origin);
	pick_neighbors(walls, &g_data->player.origin, g_data);
	i = -1;
	while (++i < 9)
		if (is_point_in(&tmp, &walls[i]))
		{
			return (1);
		}
	lst_item = g_data->lst_item;
	while (lst_item)
	{
		if (is_point_in(&tmp, lst_item->content))
			return (1);
		lst_item = lst_item->next;
	}
	return (check_collision_door(g_data, m));
}
