CC			=	cc

ARRC			=	ar rc

FLAGS 		=	-Wall -Wextra -Werror

SRCPATH 	=	./

INCLUDEPATH =	./

SRCS 		=	$(SRCPATH)ft_printf.c				\
				$(SRCPATH)bonus1.c					\
				$(SRCPATH)get_next_line.c			\
				$(SRCPATH)get_next_line_utils.c		\
				$(SRCPATH)mandatory1.c				\
				$(SRCPATH)mandatory2.c				\
				$(SRCPATH)itoa.c					\
								
OBJ 		=	$(SRCS:.c=.o)

NAME 		=	libft.a

$(NAME): $(OBJ)
	$(ARRC) $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -c $< -I $(INCLUDEPATH) -o ${<:.c=.o}

clean:
	rm -f $(OBJ) $(OBJBONUS)
	
fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re