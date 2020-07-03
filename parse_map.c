#include "cub3d.h"

int		is_map_line(char *line)
{
	static char	*map_entity = "012N";

	if (*line == 0)
		return (FALSE);
	while (*line)
	{
		if (ft_strchr(map_entity, *line++) == 0)
			return (FALSE);
	}
	return (TRUE);
}

void	parse_map_line(char *line, t_list **map_data)
{
	t_list	*this_line;

	this_line = ft_lstnew(ft_strdup(line));
	ft_lstadd_front(map_data, this_line);
}