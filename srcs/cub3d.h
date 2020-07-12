#include "../screen/screen.h"
# include "../libft/libft.h"
# define TEXTURE_SPECIFIER "EA NO WE SO F C S R"
# define N_TEXTURE 8
# define TYPE_FLOOR 0
# define TYPE_WALL 1
# define TYPE_SPRITE 2
# define TEXTURE_EAST 0
# define TEXTURE_NORTH 1
# define TEXTURE_WEST 2
# define TEXTURE_SOUTH 3
# define TEXTURE_FLOOR 4
# define TEXTURE_CEILLING 5
# define TEXTURE_SPRITE 6
# define RESOLUTION 7
# define BONUS 0
# define CEILLING_HEIGHT 4000
# define WALL_WIDTH 3000
# define EYE_LEVEL 1700
# define CUB_CAM_ANGLE M_PI_2
# define ANGLE_UNIT M_PI / 180 * 3
# define MOVE_WALK 300
# define MOVE_RUN 1000
# include "key.h"

typedef struct	s_player{
	t_vec		origin;
	t_real		h;
	t_real		v;
	int			run;
}				t_player;

typedef struct	s_gamedata{
	int			n_entity;
	int			n_item;
	int			size_x;
	int			size_y;
	t_bitmap	*texture[N_TEXTURE];
	int			color[2];
	t_entity	floor;
	t_entity	wall;
	t_entity	sprite;
	t_entity	non;
	t_entity	**entity;
	t_entity	item[10];
	t_player	player;
	t_screen	screen;
}				t_gamedata;

/*
**	===========================================================================
**	init.c
**	===========================================================================
*/

void	init_game_data(char *path, t_gamedata *g_data);
int		parse_info(t_gamedata *g_data, char *line);
/*
**	===========================================================================
**	init_pars_line.c
**	===========================================================================
*/
void	parse_map(char *line, t_list **map);
int		parse_info(t_gamedata *g_data, char *line);
/*
**	===========================================================================
**	init_check_map.c
**	===========================================================================
*/
int		check_map(char **map, t_gamedata *g_data);
/*
**	===========================================================================
**	init_util.c
**	===========================================================================
*/
void	exit_message(char *err_massage, char *arg);
void	split_del(char **words);
int		lst_content_size(t_list *lst);
char	**lst_to_arr(t_list *lst);
/*
**	===========================================================================
**	init_util.c
**	===========================================================================
*/

void	init_entity(t_gamedata *g_data, char **map_arr);


void	print_entities(t_gamedata *g_data);