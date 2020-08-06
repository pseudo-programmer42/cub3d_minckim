/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:00:06 by minckim           #+#    #+#             */
/*   Updated: 2020/08/01 17:41:02 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	exit_message(char *err_massage, char *arg)
{
	ft_printf("Error\n-");
	ft_printf(err_massage, arg);
	ft_printf("\n");
	exit(1);
}

void	split_del(char **words)
{
	char	**tmp;

	if (!words)
		return ;
	tmp = words;
	while (*tmp)
		free(*tmp++);
	free(words);
}

int		lst_content_size(t_list *lst)
{
	int	size;
	int	tmp;

	size = 0;
	while (lst)
	{
		tmp = ft_strlen(lst->content);
		size = size > tmp ? size : tmp;
		lst = lst->next;
	}
	return (size);
}

char	**lst_to_arr(t_list *lst)
{
	char	**arr;
	char	**arr_tmp;
	int		size_i;
	int		i;
	t_list	*tmp;

	tmp = lst;
	size_i = lst_content_size(lst);
	arr = (char**)malloc(sizeof(char*) * (ft_lstsize(lst) + 1));
	arr_tmp = arr;
	while (lst)
	{
		*arr_tmp = (char*)malloc(sizeof(char) * (size_i + 1));
		i = -1;
		while (++i < (int)ft_strlen(lst->content))
			(*arr_tmp)[i] = ((char*)(lst->content))[i];
		while (i < size_i)
			(*arr_tmp)[i++] = ' ';
		(*arr_tmp++)[size_i] = 0;
		lst = lst->next;
		ft_printf("%s\n", *(arr_tmp - 1));
	}
	*arr_tmp = 0;
	ft_lstclear(&tmp, free);
	return (arr);
}
