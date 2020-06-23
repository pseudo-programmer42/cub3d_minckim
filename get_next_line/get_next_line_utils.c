/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:17:19 by minckim           #+#    #+#             */
/*   Updated: 2020/05/09 17:39:21 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *dst, char *src, size_t size)
{
	if (!size)
	{
		*dst = 0;
		return (dst);
	}
	while (size--)
	{
		*dst++ = *src++;
	}
	*dst = 0;
	return (dst);
}

t_line	*gnl_dup(char *buffer, ssize_t start, ssize_t max)
{
	t_line	*line;
	char	*end;
	char	*line_cursor;
	size_t	len;

	if (!(line = malloc(sizeof(t_line))))
		return (0);
	line->next = 0;
	end = buffer + max;
	buffer += start;
	line_cursor = line->buffer;
	len = 0;
	while (buffer != end && *buffer != '\n')
	{
		*line_cursor++ = *buffer++;
		len++;
	}
	line->len = len;
	return (line);
}

int		read_buffer(t_file *file, t_line *curr)
{
	if (file->cursor == 0)
		if ((file->read_chars = read(file->fd, file->buffer, BUFFER_SIZE)) < 0)
			file->status = GNL_ERR;
	if (file->read_chars == 0)
	{
		file->status = GNL_EOF;
		curr->next = gnl_dup(file->buffer, 0, 0);
	}
	if (file->status == GNL_ERR || file->status == GNL_EOF)
		return (0);
	if (!(curr->next = gnl_dup(file->buffer, file->cursor, file->read_chars)))
	{
		file->status = GNL_ERR;
		return (0);
	}
	file->cursor += curr->next->len;
	if (file->buffer[file->cursor] == '\n' && file->cursor != file->read_chars)
	{
		file->cursor++;
		file->cursor = file->cursor == file->read_chars ? 0 : file->cursor;
		return (0);
	}
	file->cursor = file->cursor == file->read_chars ? 0 : file->cursor;
	return (1);
}

int		read_line(t_file *file)
{
	t_line	*curr;

	if (!(curr = (t_line*)malloc(sizeof(t_line))))
	{
		curr->next = 0;
		file->status = GNL_ERR;
		return (file->status);
	}
	file->line = curr;
	while (read_buffer(file, curr))
	{
		curr = curr->next;
	}
	return (file->status);
}

char	*merge(t_line *line)
{
	t_line	*curr;
	size_t	len;
	char	*result;
	char	*tmp;

	len = 0;
	curr = line->next;
	while (curr)
	{
		len += curr->len;
		curr = curr->next;
	}
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	tmp = result;
	curr = line->next;
	while (curr)
	{
		tmp = ft_strcat(tmp, curr->buffer, curr->len);
		curr = curr->next;
	}
	*tmp = 0;
	return (result);
}
