CC 			 = cc

FLAGS 		 =	-Wall -Wextra -Werror -MMD -MP -g3

LIB_PATH     =  -L libft/

LDLIBS		 =  -lft

LIB			 = 	 libft/libft.a

INCLUDEPATH  =	./include/

SRCPATH 	 =	./src/

SRCNAME 	 =	main.c 			 		\
			    utils.c 		 		\
				display_error.c  		\
				cleaning.c		 		\
				parsing.c		 		\
				check_char.c 	 		\
				split.c 		 		\
				ft_list.c		 		\
				ft_list2.c				\
				instructions.c   		\
				instructions2.c  		\
				print_instructions.c	\
				print_instructions2.c 	\
				sort.c					\
				sort2.c					\
				sort3.c					\
				sort4.c   									

SRC			 = $(addprefix $(SRCPATH), $(SRCNAME))

NAME 		=	push_swap

OBJ 		=	$(SRC:.c=.o)

DEP		    = 	$(patsubst %.o,%.d, $(OBJ) $(OBJBONUS)) $(patsubst %.a,%.d, $(LIB))

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) -Ilibft/ $(LDLIBS) -o $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) -I$(INCLUDEPATH) -Ilibft/ -c $< -o $@

libft/libft.a:
	$(MAKE) -C libft 

all: $(NAME)

clean:
	rm -f $(OBJ) $(DEP)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re : fclean all

.PHONY: clean fclean all re bonus

-include $(DEP)