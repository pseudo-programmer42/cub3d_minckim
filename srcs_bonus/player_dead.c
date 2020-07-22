/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:13:22 by minckim           #+#    #+#             */
/*   Updated: 2020/07/22 20:33:27 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	dead(t_player *p, t_screen *s)
{
	static t_bitmap	*b;
	int				left_top[2];
	double			sc;

	if (p->life)
		return ;
	screen_gray(s);
	if (!b)
		b = bitmap_new("./texture/u_died.bmp");
	sc = (double)s->rx / b->width;
	sc = (double)s->ry / b->height < sc ? (double)s->ry / b->height : sc;
	left_top[0] = s->rx / 2 - b->width / 2 * sc;
	left_top[1] = s->ry / 2 - b->height / 2 * sc;
	screen_bitmap(s, b, left_top, sc);
}
