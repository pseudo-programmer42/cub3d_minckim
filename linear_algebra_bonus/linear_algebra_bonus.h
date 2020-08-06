/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:36:56 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:45:20 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_ALGEBRA_BONUS_H
# define LINEAR_ALGEBRA_BONUS_H
# define BIG_REAL INFINITY
# include <math.h>

typedef float	t_real;
typedef float	t_angle;

typedef struct	s_vec{
	t_real		x;
	t_real		y;
	t_real		z;
}				t_vec;

typedef struct	s_mat{
	t_real		a;
	t_real		b;
	t_real		c;
	t_real		d;
	t_real		e;
	t_real		f;
	t_real		g;
	t_real		h;
	t_real		i;
}				t_mat;
/*
** vec0.c----------------------------------------------------------------------
*/
t_vec			vec_new(t_real a, t_real b, t_real c);
t_vec			*vec_add(t_vec *a, t_vec *b);
t_vec			*vec_sub(t_vec *a, t_vec *b);
t_vec			*vec_inv(t_vec *a);
t_real			vec_dot(t_vec *a, t_vec *b);
/*
** vec1.c----------------------------------------------------------------------
*/
t_vec			vec_cross(t_vec *a, t_vec *b);
t_vec			*vec_rot(t_vec *a, t_angle h, t_angle v);
t_vec			*vec_rot_rc(t_vec *a, t_angle h, t_angle v);
t_vec			*vec_mul(t_vec *a, t_real b);
t_vec			*vec_unit(t_vec *a);
/*
** vec2.c----------------------------------------------------------------------
*/
t_vec			*vec_div(t_vec *a, t_real b);
t_real			vec_distance(t_vec *a, t_vec *b);
t_real			vec_distance2(t_vec *a, t_vec *b);
/*
** mat0.c----------------------------------------------------------------------
*/
t_mat			mat_new(t_real *a);
t_mat			*mat_add(t_mat *a, t_mat *b);
t_mat			*mat_sub(t_mat *a, t_mat *b);
t_mat			mat_mul(t_mat *a, t_mat *b);
t_vec			*mat_vec(t_mat *m, t_vec *v);
/*
** mat1.c----------------------------------------------------------------------
*/
t_mat			*mat_inverse(t_mat *a);
t_mat			*mat_inverse_det(t_mat *m, t_real *det);
t_mat			mat_rot(t_angle h, t_angle v);
t_mat			mat_rot_rc(t_angle h, t_angle v);
/*
** mat2.c----------------------------------------------------------------------
*/
t_mat			*mat_transpose(t_mat *a);
t_mat			mat_new_vec(t_vec *a, t_vec *b, t_vec *c);
/*
** equation.c------------------------------------------------------------------
*/
t_vec			equation_vector(t_vec *u, t_vec *v, t_vec *r, t_vec *x);
int				equation3(t_real *a, t_real *b, t_real *c);
/*
** equation_line_operation0.c--------------------------------------------------
*/
void			line_mul3(t_real *a, t_real b);
void			line_mul2(t_real *a, t_real b);
void			line_div3(t_real *a, t_real b);
void			line_div2(t_real *a, t_real b);
/*
** equation_line_operation1.c--------------------------------------------------
*/
void			line_sub3(t_real *a, t_real *b);
void			line_sub2(t_real *a, t_real *b);
int				equation2(t_real *a, t_real *b);
void			line_swap(t_real **a, t_real **b);
/*
** linear_algebra_print.c------------------------------------------------------
*/
void			mat_print(t_mat *a);
void			vec_print(t_vec *a);
#endif
