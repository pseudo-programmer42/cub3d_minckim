/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:52:32 by minckim           #+#    #+#             */
/*   Updated: 2020/04/06 17:54:00 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*nxt;

	if (!*lst || !del)
		return ;
	cur = *lst;
	while (cur)
	{
		nxt = cur->next;
		ft_lstdelone(cur, del);
		cur = nxt;
	}
	*lst = 0;
}
