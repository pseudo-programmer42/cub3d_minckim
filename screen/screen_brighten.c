/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_brighten.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:21:16 by minckim           #+#    #+#             */
/*   Updated: 2020/07/22 19:28:37 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	pixel_brighten(t_pixel *p, t_real value)
{
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;

	r = ((unsigned char*)(p->color)) + 2;
	g = ((unsigned char*)(p->color)) + 1;
	b = ((unsigned char*)(p->color)) + 0;
	*r = (t_real)*r * value > 255 ? 255 : *r * value;
	*g = (t_real)*g * value > 255 ? 255 : *g * value;
	*b = (t_real)*b * value > 255 ? 255 : *b * value;
}

void	pixel_gray(t_pixel *p)
{
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	int				v;

	r = ((unsigned char*)(p->color)) + 2;
	g = ((unsigned char*)(p->color)) + 1;
	b = ((unsigned char*)(p->color)) + 0;
	v = (*r + *g + *b) / 3;
	*r = v;
	*g = v;
	*b = v;
}

void	screen_brighten(t_screen *s, t_real value)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->rx)
	{
		j = -1;
		while (++j < s->ry)
		{
			pixel_brighten(&s->pixel[i][j], value);
		}
	}
}

void	screen_gray(t_screen *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->rx)
	{
		j = -1;
		while (++j < s->ry)
		{
			pixel_gray(&s->pixel[i][j]);
		}
	}
}

void	screen_rgb(t_screen *s, t_real value, int rgb)
{
	int				i;
	int				j;
	unsigned char	*c;

	i = -1;
	while (++i < s->rx)
	{
		j = -1;
		while (++j < s->ry)
		{
			c = (unsigned char*)(s->pixel[i][j].color) + rgb;
			*c = *c * value > 255 ? 255 : *c * value;
		}
	}
}
