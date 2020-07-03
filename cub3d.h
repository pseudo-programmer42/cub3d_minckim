/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   newd: 2020/06/29 16:58:46 by minckim           #+#    #+#             */
/*   Updated: 2020/06/30 06:05:49 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "./libft/libft.h"
# define TRUE 1
# define FALSE 0
# define CELL_SIZE 3000
# define WALL_HEIGHT 3000
# define EYE_LEVEL 1700
# define SOUTH 0
# define EAST 1
# define NORTH 2
# define WEST 3
/*
 * check list macro
*/
# define RESOLUTION 1
# define NORTH_TEXTURE 2
# define SOUTH_TEXTURE 4
# define EAST_TEXTURE 8
# define WEST_TEXTURE 16
# define SPRITE_TEXTURE 32
# define FLOOR_COLOR 64
# define CEILLING_COLOR 128
# define PI 3.14159265358979323846264338327950288419L

typedef double*	vec;
/*
** type :
**	0 == bitmap
**	1 == xpm
*/

typedef struct	s_image{
	int			type;
	int			width;
	int			height;
	int			byte_per_line;
	int			byte_per_pixel;
	int			size;
	char		*arr;
}				t_image;

typedef struct	s_mlx_image{
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}				t_mlx_image;

typedef struct	s_info_data{
	int			checklist;
	int			floor_color;
	int			ceilling_color;
	int			resolution[2];
	char		north_texture[500];
	char		south_texture[500];
	char		east_texture[500];
	char		west_texture[500];
	char		sprite_texture[500];
}				t_info_data;

typedef struct	s_face{
	int			instance_type;
	double		p[9];
	t_image		*img;
	int			color;
}				t_face;

typedef struct	s_object{
	int			instance_type;
	t_list		*lst_face;
}				t_object;

/*
** texture : [0]=east -> [1]=north ->  [2]=west -> [3]=south
*/
typedef struct	s_runtime_data{
	t_image		*wall_texture[4];
	t_image		*sprite_texture;
	int			floor_color;
	int			ceilling_color;
	t_list		*lst_object;
	double		player_coord[3];
	double		player_sight[2];
}				t_runtime_data;

typedef struct	s_screen{
	int			width;
	int			height;
	int			*pixel;
	double		*ray_base;
	double		*ray;
	double		*distance;
}				t_screen;

int				is_map_line(char *line);
int				is_info_line(char **line_segment);

void			parse_map_line(char *line, t_list **map_data);
void			parse_info_line(char **line_segment, t_info_data *info_data);

void			exit_message(char *err_massage);
int				init(int argc, char **argv, t_runtime_data *runtime_data);

void			init_image(t_info_data *info_data, t_runtime_data *runtime_data);
void			build_map(t_list *map, t_runtime_data *t_runtime_data);

/*
** bitmap convertor
*/
int				bitmap_pixel_color(t_image *img, int i, int j);
void			bitmap_del(t_image *img);
t_image			*ft_bitmap(char *path);

/*
** input:
**	point_start	: coordinate of player's eye
**	unit		: unit vector of ray start from player's eye
**	r			: double array that going to save the result
** return: addr of r
** 	3 numbers.
**	 r[0] : multiplier of face vector0
**	 r[1] : multiplier of face vector1
**	 r[2] : distance between point start and intersect point
*/
double			*face_unit_intersect(t_face *face, double *point_start, \
				double *unit, double *r);

/*
** return:
**	if image ptr is null, return face's color
**	else color by uv vector
*/
int				get_color(t_face *face, double *u, double *v);

/*
** return:
**	screen contains many pixels that contain rays
*/
t_screen		init_screen_pixel(int scr_x, int scr_y, double cam_angle);

/*
** return:
**	wall that center is 0,0
** input:
**	void	*img	: struct bitmap data or xpm data
*/
t_object		*object_new(char c, t_object object);
t_object		*object_copy(t_object *object, double *dir);
t_object		*object_move(t_object *object, double *dir);
t_object		*object_rot_h(t_object *object, double *org, double angle);
void			object_del(t_object *object);

t_object		*wall_new(t_runtime_data *runtime_data, int x, int z);
t_object		*floor_ceilling_new(t_runtime_data *runtime_data, int x, int z);
t_object		*sprite_new(t_runtime_data *runtime_data, int x, int z);

t_list			*lstflatten_face(t_list *object);

t_face			*face_new(t_image *img, int color, double *u, double *v);
t_face			*face_copy(t_face *face, double *dir);
t_face			*face_move(t_face *face, double *dir);
t_face			*face_rot_h(t_face *face, double *org, double angle);
t_face			*face_rot_v(t_face *face, double *org, double angle_h, \
				double angle_v);
void			*face_deepcopy(void *face);
void			face_del(void *face);
void			face_print_coord(t_face *face);
/*
** vector/linear algebra function
**	return: addr of v or v1, that has been changed by func.
*/
double			*vector_new(double p0, double p1, double p2, double *r);
double			*vector_copy(double *v, double *r);
double			*vector_add(double *v1, double *v2);
double			*vector_mat_mul(double *mat, double *v);
double			*vector_sub(double *v1, double *v2);
double			*vector_rot_h(double *v, double angle);
double			*vector_rot_v(double *v, double angle_h, double angle_v);
double			*vector_rot(double *v, double angle_h, double angle_v);
void			vector_print(double *v);

void			player_move(t_runtime_data *runtime_data, double *dir);
void			player_rot_h(t_runtime_data *runtime_data, double angle);
void			player_rot_v(t_runtime_data *runtime_data, double angle);
void			player_rot(t_runtime_data *runtime_data, double angle);

void			all_pixel_to_image(t_mlx_image *img, t_screen *screen);

void			print_image_info(t_image *img, int option);


#endif