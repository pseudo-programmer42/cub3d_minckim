NAME = libgnl.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS	= get_next_line.c get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

LIBFT_DIR = ../
LIBFT = $(LIBFT_DIR)libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	ar r $(LIBFT) $(OBJS)

$(OBJS):%.o : %.c
	$(CC) $(CFLAG) -c -o $@ $*.c

re : fclean all

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

.PHONY: all bonus clean fclean re