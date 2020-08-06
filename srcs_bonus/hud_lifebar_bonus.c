/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_lifebar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:23:53 by minckim           #+#    #+#             */
/*   Updated: 2020/07/20 13:31:15 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#define L_BAR 154
#define H_BAR 26
#define START_X 96
#define START_Y 53

void	screen_lifebar(t_screen *s, t_bitmap *b, t_player *p)
{
	int		i;
	int		j;
	int		mx;
	int		left_top[2];

	left_top[0] = 10;
	left_top[1] = 10;
	mx = (double)L_BAR / LIFE_MAX * p->life;
	i = -1;
	while (++i < H_BAR)
	{
		j = -1;
		while (++j < mx)
		{
			*(s->pixel[j + START_X][i + START_Y].color) = 0xff00;
		}
	}
	screen_bitmap(s, b, left_top, 1);
}
