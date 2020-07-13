/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 01:13:40 by minckim           #+#    #+#             */
/*   Updated: 2020/07/14 03:40:41 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_turn(t_player *player, int key)
{
	if (key == KEY_LF)
		player->h += ANGLE_UNIT;
	else if (key == KEY_RT)
		player->h -= ANGLE_UNIT;
	else if (key == KEY_UP)
		player->v += ANGLE_UNIT;
	else if (key == KEY_DN)
		player->v -= ANGLE_UNIT;
}

void	player_move(t_player *player, int key, int run)
{
	t_vec	m;
	int		speed;

	speed = run ? MOVE_RUN : MOVE_WALK;
	m = vec_new(speed, 0, 0);
	if (key == KEY_A)
		vec_rot(&m, player->h + M_PI / 2, 0);
	else if (key == KEY_D)
		vec_rot(&m, player->h - M_PI / 2, 0);
	else if (key == KEY_W)
		vec_rot(&m, player->h, 0);
	else if (key == KEY_S)
		vec_rot(&m, player->h + M_PI, 0);
	vec_add(&(player->origin), &m);
}

void	player_fly(t_player *player, int key)
{
	if (key == KEY_X)
		player->origin.z += MOVE_RUN;
	else if (key == KEY_SPC)
		player->origin.z -= MOVE_RUN;
}