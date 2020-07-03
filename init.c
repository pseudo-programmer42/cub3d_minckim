/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:57:26 by minckim           #+#    #+#             */
/*   Updated: 2020/07/01 00:51:06 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_message(char *err_massage)
{
	ft_printf("Error\n-%s\n", err_massage);
	exit(1);
}

void	check_err(t_info_data *info_data)
{
	if ((info_data->checklist & NORTH_TEXTURE) == 0)
		exit_message("init check: north texture path is missing.");
	if ((info_data->checklist & SOUTH_TEXTURE) == 0)
		exit_message("init check: south texture path is missing.");
	if ((info_data->checklist & EAST_TEXTURE) == 0)
		exit_message("init check: east texture path is missing.");
	if ((info_data->checklist & WEST_TEXTURE) == 0)
		exit_message("init check: west texture path is missing.");
	if ((info_data->checklist & SPRITE_TEXTURE) == 0)
		exit_message("init check: sprite texture path is missing.");
	if ((info_data->checklist & FLOOR_COLOR) == 0)
		exit_message("init check: floor color is not defined.");
	if ((info_data->checklist & CEILLING_COLOR) == 0)
		exit_message("init check: floor color is not defined.");
	if ((info_data->checklist & RESOLUTION) == 0)
		exit_message("init check: resolution data is missing.");
}

int		parse(char *path, t_info_data *info_data, t_list **map_data)
{
	char	**line_segment;
	char	*line;
	int		fd;
	int		check_err;
	int		i;

	fd = open(path, O_RDONLY);
	while ((check_err = get_next_line(fd, &line)) > 0)
	{
		line_segment = ft_split(line, ' ');
		if (is_info_line(line_segment) == TRUE)
			parse_info_line(line_segment, info_data);
		else if (is_map_line(line) == TRUE)
			parse_map_line(line, map_data);
		i = 0;
		while (line_segment[i])
			free(line_segment[i++]);
		free(line_segment);
		free(line);
	}
	if (check_err < 0)
		exit_message("loading failed");
	close(fd);
	return (0);
}

void	save_bitmap(void)
{
	ft_printf("saving bitmap image...\n");
}

void	check_arg(int argc, char **argv)
{
	if (argc == 1)
		exit_message("Map data empty");
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4))
		exit_message("Type of input file is wrong.");
	if (argc == 3)
		if (ft_strncmp(argv[2], "--save", ft_strlen("--save")))
			exit_message("wrong input\n");
	if (argc > 3)
		exit_message("Too many input");
}

void	init_image_n_color(t_info_data *info_data, t_runtime_data *runtime_data)
{
	runtime_data->wall_texture[0] = ft_bitmap(info_data->east_texture);
	runtime_data->wall_texture[1] = ft_bitmap(info_data->north_texture);
	runtime_data->wall_texture[2] = ft_bitmap(info_data->west_texture);
	runtime_data->wall_texture[3] = ft_bitmap(info_data->south_texture);
	runtime_data->sprite_texture = ft_bitmap(info_data->sprite_texture);
	runtime_data->floor_color = info_data->floor_color;
	runtime_data->ceilling_color = info_data->ceilling_color;
}

int	init(int argc, char **argv, t_runtime_data *runtime_data)
{
	t_list		*map_data;
	t_info_data	info_data;

	ft_memset(&map_data, 0, sizeof(map_data));
	ft_memset(&info_data, 0, sizeof(t_info_data));
	check_arg(argc, argv);
	parse(argv[1], &info_data, &map_data);
	init_image_n_color(&info_data, runtime_data);
	build_map(map_data, runtime_data);
	if (argc == 3)
		save_bitmap();
	return (0);
}