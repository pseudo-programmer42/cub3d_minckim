/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crouch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:50:11 by minckim           #+#    #+#             */
/*   Updated: 2020/07/19 12:04:34 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	player_catch_crouch(t_player *p, long long *keys)
{
	static clock_t	t0;
	clock_t			t1;

	t1 = clock();
	if (p->jump)
	{
		p->crouch = 0;
		return ;
	}
	if (is_pressed(KEY_C, keys) && (double)(t1 - t0) / CLOCKS_PER_SEC > 0.5)
	{
		p->crouch = p->crouch ? 0 : 1;
		ft_printf("%d\n", p->crouch);
		t0 = t1;
	}
}
