/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:05:48 by minckim           #+#    #+#             */
/*   Updated: 2020/07/18 18:18:34 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		mouse_motion(int a, int b, t_gamedata *g_data)
{
	static int	a_prev;
	static int	b_prev;
	int			x;
	int			y;

	x = a - a_prev;
	y = b - b_prev;
	a_prev = a;
	b_prev = b;
	g_data->player.h -= x * 0.005;
	g_data->player.v -= y * 0.005;
	return (0);
}
