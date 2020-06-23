/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:01:29 by minckim           #+#    #+#             */
/*   Updated: 2020/06/22 19:46:33 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define GNL_ERR -1
# define GNL_EOF 0
# define GNL_OK 1
# define BUFFER_SIZE 1000

typedef struct		s_head{
	void			*next;
	ssize_t			blank;
}					t_head;
typedef struct		s_file{
	struct s_file	*next;
	int				fd;
	char			buffer[BUFFER_SIZE + 16];
	ssize_t			cursor;
	struct s_line	*line;
	ssize_t			read_chars;
	int				status;
}					t_file;
typedef struct		s_line{
	char			buffer[BUFFER_SIZE + 16];
	size_t			len;
	struct s_line	*next;
}					t_line;
int					get_next_line(int fd, char **line);
int					read_line(t_file *file);
char				*merge(t_line *line);
#endif
