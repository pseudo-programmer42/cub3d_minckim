/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 18:00:21 by minckim           #+#    #+#             */
/*   Updated: 2020/05/09 17:39:21 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*file_new(int fd)
{
	t_file	*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (0);
	file->fd = fd;
	file->next = 0;
	file->line = 0;
	file->read_chars = 0;
	file->cursor = 0;
	file->status = GNL_OK;
	return (file);
}

void	line_clear(t_line *head)
{
	t_line	*curr;
	t_line	*next;

	if (!head)
		return ;
	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	file_del(t_head *head, int fd)
{
	t_file *curr;
	t_file *prev;

	prev = 0;
	curr = (t_file*)head;
	while (curr->fd != fd)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	line_clear(curr->line);
	curr->line = 0;
	free(curr);
}

t_file	*file_find(t_head *head, int fd)
{
	t_file	*curr;
	t_file	*prev;

	curr = (t_file*)head;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		prev = curr;
		curr = curr->next;
	}
	if (!(prev->next = file_new(fd)))
	{
		return (0);
	}
	return (prev->next);
}

int		get_next_line(int fd, char **line)
{
	static t_head	head;
	t_file			*file;

	head.blank = -1;
	if (fd < 0 || !(file = file_find(&head, fd)) || BUFFER_SIZE <= 0)
	{
		*line = 0;
		return (GNL_ERR);
	}
	if (read_line(file) == GNL_ERR)
	{
		*line = 0;
		file_del(&head, fd);
		return (GNL_ERR);
	}
	*line = merge(file->line);
	if (file->status == GNL_EOF)
	{
		file_del(&head, fd);
		return (GNL_EOF);
	}
	line_clear(file->line);
	return (file->status);
}
