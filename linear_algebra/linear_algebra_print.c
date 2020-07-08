/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:36:50 by minckim           #+#    #+#             */
/*   Updated: 2020/07/08 05:19:34 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "linear_algebra.h"

void	vec_print(t_vec *a)
{
	ft_printf("%10.3f %10.3f %10.3f\n", a->x, a->y, a->z);
}

void	mat_print(t_mat *a)
{
	ft_printf("%10.3f %10.3f %10.3f\n", a->a, a->b, a->c);
	ft_printf("%10.3f %10.3f %10.3f\n", a->d, a->e, a->f);
	ft_printf("%10.3f %10.3f %10.3f\n", a->g, a->h, a->i);
	ft_printf("-----------------------------------------\n");
}
