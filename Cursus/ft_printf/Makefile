CC			=	cc

CCL			=	ar rc

FLAGS 		=	-Wall -Wextra -Werror

SRCPATH 	=	./

SRCS 		=	$(SRCPATH)ft_printf.c		\
				$(SRCPATH)fonctions1.c		\
				$(SRCPATH)fonctions2.c		\

INCLUDEPATH =	./

OBJ 		=	$(SRCS:.c=.o)

NAME 		=	libftprintf.a

$(NAME): $(OBJ)
	$(CCL) $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -c $< -I $(INCLUDEPATH) -o ${<:.c=.o}

clean:
	rm -f $(OBJ) $(OBJBONUS)
	
fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re