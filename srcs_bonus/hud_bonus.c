/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:25:44 by minckim           #+#    #+#             */
/*   Updated: 2020/07/20 13:31:43 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	screen_hud(t_screen *s, t_gamedata *g_data)
{
	screen_lifebar(s, g_data->texture[IMG_LIFEBAR], &g_data->player);
	screen_stand_crouch(s, g_data);
}
