/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 01:04:02 by minckim           #+#    #+#             */
/*   Updated: 2020/07/14 03:43:08 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

size_t	put_data_fd(int fd, size_t data, size_t size)
{
	return (write(fd, &data, size));
}

/*
** offeset
**	2	"BM"
**	4	size
**	4	reserved
**	4	array offset
**	4	x size
**	4	y size
**	4	num of color plane (1)
**	2	bit per pixel
**	4
**	4
**	4
**	4
**	4
**	4
**	~	array
*/

void	save_screenshot(int argc, char **argv, t_screen *s)
{
	int			fd;
	int			j;

	if (argc != 3 || ft_strncmp(argv[2], "--save", 6))
		return ;
	fd = open("cub3d_save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, "BM", 2);
	put_data_fd(fd, s->ry * s->img.line_length + 54, 4);
	put_data_fd(fd, 0, 4);
	put_data_fd(fd, 54, 4);
	put_data_fd(fd, 40, 4);
	put_data_fd(fd, s->rx, 4);
	put_data_fd(fd, s->ry, 4);
	put_data_fd(fd, 1, 2);
	put_data_fd(fd, 32, 2);
	j = -1;
	while (++j < 6)
		put_data_fd(fd, 0, 4);
	j = s->ry;
	while (--j >= 0)
		write(fd, s->img.addr + s->img.line_length * j, s->img.line_length);
	close(fd);
}
