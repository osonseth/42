CC			=	cc

CCL			=	ar rc

FLAGS 		=	-Wall -Wextra -Werror

SRCPATH 	=	./

SRCS 		=	$(SRCPATH)bonus1.c				\
				$(SRCPATH)ft_printf.c			\
				$(SRCPATH)get_next_line.c		\
				$(SRCPATH)get_next_line_utils.c	\
				$(SRCPATH)mandatory1.c			\
				$(SRCPATH)mandatory2.c			\
				$(SRCPATH)itoa.c				\
	


INCLUDEPATH =	./

OBJ 		=	$(SRCS:.c=.o)

OBJBONUS	=	$(SRCBONUS:.c=.o)

NAME 		=	libft.a

$(NAME): $(OBJ)
	$(CCL) $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -c $< -I $(INCLUDEPATH) -o ${<:.c=.o} -I ft_printf.h -I get_next_line.h

clean:
	rm -f $(OBJ) $(OBJBONUS)
	
fclean: clean
	rm -f $(NAME)

all: $(NAME)

bonus:	$(OBJ) $(OBJBONUS)
	$(CCL) $(NAME) $(OBJ) $(OBJBONUS)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(FLAGS) $(SRCS) $(SRCBONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJBONUS)

.PHONY: clean fclean all re