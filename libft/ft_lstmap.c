/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:52:54 by minckim           #+#    #+#             */
/*   Updated: 2020/05/05 19:45:23 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;

	if (!lst || !f)
		return (0);
	head = ft_lstnew(f(lst->content));
	if (!head)
	{
		return (0);
	}
	curr = head;
	lst = lst->next;
	while (lst)
	{
		curr->next = ft_lstnew(f(lst->content));
		if (!curr->next)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (head);
}
