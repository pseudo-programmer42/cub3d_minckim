/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 00:39:43 by minckim           #+#    #+#             */
/*   Updated: 2020/07/18 14:55:46 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_common.h"
#define FILTER_SIZE 2

double	fps_filter(double x)
{
	static double	fps;

	fps = (fps * (FILTER_SIZE - 1) + x) / (FILTER_SIZE);
	return (fps);
}

char	*ft_strinsert(char *dst, char *ins, int idx)
{
	char	*r;
	char	*r_tmp;
	int		len_dst;
	int		len_ins;
	char	*dst_tmp;

	dst_tmp = dst;
	len_dst = ft_strlen(dst);
	len_ins = ft_strlen(ins);
	r = (char*)malloc(sizeof(char) * (len_dst + len_ins + 1));
	r_tmp = r;
	if (idx < 0)
		idx = len_dst + idx + 1;
	while (idx-- > 0)
		*r++ = *dst++;
	while (*ins)
		*r++ = *ins++;
	while (*dst)
		*r++ = *dst++;
	*r = 0;
	free(dst_tmp);
	return (r_tmp);
}

char	*frame_string(clock_t frame_start)
{
	static clock_t		t0;
	clock_t				t1;
	char				*str_int;
	static double		fps_prev;
	double				fps;

	t1 = clock();
	fps = 1000 * (double)((CLOCKS_PER_SEC) / (t1 - frame_start));
	fps = fps_filter(fps);
	if ((double)((t1 - t0) / CLOCKS_PER_SEC) > 0.5)
	{
		str_int = ft_itoa(fps);
		str_int = ft_strinsert(str_int, ".", -4);
		str_int = ft_strinsert(str_int, "FPS: ", 0);
		t0 = t1;
		fps_prev = fps;
		return (str_int);
	}
	else
	{
		str_int = ft_itoa(fps_prev);
		str_int = ft_strinsert(str_int, ".", -4);
		str_int = ft_strinsert(str_int, "FPS: ", 0);
		return (str_int);
	}
}

void	print_fps(clock_t frame_start, t_screen *s)
{
	char			*s1;

	s1 = frame_string(frame_start);
	mlx_string_put(s->mlx, s->win, 10, 10, 0x00FFFF00, s1);
	free(s1);
	return ;
}
