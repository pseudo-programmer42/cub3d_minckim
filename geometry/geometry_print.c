#include "geometry.h"
#include "../libft/libft.h"

void	face_print(t_face *f)
{
	if (f->type == TRIANGLE)
		ft_printf("%10s", "Triangle\n");
	else if (f->type == RECTANGLE)
		ft_printf("%10s", "Rectangle\n");
	vec_print(&(f->a));
	vec_print(&(f->b));
	vec_print(&(f->c));
}