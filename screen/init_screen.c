/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 23:50:15 by minckim           #+#    #+#             */
/*   Updated: 2020/07/16 00:38:11 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#define BASIC_COLOR 0

t_screen	init_screen(int rx, int ry, t_angle angle)
{
	t_screen	screen;
	t_img		*img;

	screen.origin = vec_new(0, 0, 0);
	screen.h = 0;
	screen.v = 0;
	screen.rx = rx;
	screen.ry = ry;
	screen.mlx = mlx_init();
	screen.win = mlx_new_window(screen.mlx, rx, ry, "cub3d_minckim");
	img = &(screen.img);
	img->img = mlx_new_image(screen.mlx, rx, ry);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
	screen.tan_camera_angle_2 = tan(angle / 2) * 2;
	screen.distance = screen.rx / screen.tan_camera_angle_2;
	screen.cos_cam = cos(angle / 2);
	screen.pixel = pixel_init(&screen);
	return (screen);
}

t_pixel		**pixel_init(t_screen *s)
{
	t_pixel	**pixel;
	int		i;
	int		j;
	t_pixel	*tmp;

	pixel = (t_pixel**)malloc(sizeof(t_pixel*) * s->rx);
	i = -1;
	while (++i < s->rx)
	{
		j = -1;
		pixel[i] = (t_pixel*)malloc(sizeof(t_pixel) * s->ry);
		while (++j < s->ry)
		{
			tmp = &(pixel[i][j]);
			tmp->distance = BIG_REAL;
			tmp->ray = vec_new(s->distance, s->rx / 2 - i, s->ry / 2 - j);
			vec_unit(&tmp->ray);
			tmp->color = s->img.addr + \
				(j * s->img.line_length + i * (s->img.bits_per_pixel / 8));
		}
	}
	return (pixel);
}

void		mlx_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		refresh_screen(t_screen *s)
{
	int		i;
	int		j;
	t_pixel	**p;

	p = s->pixel;
	i = -1;
	while (++i < s->rx)
	{
		j = -1;
		while (++j < s->ry)
		{
			(p[i][j]).distance = BIG_REAL;
		}
	}
}
