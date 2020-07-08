/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:26:17 by minckim           #+#    #+#             */
/*   Updated: 2020/07/07 04:34:58 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_ALGEBRA_H
# define LINEAR_ALGEBRA_H
# include <math.h>

typedef	double	real;

typedef struct	s_vec{
	real		x;
	real		y;
	real		z;
}				t_vec;

typedef struct	s_mat{
	real		a;
	real		b;
	real		c;
	real		d;
	real		e;
	real		f;
	real		g;
	real		h;
	real		i;
}				t_mat;

/*
** ============================================================================
** vector
** ============================================================================
*/
t_vec			vec_new(real a, real b, real c);
t_vec			vec_add(t_vec a, t_vec b);
t_vec			vec_sub(t_vec a, t_vec b);
t_vec			vec_inv(t_vec a);
t_vec			vec_cross(t_vec a, t_vec b);
t_vec			vec_mul(t_vec a, real b);
t_vec			vec_rot(t_vec a, real ah, real av);
real			vec_dot(t_vec a, t_vec b);
/*
** ============================================================================
** matrix
** ============================================================================
*/
t_mat			mat_new(real *a);
t_mat			mat_add(t_mat a, t_mat b);
t_mat			mat_sub(t_mat a, t_mat b);
t_mat			mat_mul(t_mat a, t_mat b);
t_mat			mat_transpose(t_mat a);
t_mat			mat_inverse(t_mat a);
t_mat			mat_rot(real ah, real av);
t_vec			vec_mat(t_mat m, t_vec v);
void			vec_print(t_vec a);
void			mat_print(t_mat a);
#endif
