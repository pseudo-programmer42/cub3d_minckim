/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:49:13 by minckim           #+#    #+#             */
/*   Updated: 2020/07/19 10:47:18 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <pthread.h>
# include "../screen/screen.h"
# include "../libft/libft.h"
# include "key.h"
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
# define ANGLE_UNIT 0.05235987756
# define MOVE_WALK 300
# define MOVE_RUN 1000
# define JUMP_HEIGHT 1000
# define JUMP_DUL 1
# define TIME_SEGMENT 0.01

typedef struct	s_player{
	t_vec		origin;
	t_angle		h;
	t_angle		v;
	int			run;
	int			jump;
	int			crouch;
}				t_player;

typedef struct	s_gamedata{
	int			n_entity;
	int			n_item;
	int			size_x;
	int			size_y;
	t_bitmap	*texture[N_TEXTURE];
	int			color[2];
	long long	keys[6];
	t_entity	floor;
	t_entity	wall;
	t_entity	sprite;
	t_entity	non;
	t_entity	**entity;
	t_list		*lst_ent;
	t_list		*lst_item;
	t_entity	item[10];
	t_player	player;
	t_screen	screen;
}				t_gamedata;

/*
**	init.c---------------------------------------------------------------------
*/
void			check_arg_err(int argc, char **argv);
void			init_game_data(char *path, t_gamedata *g_data);

/*
**	init_check_map.c-----------------------------------------------------------
*/
int				check_map(char **map, t_gamedata *g_data);
/*
**	init_util.c----------------------------------------------------------------
*/
void			exit_message(char *err_massage, char *arg);
void			split_del(char **words);
int				lst_content_size(t_list *lst);
char			**lst_to_arr(t_list *lst);
/*
**	print_entities.c-----------------------------------------------------------
*/
void			print_entity_list(t_screen *s, t_list **lst_ent, int (*f)());
t_list			*entity_to_list(t_gamedata *g_data);
t_list			*item_to_list(t_gamedata *g_data);
void			print_entities(t_gamedata *g_data);
/*
**	mlx_put_fps.c--------------------------------------------------------------
*/
void			print_fps(clock_t fram_start, t_screen *s);
/*
**	init_create_entity.c-------------------------------------------------------
*/
t_entity		create_wall(t_bitmap **texture);
t_entity		create_floor_ceilling(t_bitmap **texture);
t_entity		create_sprite(t_bitmap **texture);
t_entity		create_non(void);
/*
**	init_entity.c--------------------------------------------------------------
*/
void			init_entity(t_gamedata *g_data, char **map_arr);
/*
**	init_pars_line.c-----------------------------------------------------------
*/
void			parse_map(char *line, t_list **map);
int				parse_info(t_gamedata *g_data, char *line);

/*
**	player_manage.c------------------------------------------------------------
*/
void			player_turn(t_player *player, long long *key);
void			player_move(t_gamedata *g_data, long long *key);
void			player_fly(t_player *player, long long *key);
/*
**	check_collision.c----------------------------------------------------------
*/
int				check_collision(t_gamedata *g_data, t_vec *m);
/*
**	jump.c---------------------------------------------------------------------
*/
void			player_jump(t_player *p);
void			player_catch_jump(t_player *p, long long *keys);
/*
**	crouch.c-------------------------------------------------------------------
*/
void			player_crouch(t_player *p);
void			player_catch_crouch(t_player *p, long long *keys);
/*
**	mouse_motion.c-------------------------------------------------------------
*/
int				mouse_motion(int a, int b, t_gamedata *g_data);
/*
**	key_manager.c--------------------------------------------------------------
*/
int				key_press_manager(int key, long long *keys);
int				key_release_manager(int key, long long *keys);
int				is_pressed(int key, long long *keys);
#endif
