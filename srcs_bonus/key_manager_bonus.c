/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 09:56:23 by minckim           #+#    #+#             */
/*   Updated: 2020/07/20 13:31:27 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		key_press_manager(int key, long long *keys)
{
	keys[key / 64] |= (1 << (key % 64));
	return (0);
}

int		key_release_manager(int key, long long *keys)
{
	keys[key / 64] &= ~(1 << (key % 64));
	return (0);
}

int		is_pressed(int key, long long *keys)
{
	if (keys[key / 64] & 1 << (key % 64))
		return (1);
	else
		return (0);
}

int		mouse_press(int button, int x, int y, t_gamedata *g_data)
{
	(void)g_data;
	ft_printf("button: %d | %d %d\n", button, x, y);
	return (0);
}
