CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -rf

SRC_MD	=	ft_printf.c		ft_printf_util_1.c\
			convert_int.c	convert_float1.c	convert_float2.c\
			get_option.c	print_d.c			print_u.c\
			print_x.c		print_p.c			print_c.c\
			print_s.c		print_f.c			print_e.c\
			print_g.c		print_n.c

OBJ_MD	= $(SRC_MD:.c=.o)

LIBFT_DIR = ../
LIBFT = $(LIBFT_DIR)libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_MD)
	ar r $(LIBFT) $(OBJ_MD)

libft : $(LIBFT)

$(LIBFT) :
	make -C $(LIBFT_DIR)

bonus : libft $(OBJ_MD)
	cp -r $(LIBFT) ./$(NAME)
	ar r $(NAME) $(OBJ_MD)

$(OBJ_MD):%.o : %.c
	$(CC) $(CFLAG) -c -o $@ $*.c

re : fclean all

clean :
	$(RM) *.o
	make clean -C $(LIBFT_DIR)

fclean :
	make fclean -C $(LIBFT_DIR)
	$(RM) *.o
	$(RM) $(NAME)
