/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 01:13:40 by minckim           #+#    #+#             */
/*   Updated: 2020/07/19 12:05:28 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	player_turn(t_player *player, long long *keys)
{
	static clock_t	t0;
	clock_t			t1;

	if (!t0)
		t0 = clock();
	t1 = clock();
	if ((double)(t1 - t0) / CLOCKS_PER_SEC < TIME_SEGMENT)
		return ;
	if (is_pressed(KEY_LF, keys))
		player->h += ANGLE_UNIT;
	if (is_pressed(KEY_RT, keys))
		player->h -= ANGLE_UNIT;
	if (is_pressed(KEY_UP, keys))
		player->v += ANGLE_UNIT;
	if (is_pressed(KEY_DN, keys))
		player->v -= ANGLE_UNIT;
}

t_angle	angle_combination(long long *keys)
{
	t_angle	h;

	if (is_pressed(KEY_A, keys) && is_pressed(KEY_W, keys))
		h = M_PI_4;
	else if (is_pressed(KEY_D, keys) && is_pressed(KEY_W, keys))
		h = -M_PI_4;
	else if (is_pressed(KEY_A, keys) && is_pressed(KEY_S, keys))
		h = M_PI_2 + M_PI_4;
	else if (is_pressed(KEY_D, keys) && is_pressed(KEY_S, keys))
		h = -M_PI_2 - M_PI_4;
	else if (is_pressed(KEY_A, keys))
		h = M_PI_2;
	else if (is_pressed(KEY_D, keys))
		h = -M_PI_2;
	else if (is_pressed(KEY_W, keys))
		h = 0;
	else if (is_pressed(KEY_S, keys))
		h = M_PI;
	return (h);
}

void	player_move(t_gamedata *g_data, long long *keys)
{
	static clock_t	t0;
	clock_t			t1;
	t_vec			m;

	if (!t0)
		t0 = clock();
	t1 = clock();
	if ((double)(t1 - t0) / CLOCKS_PER_SEC < TIME_SEGMENT)
		return ;
	t0 = t1;
	if (is_pressed(KEY_A, keys)\
		|| is_pressed(KEY_D, keys)\
		|| is_pressed(KEY_W, keys)\
		|| is_pressed(KEY_S, keys))
	{
		m = vec_new(MOVE_WALK, 0, 0);
		vec_rot(&m, angle_combination(keys) + g_data->player.h, 0);
		if (!(check_collision(g_data, &m)))
			vec_add(&(g_data->player.origin), &m);
	}
}
