/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 22:02:25 by root              #+#    #+#             */
/*   Updated: 2020/06/27 22:31:50 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_info_line(char **line_segment)
{
	if (!(*line_segment))
		return (FALSE);
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

void	parse_resolution(char **line_segment, int *resolution, \
		int *checklist, int c)
{
	ft_printf("parsing resolution value...\n");
	if (!line_segment[1])
		exit_message("Missing factor: screen resolution x");
	if (!line_segment[2])
		exit_message("Missing factor: screen resolution y");
	resolution[0] = ft_atoi(line_segment[1]);
	resolution[1] = ft_atoi(line_segment[2]);
	if (resolution[0] == 0 || resolution[1] == 0)
		exit_message("Wrong factor: Given screen size is 0");
	*checklist += c;
}

void	parse_color(char **line_segment, int *color, int *checklist, int c)
{
	char	**color_a;
	int		i;

	ft_printf("parsing color %s...\n", line_segment[0]);
	if (!line_segment[1])
		exit_message("Missing factor: screen resolution x");
	color_a = ft_split(line_segment[1], ',');
	*color = 0;
	i = -1;
	while (++i < 3)
		*color += (ft_atoi(color_a[i])) << (i * 8);
	*checklist += c;
}

void	parse_path(char **line_segment, char *path, int *checklist, int c)
{
	int	len;

	ft_printf("parsing %s...\n", line_segment[0]);
	len = ft_strlcpy(path, line_segment[1], 500);
	if (len == 0)
		exit_message("Missing factor: path");
	*checklist += c;
}

void	parse_info_line(char **line_segment, t_info_data *info_data)
{
	int	*checklist;

	checklist = &(info_data->checklist);
	if (ft_strncmp(line_segment[0], "R", 1) == 0)
		parse_resolution(line_segment, info_data->resolution, checklist, 1);
	else if (ft_strncmp(line_segment[0], "NO", 2) == 0)
		parse_path(line_segment, info_data->north_texture, checklist, 2);
	else if (ft_strncmp(line_segment[0], "SO", 2) == 0)
		parse_path(line_segment, info_data->south_texture, checklist, 4);
	else if (ft_strncmp(line_segment[0], "EA", 2) == 0)
		parse_path(line_segment, info_data->east_texture, checklist, 8);
	else if (ft_strncmp(line_segment[0], "WE", 2) == 0)
		parse_path(line_segment, info_data->west_texture, checklist, 16);
	else if (ft_strncmp(line_segment[0], "S", 1) == 0)
		parse_path(line_segment, info_data->sprite_texture, checklist, 32);
	else if (ft_strncmp(line_segment[0], "F", 1) == 0)
		parse_color(line_segment, &(info_data->floor_color), checklist, 64);
	else if (ft_strncmp(line_segment[0], "C", 1) == 0)
		parse_color(line_segment, &(info_data->ceilling_color), checklist, \
		128);
}
