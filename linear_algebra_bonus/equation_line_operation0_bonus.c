/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_line_operation0_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 00:26:56 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:22:36 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra_bonus.h"

void	line_mul3(t_real *a, t_real b)
{
	a[1] *= b;
	a[2] *= b;
	a[3] *= b;
}

void	line_mul2(t_real *a, t_real b)
{
	a[1] *= b;
	a[2] *= b;
}

void	line_div3(t_real *a, t_real b)
{
	a[1] /= b;
	a[2] /= b;
	a[3] /= b;
	*a = 1;
}

void	line_div2(t_real *a, t_real b)
{
	a[1] /= b;
	a[2] /= b;
	*a = 1;
}
