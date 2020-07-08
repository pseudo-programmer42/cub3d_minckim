/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:26:10 by minckim           #+#    #+#             */
/*   Updated: 2020/07/07 04:26:14 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "linear_algebra.h"

void	vec_print(t_vec a)
{
	printf("%10.3f %10.3f %10.3f\n", a.x, a.y, a.z);
}

void	mat_print(t_mat a)
{
	printf("%10.3f %10.3f %10.3f\n", a.a, a.b, a.c);
	printf("%10.3f %10.3f %10.3f\n", a.d, a.e, a.f);
	printf("%10.3f %10.3f %10.3f\n", a.g, a.h, a.i);
	printf("-----------------------------------------\n");
}