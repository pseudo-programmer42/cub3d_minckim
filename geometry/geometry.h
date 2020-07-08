#ifndef GEOMETRY_H
# define GEOMETRY_H
# define TRIANGLE 0
# define RECTANGLE 1
# include "../linear_algebra/linear_algebra.h"
# define DEF_COLOR 0x00ff0000
/*
** face type:
**	0 : triangle
**	1 : rectangle
*/
typedef struct		s_face{
	int				type;
	int				color;
	void			*img;
	t_vec			a;
	t_vec			b;
	t_vec			c;
}					t_face;

/*
** entity type:
**	-1 : non
**	0 : floor and ceilling
**	1 : wall
**	2 : sprite
*/
typedef struct		s_entity{
	int				type;
	int				n_face;
	t_vec			origin;
	t_real			h;
	t_real			v;
	t_face			*face;
}					t_entity;

t_face				face_new(t_vec a, t_vec b, t_vec c, int color);
t_face				face_copy(t_face *f);
t_face				*face_move(t_face *f, t_vec *v);
t_face				*face_rot(t_face *f, t_vec *center, t_real h, t_real v);
t_face				*face_rot_rc(t_face *f, t_vec *center, t_real h, t_real v);

t_entity	*entity_move(t_entity *e, t_vec *v);
t_entity	*entity_rot(t_entity *e, t_real h, t_real v);
t_entity	entity_deepcopy(t_entity *e, t_vec *v);
t_entity	entity_copy(t_entity *e, t_vec *v);

void	face_print(t_face *f);


#endif