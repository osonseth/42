CC 			  =  cc

FLAGS 		  =	-Wall -Wextra -Werror -MMD -MP  -g

LDLIBS		  = -lft -lreadline

LIB			  =  libft/libft.a

LIB_PATH      = -L libft/

LIBFT_INCLUDE = -Ilibft/

INCLUDEPATH   =	./include/

SRCPATH 	  =	./src/

SRC_NAME 	  =	main.c				\
				utils.c				\
				print_test.c		\
				clean.c				\
				error.c				\
				cmd_table.c			\
				formate_cmd_table.c	\
				parsing.c			\
				expand.c			\
				quote.c				\
				token.c				\
				check_syntax.c
				

					
SRC	    	  = $(addprefix $(SRCPATH), $(SRC_NAME))

NAME 		  =	 minishell

OBJ 		  =	$(SRC:.c=.o)

DEP		      = $(patsubst %.o,%.d, $(OBJ))

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIBFT_INCLUDE) $(LDLIBS) -o $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) -I$(INCLUDEPATH) $(LIBFT_INCLUDE) -c $< -o $@ 

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

-include $(DEP)

.PHONY: clean fclean all re bonus