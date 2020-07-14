/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:12:34 by minckim           #+#    #+#             */
/*   Updated: 2020/07/15 04:15:09 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H
# include <mlx.h>
# include "../bitmap/bitmap.h"
# include "../linear_algebra/linear_algebra.h"
# include "../geometry/geometry.h"
# include "../libft/libft.h"
# include <stdlib.h>
# define CAMERA_ANGLE M_PI_2

typedef struct	s_img{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_pixel{
	t_real		distance;
	t_real		distance2;
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
	t_angle		h;
	t_angle		v;
	t_angle		tan_camera_angle_2;
	t_real		distance;
	t_angle		cos_cam;
}				t_screen;

/*
** ============================================================================
** init_screen.c
** ============================================================================
*/
t_screen		init_screen(int rx, int ry, t_real angle);
t_pixel			**pixel_init(t_screen *screen);
void			mlx_pixel(t_img *img, int x, int y, int color);
void			refresh_screen(t_screen *s);
/*
** ============================================================================
** screen_face.c
** ============================================================================
*/
void			screen_face(t_screen *s, t_face *f);
/*
** ============================================================================
** screen_face_util.c
** ============================================================================
*/
int				screen_point(t_screen *s, t_vec *v, t_real *point);
int				screen_face_point(t_screen *s, t_face *f, t_real *point);
void			set_boundary(int *boundary, t_real *point);
int				set_boundary_f(t_screen *s, t_face *f, int *b, t_real *point);
/*
** ============================================================================
** screen_entity.c
** ============================================================================
*/
void			screen_entity(t_screen *s, t_entity *e);
void			screen_item(t_screen *s, t_entity *e);
/*
** ============================================================================
** save_screenshot.c
** ============================================================================
*/
void			save_screenshot(int argc, char **argv, t_screen *s);
#endif
