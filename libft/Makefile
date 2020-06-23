CC = gcc
CFLAG = -Wall -Wextra -Werror

SRC_MD	=\
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
ft_putnbr_fd.c

SRC_BNS =\
ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

OBJ_MD	= $(SRC_MD:.c=.o)
OBJ_BNS	= $(SRC_BNS:.c=.o)
NAME = libft.a
BNS = bonus

all : $(NAME)

$(NAME) : $(OBJ_MD) $(OBJ_BNS)
	ar rc $(NAME) $(OBJ_MD) $(OBJ_BNS)

$(BNS) : $(OBJ_MD) $(OBJ_BNS)
	ar rc $(NAME) $(OBJ_MD) $(OBJ_BNS)

$(OBJ_MD):%.o : %.c
	$(CC) $(CFLAG) -c -o $@ $*.c

$(OBJ_BNS):%.o : %.c
	$(CC) $(CFLAG) -c -o $@ $*.c

re : fclean all

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

.PHONY: all bonus clean fclean re