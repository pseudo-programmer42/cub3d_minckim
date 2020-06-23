#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

int		init_data(char *file, t_game_data *data)
{
	collect_data(file, data);
	map_init(file, data);
}













	int		fd;

	fd = open(file, RD_ONLY);












// void	print_error(char *s)
// {
// 	printf("%s\n", s);
// }

// t_point	make_point(int x, int y)
// {
// 	t_point	result;

// 	result.x = x;
// 	result.y = y;
// 	return (result);
// }

// void	data_collector(char *line, t_game_data *data)
// {
// 	char	**words;
// 	int		i;

// 	i = 0;
// 	words = ft_split(line, ' ');
// 	if (ft_strncmp(words[0], "R", 1) == 0)
// 		data->resolution = make_point(ft_atoi(words[1]), words[2]);
// 	else if (ft_strncmp(words[0], "NO", 2) == 0)
// 		data->north_texture = ft_strcpy(words[1]);
// 	else if (ft_strncmp(words[0], "SO", 2) == 0)
// 		data->south_texture = ft_strcpy(words[1]);
// 	else if (ft_strncmp(words[0], "WO", 2) == 0)
// 		data->west_texture = ft_strcpy(words[1]);
// 	else if (ft_strncmp(words[0], "EO", 2) == 0)
// 		data->east_texture = ft_strcpy(words[1]);
// 	else if (ft_strncmp(words[0], "S", 1) == 0)
// 		data->sprite_texture = ft_strcpy(words[1]);
// 	else if (ft_strncmp(words[0], "F", 1) == 0)
// 		data->floor_color = ft_atoi(words[1]);
// 	else if (ft_strncmp(words[0], "C", 1) == 0)
// 		data->ceilling_color = ft_atoi(words[1]);
// 	while (words[i])
// 		free(words[i++]);
// 	free(words);
// }

// t_map	*init_map(char *file)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(file, RD_ONLY);
// 	while (get_next_line(fd, &line))
// 	while (ft_strchr(" 012N", line[0]))
// }


// int		init(char *file, t_game_data *data)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	fd = open(file, RD_ONLY);
// 	while (get_next_line(fd, &line))
// 	{
// 		data_collector(line, data);
// 		free(line);
// 	}
// 	if (data->resoultion * data->north_texture * data->south_texture * \
// 	data->west_texture * data->east_texture * data->sprite_texture * \
// 	data->floor_color * data->ceilling_color == 0)
// 		print_error("wrong_data");
// 	while (get_next_line(fd, &line) && ft_strlen(line) == 0)
// 		free(line);
// 	close(fd);
// 	data->map = map_init(file);
// }