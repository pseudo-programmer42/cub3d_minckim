/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 04:24:21 by minckim           #+#    #+#             */
/*   Updated: 2020/07/08 04:44:21 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bitmap.h"

int			bitmap_pixel_color(t_bitmap *img, int i, int j)
{
	int	idx;

	if (i < 0 || img->width < i || j < 0 || img->height < j)
		return (0);
	idx = img->byte_per_line * j + i * img->byte_per_pixel;
	return ((*(int*)(&img->arr[idx])) & 0xffffff);
}

/*
** void		print_bitmap_arr(t_bitmap *img)
** {
** 	for (int j = 0 ; j < img->height ; j++)
** 	{
** 		for (int i = 0 ; i < img->width ; i++)
** 		{
** 			printf("%.6x ", bitmap_pixel_color(img, i, j));
** 		}
** 		printf("\n");
** 	}
** }
**
** void		print_bitmap_info(t_bitmap *img, int option)
** {
** 	printf("x    : %5d\n", img->width);
** 	printf("y    : %5d\n", img->height);
** 	if (option)
** 		print_bitmap_arr(img);
** }
*/

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
	img->byte_per_line = 3 * img->width + img->width % 4;
	return (0);
}

t_bitmap	*ft_bitmap(char *path)
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

/*
** int	main(void)
** {
** 	int		bf_size = 1000000;
** 	int 	fd;
** 	char	buffer[bf_size];
** 	int		line = 40;
** 	char	*path = "bittest_ps.bmp";
** 	int		size;
**
** 	fd = open(path, O_RDONLY);
** 	size = read(fd, buffer, bf_size);
** 	char	*tmp = buffer + 54;
** 	for (int i = 0; i < size - 54 ; i++)
** 	{
** 		printf("%3.2hhx", tmp[i]);
** 		if (i % line == (line - 1))
** 			printf("\n");
** 	}
**
**
** 	// printf("%15s| ", "head");			print(buffer, CHAR, 0, 2);
** 	// printf("%15s| ", "size");			print(buffer, INT, 2, 6);
** 	// printf("%15s| ", "array start");	print(buffer, INT, 10, 14);
** 	// printf("%15s| ", "header size");	print(buffer, INT, 14, 18);
** 	// printf("%15s| ", "width");			print(buffer, INT, 18, 22);
** 	// printf("%15s| ", "height");			print(buffer, INT, 22, 26);
** 	// printf("%15s| ", "bit/pix");		print(buffer, BYTE, 28, 30);
** 	// printf("%15s| ", "comp");			print(buffer, INT, 30, 34);
** 	// printf("%15s| ", "raw size");		print(buffer, INT, 34, 38);
** 	// printf("%15s| ", "resolution-h");	print(buffer, INT, 38, 42);
** 	// printf("%15s| ", "resolution-v");	print(buffer, INT, 42, 46);
** 	// printf("%15s| ", "color palette");	print(buffer, INT, 46, 50);
** 	// printf("%15s| ", "importantcolor");	print(buffer, INT, 50, 54);
**
** 	// print(buffer, BYTE, 54, 60);
** 	t_bitmap *img;
** 	img = ft_bitmap(path);
** 	printf("[%d]\n", img->size);
** 	for (int j = 0 ; j < img->height ; j++)
** 	{
** 		for (int i = 0 ; i < img->width ; i++)
** 		{
** 			printf("%.6x ", pixel_color(img, i, j));
** 		}
** 		printf("\n");
** 	}
** }
**
*/
