#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


void	print_entities(t_gamedata *g_data)
{
	int	i;
	int	j;
	t_screen	*s;
	t_entity	*e;

	s = &g_data->screen;
	i = -1;
	while (++i < g_data->size_x)
	{
		e = g_data->entity[i];
		j = -1;
		while (++j < g_data->size_y)
		{
			screen_entity(s, e + j);
		}
	}
}

void	player_turn(t_player *player, int key)
{
	if (key == KEY_LF)
		player->h += ANGLE_UNIT;
	else if (key == KEY_RT)
		player->h -= ANGLE_UNIT;
	else if (key == KEY_UP)
		player->v += ANGLE_UNIT;
	else if (key == KEY_DN)
		player->v -= ANGLE_UNIT;
}

void	player_move(t_player *player, int key)
{
	t_vec	m;

	m = vec_new(MOVE_UNIT, 0, 0);
	if (key == KEY_A)
		vec_rot(&m, player->h + M_PI / 2, 0);
	else if (key == KEY_D)
		vec_rot(&m, player->h - M_PI / 2, 0);
	else if (key == KEY_W)
		vec_rot(&m, player->h, 0);
	else if (key == KEY_S)
		vec_rot(&m, player->h + M_PI, 0);
	// vec_print(&m);
	vec_add(&(player->origin), &m);
}

void	player_fly(t_player *player, int key)
{
	if (key == KEY_X)
		player->origin.z += MOVE_UNIT;
	else if (key == KEY_SPC)
		player->origin.z -= MOVE_UNIT;
}


int		cub_key_hook(int key, t_gamedata *g_data)
{
	t_screen	*s;
	t_player	*p;

	s = &(g_data->screen);
	p = &(g_data->player);
	if (key == KEY_LF || key == KEY_RT || key == KEY_UP || key == KEY_DN)
		player_turn(&(g_data->player), key);
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
		player_move(&(g_data->player), key);
	if (key == KEY_X || key == KEY_SPC)
		player_fly(&g_data->player, key);
	if (key == KEY_ESC)
		exit(1);
	s->origin = p->origin;
	s->h = p->h;
	s->v = p->v;
	refresh_screen(s);
	print_entities(g_data);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0,0);
	// print_key(key);
	return (1);
}

int		print_key(int key)
{
	printf("pressed : %3d\n", key);
	return 0;
}

int		main(int argc, char **argv)
{
	t_gamedata	g_data;
	t_screen	*s;

	ft_memset(&g_data, 0, sizeof(g_data));
	init_game_data(argv[1], &g_data);

	s = &g_data.screen;
	// t_face	*f;

	// f = (g_data.wall.face);
	// f->img = 0;
	// screen_face(s, f);
	mlx_hook(s->win, 2, 1, cub_key_hook, &g_data);
	// mlx_key_hook(s->win, cub_key_hook, &g_data);
	mlx_loop(s->mlx);


	// double	x;
	// int		a;

	// x = (21474836470L);
	// printf("%d\n", (int)x);
}