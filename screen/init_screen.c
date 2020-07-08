#include "screen.h"
#define BASIC_COLOR 0

t_screen	init_screen(int rx, int ry, t_real angle)
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
			tmp->color = s->img.addr + (j * s->img.line_length + i * (s->img.bits_per_pixel / 8));
		}
	}
	return (pixel);
}

void		mlx_pixel(t_img *img, int x, int y, int color)
{
	char    *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		screen_point(t_screen *s, t_vec *v, t_real *point)
{
	*point++ = s->rx / 2 - v->y * s->distance / v->x;
	*point = s->ry / 2 - v->z * s->distance / v->x;

}

void		screen_face_point(t_screen *s, t_face *f, t_real *point)
{
	screen_point(s, &(f->a), point);
	screen_point(s, &(f->b), point + 2);
	screen_point(s, &(f->c), point + 4);
	if (f->type == RECTANGLE)
		screen_point(s, &(f->c), point + 6);
}

void		set_boundary(t_real *boundary, t_real *point)
{
	boundary[0] = boundary[0] > point[0] ? point[0] : boundary[0];
	boundary[1] = boundary[1] > point[1] ? point[1] : boundary[1];
	boundary[2] = boundary[2] < point[0] ? point[0] : boundary[2];
	boundary[3] = boundary[3] < point[1] ? point[1] : boundary[3];
}

void		set_boundary_f(t_screen *s, t_face *f, t_real *boundary, t_real *point)
{
	boundary[0] = BIG_REAL;
	boundary[1] = BIG_REAL;
	boundary[2] = 0;
	boundary[3] = 0;
	screen_face_point(s, f, point);
	set_boundary(boundary, point);
	set_boundary(boundary, point + 2);
	set_boundary(boundary, point + 4);
	if (f->type == RECTANGLE)
		set_boundary(boundary, point + 6);
	boundary[0] = boundary[0] < 0 ? 0 : boundary[0];
	boundary[1] = boundary[1] < 0 ? 0 : boundary[1];
	boundary[2] = boundary[2] > s->rx ? s->rx : boundary[2];
	boundary[3] = boundary[3] > s->ry ? s->ry : boundary[3];
}

void		pixel_face(t_pixel *pixel, t_face *f)
{
	t_vec	u;
	t_vec	v;
	t_vec	a;
	t_mat	r;

	a = vec_new(f->a.x, f->a.y, f->a.z);
	vec_inv(&a);
	u = vec_new(f->b.x, f->b.y, f->b.z);
	v = vec_new(f->c.x, f->c.y, f->c.z);
	vec_add(&u, &a);
	vec_add(&v, &a);
	r = mat_new_vec(&u, &v, &(pixel->ray));
	mat_inverse(&r);
	mat_vec(&r, &a);
	if (a.x < 0 || 1 < a.x || a.y < 0 || 1 < a.y || a.z > 0 || a.z > pixel->distance)
		return ;
	if (f->type == TRIANGLE && a.x + a.y > 1)
		return ;
	if (f->img)
	{
		*(pixel->color) = bitmap_pixel_color(f->img, \
			a.x * ((t_bitmap*)(f->img))->width, \
			a.y * ((t_bitmap*)(f->img))->height);
	}
	else
	{
		*(pixel->color) = (f->color);
	}

}

void		screen_face(t_screen *s, t_face *f)
{
	t_real	boundary[4];
	t_real	point[8];
	t_face	tmp;
	int		i;
	int		j;

	tmp = face_copy(f);
	face_rot_rc(&tmp, &(s->origin), s->h, s->v);
	set_boundary_f(s, &tmp, boundary, point);
	i = boundary[0] - 1;
	while (++i < (int)(boundary[2] * 2) / 2)
	{
		j = boundary[1] - 1;
		while (++j < (int)(boundary[3] * 2) / 2)
		{
			pixel_face(&((s->pixel)[i][j]), f);
		}
	}

}