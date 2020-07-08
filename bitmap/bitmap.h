/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:02:23 by minckim           #+#    #+#             */
/*   Updated: 2020/07/07 05:02:54 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

typedef struct	s_bitmap{
	int			type;
	int			width;
	int			height;
	int			byte_per_line;
	int			byte_per_pixel;
	int			size;
	char		*arr;
}				t_bitmap;

t_bitmap		*ft_bitmap();
int				bitmap_pixel_color(t_bitmap *img, int i, int j);
#endif
