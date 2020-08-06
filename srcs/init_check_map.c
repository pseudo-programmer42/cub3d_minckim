/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:39:12 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 16:18:27 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_row(char **map)
{
	char	*tmp;

	while (*map)
	{
		tmp = *map;
		while (*tmp && *tmp == ' ')
			tmp++;
		while (*tmp)
		{
			if (*(tmp) != '1')
			{
				return (0);
			}
			while (*tmp && *tmp != ' ')
				tmp++;
			if (*(tmp - 1) != '1')
				return (0);
			while (*tmp && *tmp == ' ')
				tmp++;
		}
		map++;
	}
	return (1);
}

void	size_map(char **map, int *i, int *j)
{
	char	**tmp_i;
	char	*tmp_j;

	*i = 0;
	*j = 0;
	tmp_i = map;
	tmp_j = *map;
	while (*tmp_j++)
		(*j)++;
	while (*tmp_i++)
		(*i)++;
}

int		check_col(char **map, int mx_i, int mx_j)
{
	int		i;
	int		j;

	j = 0;
	while (j < mx_j)
	{
		i = 0;
		while (i < mx_i && map[i][j] == ' ')
			i++;
		while (i < mx_i)
		{
			if (map[i++][j] != '1')
				return (0);
			while (i < mx_i && map[i][j] != ' ')
				i++;
			if (map[i - 1][j] != '1')
				return (0);
			while (i < mx_i && map[i][j] == ' ')
				i++;
		}
		j++;
	}
	return (1);
}

int		check_map(char **map, t_gamedata *g_data)
{
	size_map(map, &g_data->size_x, &g_data->size_y);
	if (check_row(map) && check_col(map, g_data->size_x, g_data->size_y))
		return (1);
	else
		return (0);
}
