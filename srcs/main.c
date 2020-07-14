/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:54:52 by minckim           #+#    #+#             */
/*   Updated: 2020/07/15 05:57:09 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int		refresh(t_gamedata *g_data)
{
	clock_t		t0;
	clock_t		t1;
	t_screen	*s;
	t_player	*p;
	char		*s1;

	p = &(g_data->player);
	s = &(g_data->screen);
	s->origin = p->origin;
	s->origin.z += EYE_LEVEL;
	s->h = p->h;
	s->v = p->v;
	t0 = clock();
	refresh_screen(s);
	print_entities(g_data);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	t1 = clock();
	s1 = ft_itoa((int)(1000 * CLOCKS_PER_SEC / ((double)(t1 - t0))));
	mlx_string_put(s->mlx, s->win, 10, 10, 0x00FFFF00, s1);
	free(s1);
	return (1);
}

int		print_key(int key)
{
	printf("pressed : %3d\n", key);
	return (0);
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
	usleep((double)100);
	return (1);
}

int		main(int argc, char **argv)
{
	t_gamedata	g_data;
	t_screen	*s;

	ft_memset(&g_data, 0, sizeof(g_data));
	init_game_data(argv[1], &g_data);
	s = &g_data.screen;
	refresh(&g_data);
	save_screenshot(argc, argv, s);
	mlx_loop_hook(s->mlx, refresh, &g_data);
	mlx_hook(s->win, 2, 1, cub_key_hook, &g_data);
	mlx_hook(s->win, 17, 1L << 5, cub_close, &g_data);
	mlx_loop(s->mlx);
}