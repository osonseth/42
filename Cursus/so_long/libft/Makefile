CC			=	cc

ARRC			=	ar rc

FLAGS 		 =	-Wall -Wextra -Werror -MMD -MP -g3

SRCPATH 	=	./

INCLUDEPATH =	./

SRCS 		=	$(SRCPATH)ft_printf.c				\
				$(SRCPATH)bonus1.c					\
				$(SRCPATH)get_next_line.c			\
				$(SRCPATH)get_next_line_utils.c		\
				$(SRCPATH)mandatory1.c				\
				$(SRCPATH)mandatory2.c				\
				
OBJ 		=	$(SRCS:.c=.o)

DEP		=   $(patsubst %.o,%.d, $(OBJ))

NAME 		=	libft.a

$(NAME): $(OBJ)
	$(ARRC) $(NAME) $(OBJ)

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ) $(OBJBONUS) $(DEP)
	
fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re

-include $(DEP)