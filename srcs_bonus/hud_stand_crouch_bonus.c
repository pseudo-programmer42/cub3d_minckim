/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_stand_crouch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:17:12 by minckim           #+#    #+#             */
/*   Updated: 2020/07/21 22:23:49 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	screen_stand(t_screen *s, t_bitmap *b)
{
	int		left_top[2];

	left_top[0] = 10;
	left_top[1] = s->ry - 170;
	screen_bitmap(s, b, left_top, 0.1);
}

void	screen_crouch(t_screen *s, t_bitmap *b)
{
	int		left_top[2];

	left_top[0] = 10;
	left_top[1] = s->ry - 110;
	screen_bitmap(s, b, left_top, 0.1);
}

void	screen_stand_crouch(t_screen *s, t_gamedata *g_data)
{
	if (g_data->player.crouch)
		screen_crouch(s, g_data->texture[IMG_CROUCH]);
	else
		screen_stand(s, g_data->texture[IMG_STAND]);
}
