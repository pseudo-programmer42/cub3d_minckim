/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bitmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:28:34 by minckim           #+#    #+#             */
/*   Updated: 2020/07/22 20:31:23 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	screen_bitmap(t_screen *s, t_bitmap *b, int *left_top, double scale)
{
	int		i;
	int		j;
	int		color;
	int		mx_x;
	int		mx_y;

	mx_x = b->width * scale;
	if (mx_x + left_top[0] > s->rx)
		mx_x = s->rx - left_top[0];
	mx_y = b->height * scale;
	if (mx_y + left_top[1] > s->ry)
		mx_y = s->ry - left_top[1];
	i = -1;
	while (++i < mx_x)
	{
		j = 0;
		while (++j < mx_y)
		{
			color = bitmap_pixel_color(b, i / scale, b->height - j / scale);
			if (color != 0xffffff)
				*(s->pixel[i + left_top[0]][j + left_top[1]].color) = color;
		}
	}
}
