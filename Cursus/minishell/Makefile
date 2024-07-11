CC 			  =  cc

FLAGS 		  =	-Wall -Wextra -Werror -MMD -MP  -g 

#-fsanitize=address

LDLIBS		  = -lft -lreadline

LIB			  =  libft/libft.a

LIB_PATH      = -L libft/

LIBFT_INCLUDE = -Ilibft/

INCLUDEPATH   =	./include/

SRCPATH 	  =	./src/

OBJDIR 		  = ./obj/

DEPDIR 		  = ./dep/

SRC_NAME 	  =	main.c					\
				utils.c					\
				print_test.c			\
				clean.c					\
				error.c					\
				build_cmd_table.c		\
				parsing.c				\
				quote.c					\
				token_node.c			\
				check_syntax.c			\
				create_token.c 			\
				variable_node.c			\
				calculate_expand.c 		\
				expand_utils.c			\
				expand.c				\
				remove_quotes.c
				

					
SRC	    	  = $(addprefix $(SRCPATH), $(SRC_NAME))

NAME 		  =	 minishell

OBJ 		  =	$(SRC:.c=.o)

DEP		      = $(patsubst %.o,%.d, $(OBJ))

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIBFT_INCLUDE) $(LDLIBS) -o $(NAME)
	mv $(OBJ) $(OBJDIR)
	mv $(DEP) $(DEPDIR)
	
%.o: %.c 
	$(CC) $(FLAGS) -I$(INCLUDEPATH) $(LIBFT_INCLUDE) -c $< -o $@
 
libft/libft.a:
	$(MAKE) -C libft

all: $(NAME)
	
clean:
	@rm -f $(DEPDIR)*.d $(OBJDIR)*.o
	@rm -f $(OBJ) $(DEP)
	@$(MAKE) -C libft clean
	
fclean: clean
	rm -f $(NAME) 
	@$(MAKE) -C libft fclean

re : fclean all

-include $(DEP)

.PHONY: clean fclean all re bonus