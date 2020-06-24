#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#define TRUE 1
#define FALSE 0

typedef struct	s_point{
	int			x;
	int			y;
}				t_point;

typedef struct	s_info_data{
	int			floor_color;
	int			ceilling_color;
	t_point		resolution;
	char		north_texture[500];
	char		south_texture[500];
	char		east_texture[500];
	char		west_texture[500];
	char		sprite_texture[500];
}				t_info_data;