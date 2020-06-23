/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 09:40:55 by root              #+#    #+#             */
/*   Updated: 2020/06/23 09:44:31 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	read_f(int fd)
{
	char	buff[100];
	read(fd, buff, 100);
	write(1, buff, 100);
	return 0;
}

int	main(void)
{
	int		fd;

	fd = open("map2.cub", O_RDONLY);
	read_f(fd);
	return (0);
}
