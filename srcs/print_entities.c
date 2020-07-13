/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 01:10:58 by minckim           #+#    #+#             */
/*   Updated: 2020/07/14 03:40:05 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_entities(t_gamedata *g_data)
{
	int			i;
	int			j;
	t_screen	*s;
	t_entity	*e;

	s = &g_data->screen;
	i = -1;
	while (++i < g_data->size_x)
	{
		e = g_data->entity[i];
		j = -1;
		while (++j < g_data->size_y)
		{
			screen_entity(s, e + j);
		}
	}
	i = -1;
	e = g_data->item;
	while (++i < g_data->n_item)
	{
		screen_item(s, e + i);
	}
}
