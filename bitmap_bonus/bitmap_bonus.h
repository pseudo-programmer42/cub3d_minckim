/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:02:23 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:45:58 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_BONUS_H
# define BITMAP_BONUS_H

typedef struct	s_bitmap{
	int			type;
	int			width;
	int			height;
	int			byte_per_line;
	int			byte_per_pixel;
	int			size;
	char		*arr;
}				t_bitmap;

t_bitmap		*bitmap_new();
int				bitmap_pixel_color(t_bitmap *img, int i, int j);
void			bitmap_del(t_bitmap *b);
#endif
