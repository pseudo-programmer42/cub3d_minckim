#include "cub3d.h"

t_vector	vector_new(double *coord)
{
	t_vector	result;
	int			i;

	i = -1;
	while (++i < 3)
		result.p[i] = coord[i];
	return (result);
}


t_vector	vector_add(t_vector *a, t_vector *b)
{
	t_vector	result;
	int			i;

	i = -1;
	while (++i < 3)
		result.p[i] = a->p[i] + b->p[i];
}

t_matrix