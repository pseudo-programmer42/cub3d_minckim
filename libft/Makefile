CC = gcc
CFLAG = -Wall -Wextra -Werror -g

LIBFT	=\
ft_memset.c		ft_bzero.c		ft_memcpy.c\
ft_memccpy.c	ft_memmove.c	ft_memchr.c\
ft_memcmp.c		ft_strlen.c		ft_strlcpy.c\
ft_strlcat.c	ft_strchr.c		ft_strrchr.c\
ft_strnstr.c	ft_strncmp.c	ft_atoi.c\
ft_isalpha.c	ft_isdigit.c	ft_isalnum.c\
ft_isascii.c	ft_isprint.c	ft_toupper.c\
ft_tolower.c	ft_calloc.c		ft_strdup.c\
\
ft_substr.c		ft_strjoin.c	ft_strtrim.c\
ft_split.c		ft_itoa.c		ft_strmapi.c\
ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c\
ft_putnbr_fd.c\
\
ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

GNL_DIR = ./get_next_line/
GNL_SRC =\
get_next_line.c get_next_line_utils.c
GNL = $(addprefix $(GNL_DIR),$(GNL_SRC))

PRINTF_DIR = ./ft_printf/
PRINTF_SRC =\
ft_printf.c		ft_printf_util_1.c\
convert_int.c	convert_float1.c	convert_float2.c\
get_option.c	print_d.c			print_u.c\
print_x.c		print_p.c			print_c.c\
print_s.c		print_f.c			print_e.c\
print_g.c		print_n.c
PRINTF = $(addprefix $(PRINTF_DIR),$(PRINTF_SRC))

LIBFT_OBJ = $(LIBFT:.c=.o)
GNL_OBJ = $(GNL:.c=.o)
PRINTF_OBJ = $(PRINTF:.c=.o)
OBJ = $(LIBFT_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ):%.o : %.c
	$(CC) $(CFLAG) -c -o $@ $*.c

re : fclean all

clean :
	$(RM) *.o
	$(RM) $(GNL_DIR)*.o
	$(RM) $(PRINTF_DIR)*.o

fclean : clean
	$(RM) $(NAME)

.PHONY: all bonus clean fclean re