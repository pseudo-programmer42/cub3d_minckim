/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:54:52 by minckim           #+#    #+#             */
/*   Updated: 2020/07/22 18:06:48 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		refresh(t_gamedata *g_data)
{
	clock_t		frame_start;
	t_screen	*s;
	t_player	*p;

	frame_start = clock();
	p = &(g_data->player);
	s = &(g_data->screen);
	s->origin = p->origin;
	s->origin.z = p->crouch ? EYE_LEVEL / 2 : s->origin.z + EYE_LEVEL;
	s->h = p->h;
	s->v = p->v;
	player_jump(p);
	refresh_screen(s);
	s->odd = s->odd ? 0 : 1;
	print_entities(g_data);
	screen_hud(s, g_data);
	dead(p, s);
	print_fps(frame_start, s);
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	return (1);
}

int		print_key(int key)
{
	ft_printf("pressed : %3d\n", key);
	return (0);
}

int		cub_close(t_gamedata *g_data, long long *keys)
{
	if (!is_pressed(KEY_ESC, keys))
		return (0);
	(void)g_data;
	ft_printf("bye\n");
	exit(0);
}

int		play_game(t_gamedata *g_data)
{
	t_screen	*s;
	t_player	*p;

	s = &(g_data->screen);
	p = &(g_data->player);
	player_turn(p, g_data->keys);
	if (p->life)
	{
		player_move(g_data, g_data->keys);
		player_catch_jump(p, g_data->keys);
		player_catch_crouch(p, g_data->keys);
		item_interaction(g_data, s, toxic_apple);
		item_interaction(g_data, s, healing_42);
		player_opendoor(g_data);
	}
	cub_close(g_data, g_data->keys);
	refresh(g_data);
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
	refresh(&g_data);
	save_screenshot(argc, argv, s);
	mlx_hook(s->win, 2, 1, key_press_manager, g_data.keys);
	mlx_hook(s->win, 3, 2, key_release_manager, g_data.keys);
	mlx_loop_hook(s->mlx, play_game, &g_data);
	mlx_hook(s->win, 6, 1L << 2, mouse_motion, &g_data);
	mlx_hook(s->win, 17, 1L << 5, cub_close, &g_data);
	mlx_loop(s->mlx);
}
