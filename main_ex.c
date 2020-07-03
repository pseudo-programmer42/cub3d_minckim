/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:50:27 by root              #+#    #+#             */
/*   Updated: 2020/06/29 15:06:25 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

typedef struct  s_vars {
	void        *mlx;
	void        *win;
}               t_vars;

int				my_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		printf("exit with %d\n", keycode);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
	{
		if (keycode == 0)
			mlx_clear_window(vars->mlx, vars->win);
		printf("pressed: %d\n", keycode);
	}
	return 0;
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int            color_from_img(t_data *data, int x, int y)
{
	return *((int*)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))));
}

int             main(void)
{
	t_data	img;
	t_data	img42;
	char	*path = "./east.xpm";
	int		img_x;
	int		img_y;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 480, 360);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int k = 0 ; k < 300 ; k += 1)
	{
		for (int i = 50; i < 100 ; i++)
		{
			for (int j = 50 ; j < 100 ; j++)
			{
				mlx_pixel_put(vars.mlx, vars.win, i+k, j+k/2, 0x00FFFF00+k);
			}
		}
		for (int i = 75; i < 125 ; i++)
		{
			for (int j = 75 ; j < 125 ; j++)
			{
				mlx_pixel_put(vars.mlx, vars.win, i+k, j+k/2, 0x0000FF00+k);
			}
		}
	}
	// img42.img = mlx_xpm_file_to_image(vars.mlx, path, &img_x, &img_y);
	// img42.addr = mlx_get_data_addr(img42.img, &img42.bits_per_pixel, &img42.line_length, &img42.endian);
	// for (int i = 0 ; i < img_x ; i++)
	// {
	// 	for (int j = 0 ; j < img_y ; j++)
	// 	{
	// 		int	c;
	// 		c = color_from_img(&img42, i, j);
	// 		mlx_pixel_put(vars.mlx, vars.win, i + 200, j + 350, c);
	// 	}
	// }

	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// mlx_put_image_to_window(vars.mlx, vars.win, img42.img, 0, 0);
	mlx_string_put(vars.mlx, vars.win, 20, 40, 0xFF0000, "HELLO WORLD!");
	mlx_key_hook(vars.win, my_close, &vars);
	// mlx_hook(vars.win, 3, 1L<<1, close, &vars);
	// mlx_hook(vars.win, 5, 1L<<3, close, &vars);
	// mlx_clear_window(vars.mlx, vars.win);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_loop(vars.mlx);
	mlx_loop(vars.mlx);
	mlx_loop(vars.mlx);



}