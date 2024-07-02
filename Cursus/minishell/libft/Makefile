CC			=	cc

ARRC			=	ar rc

FLAGS 		 =	-Wall -Wextra -Werror -MMD -MP -g3

SRCPATH 	=	./

INCLUDEPATH =	./

SRCS 		=	$(SRCPATH)ft_isalpha.c		\
				$(SRCPATH)ft_isdigit.c		\
				$(SRCPATH)ft_isalnum.c		\
				$(SRCPATH)ft_strdup.c		\
				$(SRCPATH)ft_strlen.c			
								
OBJ 		=	$(SRCS:.c=.o)

DEP		=   $(patsubst %.o,%.d, $(OBJ))

NAME 		=	libft.a

$(NAME): $(OBJ)
	$(ARRC) $(NAME) $(OBJ)

%.o: %.c 
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ) $(DEP)
	
fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

-include $(DEP)

.PHONY: clean fclean all re