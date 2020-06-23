#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

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

int             main(void)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 480, 360);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 50; i < 100 ; i++)
	{
		for (int j = 50 ; j < 100 ; j++)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FFFF00);
		}
	}
	for (int i = 75; i < 125 ; i++)
	{
		for (int j = 75 ; j < 125 ; j++)
		{
			my_mlx_pixel_put(&img, i, j, 0x0000FF00);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, my_close, &vars);
	// mlx_hook(vars.win, 3, 1L<<1, close, &vars);
	// mlx_hook(vars.win, 5, 1L<<3, close, &vars);
	mlx_loop(vars.mlx);
}