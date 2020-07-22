/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:13:22 by minckim           #+#    #+#             */
/*   Updated: 2020/07/22 17:02:54 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	dead(t_player *p, t_screen *s)
{
	if (p->life)
		return ;
	screen_gray(s);
	mlx_string_put(s->mlx, s->win, s->rx / 2 - 30, s->ry / 2, 0xffffff,\
	"GAME OVER");
}
