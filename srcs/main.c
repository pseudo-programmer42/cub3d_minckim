/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:54:52 by minckim           #+#    #+#             */
/*   Updated: 2020/07/16 13:13:14 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		refresh(t_gamedata *g_data)
{
	clock_t		frame_start;
	t_screen	*s;
	t_player	*p;
	static int	odd;

	p = &(g_data->player);
	s = &(g_data->screen);
	s->origin = p->origin;
	s->origin.z += EYE_LEVEL;
	s->h = p->h;
	s->v = p->v;
	frame_start = clock();
	refresh_screen(s);
	odd = odd ? 0 : 1;
	print_entities(g_data, odd);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	print_fps(frame_start, s);
	return (1);
}

int		print_key(int key)
{
	ft_printf("pressed : %3d\n", key);
	return (0);
}

int		cub_close(t_gamedata *g_data, int key)
{
	if (key != KEY_ESC)
		return (0);
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
	player_turn(p, key);
	player_move(p, key, g_data->player.run);
	player_fly(p, key);
	cub_close(g_data, key);
	if (key == KEY_SHF)
		p->run = p->run == 1 ? 0 : 1;
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
	mlx_hook(s->win, 2, 1, cub_key_hook, &g_data);
	mlx_hook(s->win, 17, 1L << 5, cub_close, &g_data);
	mlx_loop(s->mlx);
}
