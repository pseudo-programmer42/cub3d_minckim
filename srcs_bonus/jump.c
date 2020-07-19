/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:56:44 by minckim           #+#    #+#             */
/*   Updated: 2020/07/19 10:52:21 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	player_jump(t_player *p)
{
	static clock_t	t0;
	clock_t			t1;

	if (!p->jump)
		return ;
	t1 = clock();
	if (((double)(t1 - t0) / CLOCKS_PER_SEC) > JUMP_DUL)
	{
		p->origin.z = 0;
		t0 = t1;
		p->jump = 0;
		return ;
	}
	p->origin.z = ((double)(t1 - t0) / CLOCKS_PER_SEC) \
		* (4 * JUMP_HEIGHT / JUMP_DUL) \
		* (JUMP_DUL - ((double)(t1 - t0) / CLOCKS_PER_SEC));
}

void	player_catch_jump(t_player *p, long long *keys)
{
	if (is_pressed(KEY_SPC, keys))
	{
		p->jump = 1;
		p->crouch = 0;
	}
}
