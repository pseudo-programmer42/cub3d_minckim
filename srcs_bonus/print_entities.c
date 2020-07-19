/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 01:10:58 by minckim           #+#    #+#             */
/*   Updated: 2020/07/18 19:52:51 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_list	*entity_to_list(t_gamedata *g_data)
{
	t_list	*head;
	int		i;
	int		j;

	head = 0;
	i = -1;
	while (++i < g_data->size_x)
	{
		j = -1;
		while (++j < g_data->size_y)
			ft_lstadd_front(&head, ft_lstnew(&g_data->entity[i][j]));
	}
	return (head);
}

t_list	*item_to_list(t_gamedata *g_data)
{
	t_list	*head;
	int		i;

	head = 0;
	i = -1;
	while (++i < g_data->n_item)
	{
		ft_lstadd_front(&head, ft_lstnew(&g_data->item[i]));
	}
	return (head);
}

void	print_entity_list(t_screen *s, t_list **lst_ent, int (*f)())
{
	t_list	*curr;
	t_list	*prev;

	curr = *lst_ent;
	prev = 0;
	while (curr)
	{
		if (f(s, curr->content) && prev)
		{
			prev->next = curr->next;
			ft_lstadd_front(lst_ent, curr);
			curr = prev->next;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

void	print_entities(t_gamedata *g_data)
{
	static t_list	*lst_ent;
	static t_list	*lst_item;

	if (!lst_ent)
		lst_ent = entity_to_list(g_data);
	if (!lst_item)
		lst_item = item_to_list(g_data);
	print_entity_list(&g_data->screen, &lst_ent, screen_entity);
	print_entity_list(&g_data->screen, &lst_item, screen_item);
}
