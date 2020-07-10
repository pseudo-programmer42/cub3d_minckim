#ifndef SCREEN_H
# define SCREEN_H
# include <mlx.h>
# include "../bitmap/bitmap.h"
# include "../linear_algebra/linear_algebra.h"
# include "../geometry/geometry.h"
# include "../libft/libft.h"
# include <stdlib.h>
# define BIG_REAL 1000000000
# define CAMERA_ANGLE M_PI / 2

typedef struct	s_img{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_pixel{
	t_real		distance;
	t_vec		ray;
	int			*color;
}				t_pixel;

typedef struct	s_screen{
	void		*mlx;
	void		*win;
	t_img		img;
	int			rx;
	int			ry;
	t_pixel		**pixel;
	t_vec		origin;
	t_real		h;
	t_real		v;
	t_real		tan_camera_angle_2;
	t_real		distance;
}				t_screen;


t_screen		init_screen(int rx, int ry, t_real angle);
void			mlx_pixel(t_img *img, int x, int y, int color);
t_pixel			**pixel_init(t_screen *screen);
void			screen_face(t_screen *s, t_face *f);
int				screen_point(t_screen *s, t_vec *v, t_real *point);
int				screen_face_point(t_screen *s, t_face *f, t_real *point);
void			set_boundary(int *boundary, t_real *point);
int				set_boundary_f(t_screen *s, t_face *f, int *boundary, t_real *point);
void			screen_entity(t_screen *s, t_entity *e);
void			refresh_screen(t_screen *s);
#endif