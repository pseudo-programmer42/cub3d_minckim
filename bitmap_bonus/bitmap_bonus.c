/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 04:24:21 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:23:18 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bitmap_bonus.h"
#include "../libft/libft.h"

int			bitmap_pixel_color(t_bitmap *img, int i, int j)
{
	int	idx;

	if (i < 0 || img->width < i || j < 0 || img->height < j)
		return (0);
	idx = img->byte_per_line * j + i * img->byte_per_pixel;
	return ((*(int*)(&img->arr[idx])) & 0xffffff);
}

int			parse_bitmap_size_info(char *buffer, t_bitmap *img)
{
	if (*(int*)(&buffer[0]) == 40)
	{
		img->width = *(int*)(&buffer[4]);
		img->height = *(int*)(&buffer[8]);
		img->byte_per_pixel = ((*(int*)(&buffer[14])) & 0xffff) / 8;
		img->size = *(int*)(&buffer[20]);
	}
	else if (*(int*)(&buffer[0]) == 12)
	{
		img->width = (*(int*)(&buffer[4])) & 0xffff;
		img->height = (*(int*)(&buffer[6])) & 0xffff;
		img->byte_per_pixel = ((*(int*)(&buffer[10])) & 0xffff) / 8;
		img->size = img->width * img->height * img->byte_per_pixel;
	}
	else if (*(int*)(&buffer[0]) == 124)
	{
		img->width = *(int*)(&buffer[4]);
		img->height = *(int*)(&buffer[8]);
		img->byte_per_pixel = ((*(int*)(&buffer[14])) & 0xffff) / 8;
		img->size = *(int*)(&buffer[20]);
	}
	img->byte_per_line = img->byte_per_pixel * img->width + img->width % 4;
	return (0);
}

t_bitmap	*bitmap_new(char *path)
{
	int			fd;
	char		buffer[200];
	t_bitmap	*img;

	if ((fd = open(path, O_RDONLY)) < 0)
	{
		write(1, "Can not open the image\n", 23);
		return (0);
	}
	read(fd, buffer, 14);
	if (buffer[0] != 'B' && buffer[1] != 'M')
		return (0);
	read(fd, buffer, *(int*)(&buffer[10]) - 14);
	if (!(img = (t_bitmap*)malloc(sizeof(t_bitmap))))
		return (0);
	if (parse_bitmap_size_info(buffer, img))
		return (0);
	if (!(img->arr = (char*)malloc(sizeof(int) * img->size)))
		return (0);
	read(fd, img->arr, img->size);
	close(fd);
	return (img);
}

void		bitmap_del(t_bitmap *b)
{
	free(b->arr);
	free(b);
	b = 0;
}
