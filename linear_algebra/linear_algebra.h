/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:36:56 by minckim           #+#    #+#             */
/*   Updated: 2020/07/14 00:08:45 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_ALGEBRA_H
# define LINEAR_ALGEBRA_H
# include <math.h>

typedef float	t_real;

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
** ============================================================================
** vector
** ============================================================================
*/
/*
** vec0.c----------------------------------------------------------------------
*/
t_vec			vec_new(t_real a, t_real b, t_real c);
t_vec			*vec_add(t_vec *a, t_vec *b);
/*
** vec1.c----------------------------------------------------------------------
*/
t_vec			*vec_sub(t_vec *a, t_vec *b);
t_vec			*vec_inv(t_vec *a);
t_vec			*vec_mul(t_vec *a, t_real b);
t_vec			*vec_div(t_vec *a, t_real b);
/*
** vec2.c----------------------------------------------------------------------
*/
t_vec			*vec_rot(t_vec *a, t_real h, t_real v);
t_vec			*vec_rot_rc(t_vec *a, t_real h, t_real v);
t_vec			vec_cross(t_vec *a, t_vec *b);
t_vec			*vec_unit(t_vec *a);
t_real			vec_dot(t_vec *a, t_vec *b);
/*
** ============================================================================
** matrix
** ============================================================================
*/
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
t_mat			mat_rot(t_real h, t_real v);
t_mat			mat_rot_rc(t_real h, t_real v);
/*
** mat2.c----------------------------------------------------------------------
*/
t_mat			*mat_transpose(t_mat *a);
t_mat			mat_new_vec(t_vec *a, t_vec *b, t_vec *c);
/*
** ============================================================================
** linear_algebra_print.c
** ============================================================================
*/
void			mat_print(t_mat *a);
void			vec_print(t_vec *a);
#endif
