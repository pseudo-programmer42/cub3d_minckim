# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 16:58:52 by minckim           #+#    #+#              #
#    Updated: 2020/07/14 05:54:23 by minckim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#output
NAME = cub3d

# compile option
CC = gcc
FLAG = -Wall -Wextra -Werror -O3
# FLAG = -Wall -Wextra -Werror -O3 -g
# FLAG = -O3 -g
# FLAG = -O3

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

BITMAP_DIR = ./bitmap/
BITMAP_NAME = \
	bitmap.c

SCREEN_DIR = ./screen/
SCREEN_NAME = \
	init_screen.c\
	screen_entity.c\
	screen_face.c\
	screen_face_util.c\
	save_screenshot.c

LINEAR_DIR = ./linear_algebra/
LINEAR_NAME = \
	vec0.c\
	vec1.c\
	vec2.c\
	mat0.c\
	mat1.c\
	mat2.c\
	linear_algebra_print.c

GEOMETRY_DIR = ./geometry/
GEOMETRY_NAME =\
	face.c\
	entity.c\
	geometry_print.c

SRCS_DIR = ./srcs/
SRCS_NAME =\
	main.c\
	init.c\
	init_parse_line.c\
	init_util.c\
	init_check_map.c\
	init_entity.c\
	init_create_entity.c\
	player_manage.c\
	print_entities.c

SRCS_BONUS_DIR = ./srcs_bonus/
SRCS_BONUS_NAME =\
	main.c\
	init.c\
	init_parse_line.c\
	init_util.c\
	init_check_map.c\
	init_create_entity.c\
	player_manage.c\
	print_entities.c

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_NAME))\
	$(addprefix $(SCREEN_DIR),$(SCREEN_NAME))\
	$(addprefix $(LINEAR_DIR),$(LINEAR_NAME))\
	$(addprefix $(BITMAP_DIR),$(BITMAP_NAME))\
	$(addprefix $(GEOMETRY_DIR),$(GEOMETRY_NAME))

SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR),$(SRCS_BONUS_NAME))\
	$(addprefix $(SCREEN_DIR),$(SCREEN_NAME))\
	$(addprefix $(LINEAR_DIR),$(LINEAR_NAME))\
	$(addprefix $(BITMAP_DIR),$(BITMAP_NAME))\
	$(addprefix $(GEOMETRY_DIR),$(GEOMETRY_NAME))

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#rules

all : $(NAME)

norm :
	norminette $(SRCS)

test : $(OBJS_TEST) library
	$(CC) $(FLAG) -o $(NAME) $(OBJS_TEST) \
	-lm -L. -lft -I./includes -I./usr/include -lmlx \
	-framework OpenGL -framework AppKit && ./$(NAME) map.cub


$(NAME) : $(OBJS) library
	$(CC) $(FLAG) -o $(NAME) $(OBJS) \
	-lm -L. -lft -I./includes -I./usr/include -lmlx -lpthread \
	-framework OpenGL -framework AppKit && ./$(NAME) map2.cub

bonus : $(OBJS_BONUS) library
	$(CC) $(FLAG) -o $(NAME) $(OBJS) \
	-lm -L. -lft -I./includes -I./usr/include -lmlx \
	-framework OpenGL -framework AppKit && ./$(NAME) map2.cub

linux: $(OBJS) library
	$(CC) $(FLAG) -o $(NAME) $(OBJS) \
	-lm -L. -lft \
	&& ./$(NAME) map.cub

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