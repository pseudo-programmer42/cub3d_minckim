/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:11:55 by minckim           #+#    #+#             */
/*   Updated: 2020/07/14 00:43:00 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

/*
** t_real		screen_edge_x(t_real e, t_real d, t_vec *p, t_vec *q)
** {
** 	t_vec	u;
** 	t_real	det;
** 	t_real	t[3];
**
** 	u = *p;
** 	vec_sub(u, q);
** 	det = -u.x * e + u.y * d;
** 	t[0] = (e * q->x - d * q->y) / det;
** 	t[1] = -(u.y * q->x  u.x * q->y) / det;
** 	return (q->z + t[0] * u.z) / t[1];
** }
*/
