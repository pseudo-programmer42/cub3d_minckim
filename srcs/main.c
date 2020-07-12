#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

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
	i = -1;
	e = g_data->item;
	while (++i < g_data->n_item)
	{
		screen_item(s, e + i);
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

void	player_move(t_player *player, int key, int run)
{
	t_vec	m;
	int 	speed;

	speed = run ? MOVE_RUN : MOVE_WALK;
	m = vec_new(speed, 0, 0);
	if (key == KEY_A)
		vec_rot(&m, player->h + M_PI / 2, 0);
	else if (key == KEY_D)
		vec_rot(&m, player->h - M_PI / 2, 0);
	else if (key == KEY_W)
		vec_rot(&m, player->h, 0);
	else if (key == KEY_S)
		vec_rot(&m, player->h + M_PI, 0);
	vec_add(&(player->origin), &m);
}

void	player_fly(t_player *player, int key)
{
	if (key == KEY_X)
		player->origin.z += MOVE_RUN;
	else if (key == KEY_SPC)
		player->origin.z -= MOVE_RUN;
}

int		refresh(t_gamedata *g_data)
{
	clock_t		t0;
	clock_t		t1;
	t_screen	*s;
	t_player	*p;

	p = &(g_data->player);
	s = &(g_data->screen);
	s->origin = p->origin;
	s->origin.z += EYE_LEVEL;
	s->h = p->h;
	s->v = p->v;
	t0 = clock();
	refresh_screen(s);
	print_entities(g_data);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0,0);
	t1 = clock();
	// ft_printf("frame: %10.3f\n", (CLOCKS_PER_SEC / ((double)(t1 - t0))));
	char	*s1 = ft_itoa((int)(1000 * CLOCKS_PER_SEC / ((double)(t1 - t0))));
	mlx_string_put(s->mlx, s->win, 10, 10, 0x00FFFF00, s1);
	free(s1);
	return (1);
}

int		print_key(int key)
{
	printf("pressed : %3d\n", key);
	return 0;
}

int		cub_close(int key, t_gamedata *g_data)
{
	key = 0;
	g_data++;
	ft_printf("bye\n");
	exit(1);
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
		player_move(&(g_data->player), key, g_data->player.run);
	if (key == KEY_X || key == KEY_SPC)
		player_fly(&g_data->player, key);
	if (key == KEY_ESC)
		cub_close(key, g_data);
	if (key == KEY_SHF)
		p->run = p->run == 1 ? 0 : 1;
	// refresh(g_data);
	usleep((double)100);
	// print_key(key);
	return (1);
}




void	check_arg(int argc, char **argv)
{
	if (argc == 1)
		exit_message("Map data empty%s", "");
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4))
		exit_message("Wrong extention.%s", "");
	// if (argc == 3)
	// {
	// 	if (ft_strncmp(argv[2], "--save", ft_strlen("--save")))
	// 	exit_message("wrong input%s", "");
	// }
	if (argc > 3)
		exit_message("Too many input%s", "");
}

void	save_screenshot(int argc, char **argv, t_screen *s)
{
	if (argc != 3 || ft_strncmp(argv[2], "--save", 6))
		return ;
		(void)s;

}

int		main(int argc, char **argv)
{
	t_gamedata	g_data;
	t_screen	*s;

	check_arg(argc, argv);
	ft_memset(&g_data, 0, sizeof(g_data));
	init_game_data(argv[1], &g_data);
	s = &g_data.screen;
	refresh(&g_data);
	save_screenshot(argc, argv, s);
	mlx_loop_hook(s->mlx, refresh, &g_data);
	mlx_hook(s->win, 2, 1, cub_key_hook, &g_data);
	mlx_hook(s->win, 17, 1L<<5, cub_close, &g_data);
	// print_bitmap_arr(g_data.sprite.face[0].img);
	// mlx_key_hook(s->win, cub_key_hook, &g_data);
	// mlx_do_sync(s->mlx);
	mlx_loop(s->mlx);


}






// int		main(int argc, char **argv)
// {
// 	t_gamedata	g_data;
// 	init_game_data(argv[1], &g_data);
// 	t_screen	*s;

// 	s = &g_data.screen;

// 	clock_t t1 = clock();
// 	for (int k = 0 ; k < 60 ; k++)
// 	{

// 		t_mat	m = mat_rot(0.12, 0.15);
// 		for (int i = 0 ; i < s->rx ; i++)
// 		{
// 			for (int j = 0 ; j < s->ry ; j++)
// 			{
// 				mat_vec(&m, &(s->pixel[i][j].ray));
// 			}
// 		}
// 	}
// 	clock_t t2 = clock();

// 	printf("time: %10.3f\n", (double)(t2 - t1)/CLOCKS_PER_SEC);
// }