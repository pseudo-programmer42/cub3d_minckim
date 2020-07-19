/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:57:26 by minckim           #+#    #+#             */
/*   Updated: 2020/07/18 15:50:24 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_init_data(t_gamedata *g_data)
{
	char	**words;
	int		i;

	words = ft_split(TEXTURE_SPECIFIER, ' ');
	i = -1;
	while (++i < N_TEXTURE)
		if ((g_data->texture)[i] == 0)
		{
			if (!BONUS)
			{
				if ((i == TEXTURE_FLOOR || i == TEXTURE_CEILLING))
					continue ;
			}
			else
				exit_message("Texture loading failed: %s", words[i]);
		}
	split_del(words);
	return (1);
}

void	check_arg_err(int argc, char **argv)
{
	int		len;

	if (argc == 1)
		exit_message("Map data empty%s", "");
	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".cub", 4))
		exit_message("Wrong extention.%s", "");
	if (argc == 3 && ft_strncmp("--save", argv[2], 6))
		exit_message("Second input must be \"--save\"%s", "");
	if (argc > 3)
		exit_message("Too many input%s", "");
}

void	init_game_data(char *path, t_gamedata *g_data)
{
	char	*line;
	int		eof;
	int		fd;
	t_list	*map;
	char	**map_arr;

	map = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		exit_message("%s", "Wrong path");
	while (1)
	{
		if ((eof = get_next_line(fd, &line)) < 0)
			exit_message("%s", "Loading failed");
		if (parse_info(g_data, line) == 2)
			parse_map(line, &map);
		free(line);
		if (eof == 0)
			break ;
	}
	close(fd);
	check_init_data(g_data);
	map_arr = lst_to_arr(map);
	if (check_map(map_arr, g_data) == 0)
		exit_message("%s", "Map must be closed.");
	init_entity(g_data, map_arr);
}
