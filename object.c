/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 01:07:30 by minckim           #+#    #+#             */
/*   Updated: 2020/07/02 05:33:06 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_object	*object_copy(t_object *object, double *dir)
{
	t_object	*result;
	t_list		*lst_face;

	if (!(result = (t_object*)malloc(sizeof(t_object))))
		return (0);
	// ft_memcpy(result, object, sizeof(t_object));
	lst_face = ft_lstmap(object->lst_face, *face_deepcopy, *face_del);
	// vector_print(dir);
	while (lst_face)
	{
		vector_add(((t_face*)(lst_face->content))->p, dir);
		vector_add(((t_face*)(lst_face->content))->p + 3, dir);
		vector_add(((t_face*)(lst_face->content))->p + 6, dir);
		lst_face = lst_face->next;
	}
	// result->instance_type = object->instance_type;
	return result;
}

t_object	*wall_new(t_runtime_data *runtime_data, int x, int z)
{
	t_object	*result;
	t_face		*face_dummy;
	t_face		*face;
	double		v[12];
	int			i;

	i = 0;
	vector_new(0, 0, 0, v);
	vector_new(0, x, 0, v + 3);
	vector_new(0, 0, z, v + 6);
	vector_new(x / 2, -x / 2, 0, v + 9);
	result = (t_object*)malloc(sizeof(t_object));
	result->instance_type = 1;
	face_dummy = face_new(runtime_data->wall_texture[0], 0, v + 3, v + 6);
	face_move(face_dummy, v + 9);
	while (i < 4)
	{
		face = face_copy(face_dummy, v);
		face_rot_h(face, v, i * 90);
		face->img = runtime_data->wall_texture[i];
		ft_lstadd_back(&result->lst_face, ft_lstnew(face));
		// face_print_coord(face);
		i++;
	}
	return (result);
}

t_object	*floor_ceilling_new(t_runtime_data *runtime_data, int x, int z)
{
	t_object	*result;
	t_face		*face[2];
	double		v[12];

	vector_new(x, 0, 0, v);
	vector_new(0, x, 0, v + 3);
	vector_new(-x / 2, -x / 2, 0, v + 6);
	vector_new(-x / 2, -x / 2, z, v + 9);
	result = (t_object*)malloc(sizeof(t_object));
	result->instance_type = 0;
	face[0] = face_new(0, runtime_data->floor_color, v, v + 3);
	face[1] = face_new(0, runtime_data->ceilling_color, v, v + 3);
	face_move(face[0], v + 6);
	face_move(face[1], v + 9);
	ft_lstadd_back(&result->lst_face, ft_lstnew(face[0]));
	ft_lstadd_back(&result->lst_face, ft_lstnew(face[1]));
	return (result);
}

t_object	*sprite_new(t_runtime_data *runtime_data, int x, int z)
{
	t_object	*result;
	t_face		*face;
	double		v[9];

	vector_new(0, x, 0, v);
	vector_new(0, 0, z, v + 3);
	vector_new(-x / 2, 0, 0, v + 6);
	result = (t_object*)malloc(sizeof(t_object));
	result->instance_type = 2;
	face = face_new(runtime_data->sprite_texture, 0, v, v + 3);
	face_move(face, v + 6);
	ft_lstadd_back(&result->lst_face, ft_lstnew(face));
	return (result);
}