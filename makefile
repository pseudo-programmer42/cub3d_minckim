#output
NAME = cub3d

# compile option
CC = gcc
FLAG = -Wall -Wextra -Werror
# NFLAG =

#library
LIBFT_DIR = ./libft/
LIBFT = libft.a

LIBGNL_DIR = $(LIBFT_DIR)get_next_line/
LIBGNL = libgnl.a

LIBFTPRINTF_DIR = $(LIBFT_DIR)ft_printf/
LIBFTPRINTF = libftprintf.a

#source files
SRCS = main.c

OBJS = $(SRCS:.c=.o)

#rules

all : $(NAME)

$(NAME) : $(OBJS) library
	$(CC) $(FLAG) -o $(NAME) $(OBJS) \
	-lm -L. -lft -lgnl -lftprintf-I./includes -I./usr/include -lmlx \
	-framework OpenGL -framework AppKit

$(OBJS):%.o : %.c
	$(CC) $(FLAG) -c $*.c -o $@

lib : library

library : $(LIBFT)

$(LIBFT) :
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .

clean :
	rm -rf $(OBJS) $(LIBFT) $(MMS) $(OPENGL)
	make clean -C $(LIBFT_DIR)


fclean :
	rm -rf $(OBJS) $(LIBFT) $(MMS) $(OPENGL) $(NAME)
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