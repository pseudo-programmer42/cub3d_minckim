/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_interaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:08:56 by minckim           #+#    #+#             */
/*   Updated: 2020/07/22 19:29:12 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	del_lst_item(t_list *prev, t_list *curr, t_list **head)
{
	if (prev)
		prev->next = curr->next;
	else
		*head = curr->next;
	free(curr);
}

int		healing_42(t_gamedata *g, t_screen *s, t_entity *item)
{
	t_player *p;

	p = &g->player;
	if (item->type != TYPE_SPRITE_42
	|| vec_distance2(&item->origin, &p->origin) > WALL_WIDTH * WALL_WIDTH / 4)
		return (0);
	p->life = p->life + 20 > 100 ? 100 : p->life + 20;
	screen_rgb(s, 100, 1);
	return (1);
}

int		toxic_apple(t_gamedata *g, t_screen *s, t_entity *item)
{
	t_player *p;

	p = &g->player;
	if (item->type == TYPE_SPRITE_AP \
	&& vec_distance2(&item->origin, &p->origin) < WALL_WIDTH * WALL_WIDTH / 4)
	{
		p->life = p->life - 20 < 0 ? 0 : p->life - 20;
		screen_rgb(s, 100, 2);
		return (1);
	}
	return (0);
}

void	item_interaction(t_gamedata *g, t_screen *s, int (*f)())
{
	t_entity	*tmp;
	t_list		*curr;
	t_list		*prev;

	prev = 0;
	curr = g->lst_item;
	while (curr)
	{
		if (f(g, s, curr->content))
		{
			del_lst_item(prev, curr, &g->lst_item);
		}
		tmp = curr->content;
		prev = curr;
		curr = curr->next;
	}
}
