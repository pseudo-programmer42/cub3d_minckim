#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int	main(void)
{
	t_screen	screen;
	t_bitmap	*bitmap;

	// screen = init_screen(1000, 1000, 100);
	bitmap = ft_bitmap("./texture/super.bmp");
	screen = init_screen(bitmap->width, bitmap->height, M_PI/2);
	// print_bitmap_info(b, 0);
	// for (int i = 0 ; i < bitmap->width ; i++)
	// 	for (int j = 0 ; j < bitmap->height ; j++)
	// 		mlx_pixel(&screen.img, i, j, bitmap_pixel_color(bitmap, i, j));

	t_vec	a = vec_new(100, 0, 0);
	t_vec	b = vec_new(100, 100, 0);
	t_vec	c = vec_new(100, 0, 20);
	t_face	tri0 = face_new(a, b, c, TRIANGLE);
	face_rot(&tri0, &a, M_PI/5, 0);
	tri0.img = bitmap;
	screen_face(&screen, &tri0);
	mlx_put_image_to_window(screen.mlx, screen.win, screen.img.img, 0, 0);
	// screen_face(tri1);
	mlx_loop(screen.mlx);
}

// int	main(void)
// {
// 	t_mat	r1;
// 	t_mat	r2;
// 	t_mat	r3;

// 	r1 = mat_rot(0.5,0.5);
// 	mat_print(&r1);
// 	r2 = mat_rot(0.5,0.5);
// 	mat_inverse(&r2);
// 	mat_print(&r2);
// 	r3 = mat_mul(&r1, &r2);
// 	mat_print(&r3);
// }