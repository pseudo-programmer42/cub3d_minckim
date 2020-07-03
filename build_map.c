#include "cub3d.h"
#define TYPE_WALL 234
#define TYPE_FLOOR 23254
#define TYPE_CELLING 23124
#define TYPE_SPRITE 2634

void		vector_print(double *v)
{
	printf("%13.3f %13.3f %13.3f\n", v[0], v[1], v[2]);
}

void		face_print_coord(t_face *face)
{
	double	*p;

	p = face->p;
	printf("%10.3f %10.3f %10.3f |", p[0], p[1], p[2]);
	printf("%10.3f %10.3f %10.3f |", p[3], p[4], p[5]);
	printf("%10.3f %10.3f %10.3f |", p[6], p[7], p[8]);
	printf("%15p %8x\n", face->img, face->color);
}

void		object_print_coord(t_object *object)
{
	t_list	*lst_face;

	lst_face = object->lst_face;
	while (lst_face)
	{
		face_print_coord(lst_face->content);
		lst_face = lst_face->next;
	}
	printf("------------------------------------------\n");
}

void		init_object_origin(t_object **object, t_runtime_data *runtime_data)
{
	// t_object	*pobject[5];

	object[0] = floor_ceilling_new(runtime_data, CELL_SIZE, WALL_HEIGHT);
	object[1] = wall_new(runtime_data, CELL_SIZE, WALL_HEIGHT);
	object[2] = sprite_new(runtime_data, CELL_SIZE, EYE_LEVEL);

	printf("[%p]\n", object[1]);
	object_print_coord(object[1]);
	// face_print_coord((object[1]->lst_face->content));
	// printf("%f");
}

void		init_all_object(t_object **o, t_runtime_data *r_data, char **map)
{
	double		dir[3];
	int			i;
	int			j;
	t_list		*curr;
	t_list		head;

	curr = &head;
	head.next = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			vector_new(j * CELL_SIZE, i * CELL_SIZE, 0, dir);
			if ('0' <= map[i][j] && map[i][j] <= '2')
			{
				// printf("[%2d %2d]", i, j);
				// printf("[%d%d]",o[(map[i][j] - '0')]->type, map[i][j]-'0');
				// curr->next = ft_lstnew(object_copy(o[0], dir));
				// curr->next = ft_lstnew(object_copy(o[map[i][j] - '0'], dir));
				curr = curr->next;
				// object_print_coord(curr->content);
			}
			else if (ft_strchr("NEWS", map[i][j] - '0'))
				vector_copy(dir, r_data->player_coord);
			j++;
		}
		// printf("\n");
		i++;
	}
	r_data->lst_object = head.next;
}

char		**map_lst_to_char(t_list *lst_map)
{
	char	**map;
	char	**map_cursor;

	map = (char**)malloc(sizeof(char) * (ft_lstsize(lst_map) + 1));
	map_cursor = map;
	while (lst_map)
	{
		*map_cursor++ = lst_map->content;
		lst_map = lst_map->next;
	}
	*map_cursor = 0;
	return map;
}




void		build_map(t_list *lst_map, t_runtime_data *runtime_data)
{
	t_object	*object[5];
	// double		dir[3];
	char		**map;

	init_object_origin(object, runtime_data);
	printf("<%p>\n",object[1]);
	object_print_coord(object[1]);
	map = map_lst_to_char(lst_map);
	init_all_object(object, runtime_data, map);
	// print_image_info(runtime_data->sprite_texture, 0);
	// object_print_coord(object[0]);
	t_list		*lst_o;
	t_list		*lst_f;
	t_object	*tmp_o;
	t_face		*tmp_f;
	double		*p;

	lst_o = runtime_data->lst_object;
	while (lst_o)
	{
		tmp_o = lst_o->content;
		lst_f = tmp_o->lst_face;
		tmp_f = lst_f->content;
		object_print_coord(lst_o->content);
		lst_o = lst_o->next;
	}

}