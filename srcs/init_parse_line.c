/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 23:50:17 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 17:38:34 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_color(char **words)
{
	char	**color_a;
	int		i;
	int		color;

	ft_printf("parsing color...");
	if (!words[1])
		exit_message("%s", "Missing factor: color info");
	color_a = ft_split(words[1], ',');
	if (!color_a[0])
		exit_message("%s", "Missing factor: color R");
	if (!color_a[1])
		exit_message("%s", "Missing factor: color G");
	if (!color_a[2])
		exit_message("%s", "Missing factor: color B");
	color = 0;
	i = -1;
	ft_printf("[%s]", color_a[0]);
	ft_printf("[%s]", color_a[1]);
	ft_printf("[%s]\n", color_a[2]);
	while (++i < 3)
		color += (ft_atoi(color_a[i])) << ((2 - i) * 8);
	i = -1;
	split_del(color_a);
	return (color);
}

void	parse_res(t_gamedata *g_data, char **words)
{
	int	rx;
	int	ry;

	ft_printf("parsing resolution...\n");
	if (!words[1])
		exit_message("%s", "Missing factor: screen res x");
	if (!words[2])
		exit_message("%s", "Missing factor: screen res y");
	rx = ft_atoi(words[1]);
	ry = ft_atoi(words[2]);
	g_data->screen = init_screen(rx, ry, CUB_CAM_ANGLE);
}

void	put_data(t_gamedata *g_data, char **words, int i, char **specifier)
{
	ft_printf("parsing info: %s...\n", specifier[i]);
	if ((i == TEXTURE_FLOOR || i == TEXTURE_CEILLING) && !BONUS)
		(g_data->color)[i - TEXTURE_FLOOR] = parse_color(words);
	else if (i == RESOLUTION)
		parse_res(g_data, words);
	else if (!((g_data->texture)[i] = bitmap_new(words[1])))
		exit_message("Wrong path: %s", specifier[i]);
}

int		parse_info(t_gamedata *g_data, char *line)
{
	char		**words;
	static char	**specifier;
	int			i;

	if (!(*line))
		return (0);
	if (!(specifier))
		specifier = ft_split(TEXTURE_SPECIFIER, ' ');
	words = ft_split(line, ' ');
	i = 0;
	while (specifier[i])
	{
		if (ft_strncmp(words[0], specifier[i], 10) == 0)
		{
			put_data(g_data, words, i, specifier);
			split_del(words);
			return (1);
		}
		i++;
	}
	split_del(words);
	return (2);
}

void	parse_map(char *line, t_list **map)
{
	char	*line_tmp;

	line_tmp = line;
	while (*line_tmp)
	{
		if (ft_strchr("012NEWS ", *line_tmp) == 0)
			exit_message("Wrong character(%.1s) in the map data.", line_tmp);
		line_tmp++;
	}
	ft_lstadd_back(map, ft_lstnew(ft_strdup(line)));
}
