/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:36:50 by minckim           #+#    #+#             */
/*   Updated: 2020/07/15 02:35:04 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "linear_algebra.h"

void	vec_print(t_vec *a)
{
	ft_printf("%15.9f %15.9f %15.9f\n", a->x, a->y, a->z);
}

void	mat_print(t_mat *a)
{
	ft_printf("%15.9f %15.9f %15.9f\n", a->a, a->b, a->c);
	ft_printf("%15.9f %15.9f %15.9f\n", a->d, a->e, a->f);
	ft_printf("%15.9f %15.9f %15.9f\n", a->g, a->h, a->i);
	ft_printf("-----------------------------------------\n");
}
