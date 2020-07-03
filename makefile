# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 16:58:52 by minckim           #+#    #+#              #
#    Updated: 2020/07/02 04:59:49 by minckim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#output
NAME = cub3d

# compile option
CC = gcc
# FLAG = -Wall -Wextra -Werror
FLAG =

#library
LIBFT_DIR = ./libft/
LIBFT = libft.a

LIBGNL_DIR = $(LIBFT_DIR)get_next_line/
LIBGNL = libgnl.a

LIBFTPRINTF_DIR = $(LIBFT_DIR)ft_printf/
LIBFTPRINTF = libftprintf.a

#source files
SRCS_TEST = main_ex.c
OBJS_TEST = $(SRCS_TEST:.c=.o)


SRCS = \
		main.c				init.c			parse_info.c\
		parse_map.c			build_map.c		linear_algebra.c\
		image_convertor.c	object.c		face.c\

OBJS = $(SRCS:.c=.o)

#rules

all : $(NAME)

test : $(OBJS_TEST) library
	$(CC) $(FLAG) -o $(NAME) $(OBJS_TEST) \
	-lm -L. -lft -I./includes -I./usr/include -lmlx \
	-framework OpenGL -framework AppKit && ./$(NAME) map.cub


$(NAME) : $(OBJS) library
	$(CC) $(FLAG) -o $(NAME) $(OBJS) \
	-lm -L. -lft -I./includes -I./usr/include -lmlx \
	-framework OpenGL -framework AppKit && ./$(NAME) map.cub

$(OBJS):%.o : %.c
	$(CC) $(FLAG) -c $*.c -o $@

lib : library

library : $(LIBFT)

$(LIBFT) :
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .

clean :
	rm -rf $(OBJS) $(LIBFT)
	make clean -C $(LIBFT_DIR)


fclean :
	rm -rf $(OBJS) $(LIBFT) $(NAME)
	make clean -C $(LIBFT_DIR)


re : fclean $(NAME)


# MMS_DIR = ./minilibx_mms_20200219/
# MMS = libmlx.dylib

# OPENGL_DIR = ./minilibx_opengl_20191021/
# OPENGL = libmlx.a

# mms :
# 	make -C $(MMS_DIR)
# 	mv $(MMS_DIR)$(MMS) ./$(MMS)

# opengl :
# 	make -C $(OPENGL_DIR)
# 	mv $(OPENGL_DIR)$(OPENGL) ./$(OPENGL)

# clean :
# 	rm -rf $(OBJS) $(LIBFT) $(MMS) $(OPENGL)
# 	make clean -C $(LIBFT_DIR)
# 	make clean -C $(MMS_DIR)
# 	make clean -C $(OPENGL_DIR)

# fclean :
# 	rm -rf $(OBJS) $(LIBFT) $(MMS) $(OPENGL) $(NAME)
# 	make clean -C $(LIBFT_DIR)
# 	make clean -C $(MMS_DIR)
# 	make clean -C $(OPENGL_DIR)

# re : fclean $(NAME)