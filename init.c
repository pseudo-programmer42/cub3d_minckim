/*pseudo code

init()
	info_data
	map_data
	runtime_data

	while (get_next_line(fd, &line))
		line_segment = split(line, ' ')
		if is_info_data(line) == true
			parse_info_data(line, &info_data)
				if strcmp(line_segment[0] == "R") == 0
					init_resolution()...
				else if ...
					...
				else if ...
					...
		else if is_map_data(line) == true
			parse_map_data((line, &init_data))
				get_map_size()
					t_list	*map;
					...
				init_map()
		free(line_segment);	//free all
		free(line)



*/
#include "cub3d.h"

void	exit_print(char *err_massage)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(err_massage, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

t_point	make_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

int		is_info_line(char **line_segment)
{
	if (ft_strncmp(line_segment[0], "R", 1) == 0)
		return (TRUE);
	if (ft_strncmp(line_segment[0], "NO", 2) == 0)
		return (TRUE);
	if (ft_strncmp(line_segment[0], "SO", 2) == 0)
		return (TRUE);
	if (ft_strncmp(line_segment[0], "EA", 2) == 0)
		return (TRUE);
	if (ft_strncmp(line_segment[0], "WE", 2) == 0)
		return (TRUE);
	if (ft_strncmp(line_segment[0], "S", 1) == 0)
		return (TRUE);
	if (ft_strncmp(line_segment[0], "C", 1) == 0)
		return (TRUE);
	if (ft_strncmp(line_segment[0], "F", 1) == 0)
		return (TRUE);
	return (FALSE);
}

int		is_map_line(char *line)
{
	char	map_entity[6];

	ft_strlcpy(map_entity, "012N ", 5);
	if (*line == 0)
		return (FALSE);
	while (*line)
	{
		if (ft_strchr(map_entity, *line) == 0)
			return (FALSE);
	}
	return (TRUE);
}

void	init_resolution(char **line_segment, t_point *resolution)
{
	int	x;
	int	y;
	ft_printf("loading resolution\n");
	if (!line_segment[1])
		exit_print("Missing factor: screen resolution x");
	if (!line_segment[2])
		exit_print("Missing factor: screen resolution y");
	x = ft_atoi(line_segment[1]);
	y = ft_atoi(line_segment[2]);
	if (x == 0 || y == 0)
		exit_print("Wrong factor: Given screen size is 0");
	*resolution = make_point(x, y);
}

void	init_color(char **line_segment, int *color)
{
	ft_printf("loading %s\n", line_segment[0]);
	line_segment = line_segment + 0;
}

void	init_path(char **line_segment, char *path)
{
	int	len;

	ft_printf("loading %s\n", line_segment[0]);
	len = ft_strlcpy(path, line_segment[1], 500);
	if (len == 0)
		exit_print("Missing factor: path_empty");
}

void	parse_info_line(char **line_segment, t_info_data *info_data)
{
	if (ft_strncmp(line_segment[0], "R", 1) == 0)
		init_resolution(line_segment, &(info_data->resolution));
	else if (ft_strncmp(line_segment[0], "NO", 2) == 0)
		init_path(line_segment, info_data->north_texture);
	else if (ft_strncmp(line_segment[0], "SO", 2) == 0)
		init_path(line_segment, info_data->south_texture);
	else if (ft_strncmp(line_segment[0], "EA", 2) == 0)
		init_path(line_segment, info_data->east_texture);
	else if (ft_strncmp(line_segment[0], "WE", 2) == 0)
		init_path(line_segment, info_data->west_texture);
	else if (ft_strncmp(line_segment[0], "S", 1) == 0)
		init_path(line_segment, info_data->sprite_texture);
	else if (ft_strncmp(line_segment[0], "F", 1) == 0)
		init_color(line_segment, &(info_data->floor_color));
	else if (ft_strncmp(line_segment[0], "C", 1) == 0)
		init_color(line_segment, &(info_data->ceilling_color));
}

void	parse_map_line(char *line, t_list *map_data)
{
	t_list	*this_line;

	ft_printf("setting map");
	this_line = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(&map_data, this_line);
}


void	set_map(t_list **map)
{
	ft_putstr_fd("set_map\n", 1);
}

int		init(char *path, t_info_data *info_data, t_list *map_data)
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
		else
			ft_printf("blank\n");
		free(line);
		i = 0;
		while (line_segment[i])
			free(line_segment[i++]);
		free(line_segment);
	}
	if (check_err < 0)
		exit_print("loading failed while reading .cub file");
	set_map(&map_data);
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	t_list		map_data;
	t_info_data	info_data;

	ft_memset(&info_data, 0, sizeof(t_info_data));
	ft_memset(&info_data, 0, sizeof(t_info_data));
	init(argv[1], &info_data, &map_data);
}
