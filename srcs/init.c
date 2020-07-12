/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:57:26 by minckim           #+#    #+#             */
/*   Updated: 2020/07/13 04:19:17 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_init_data(t_gamedata *g_data)
{
	char	**words;
	int	i;

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

void	init_player(t_gamedata *g_data)
{
	g_data->player.run = 0;
}


void	init_game_data(char *path, t_gamedata *g_data)
{
	char	*line;
	int		eof;
	int		fd;
	t_list	*map;
	char	**map_arr;

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
	check_init_data(g_data);
	map_arr = lst_to_arr(map);
	if (check_map(map_arr, g_data) == 0)
		exit_message("%s", "Map must be closed.");
	init_entity(g_data, map_arr);
	init_player(g_data);
}
