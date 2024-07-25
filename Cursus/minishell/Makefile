CC 			  =  cc

FLAGS 		  =	-Wall -Wextra -Werror -MMD -MP  -g 

DEBUG_FLAG	  = 	-fsanitize=address

LDLIBS		  = -lft -lreadline

LIB			  =  libft/libft.a

LIB_PATH      = -L libft/

LIBFT_INCLUDE = -Ilibft/

INCLUDEPATH   =	./include/

SRCPATH 	  =	./src/

OBJDIR 		  = ./obj/

DEPDIR 		  = ./dep/

SRC_NAME 	  =	main.c						\
				env.c						\
				utils.c						\
				print_test.c				\
				clean.c						\
				clean_utils.c 				\
				error.c						\
				build_cmd_table.c			\
				cmd_table_utils.c 			\
				parsing.c					\
				quote.c						\
				token_node.c				\
				syntax_pipe_and_quote.c		\
				syntax_redirections.c		\
				create_token.c 				\
				create_args.c 				\
				variable_node.c				\
				calculate_expand.c 			\
				expand_utils.c				\
				expand.c					\
				remove_quotes.c				\
				redirections_token.c		\
				redirections_tokenization.c \
				redirection_list.c			\
				redirection_node.c			\
				redirections_utils.c 		
				
OBJ_NAME 	 =	$(SRC:.c=.o)
					
SRC	    	  = $(addprefix $(SRCPATH), $(SRC_NAME))
OBJ	    	  = $(addprefix $(OBJDIR), $(OBJ_NAME))

NAME 		  =	 minishell


DEP		      = $(patsubst %.o,%.d, $(OBJ))

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIBFT_INCLUDE) $(LDLIBS) -o $(NAME)
$(OBJDIR)%.o: %.c 
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -I$(INCLUDEPATH) $(LIBFT_INCLUDE) -c $< -o $@
 
libft/libft.a:
	$(MAKE) -C libft

all: $(NAME)

debug: $(OBJ) $(LIB) 
	$(CC) $(DEBUG_FLAG) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIBFT_INCLUDE) $(LDLIBS) -o $(NAME)
clean:
	@rm -rf $(OBJDIR) $(DEP)
	@$(MAKE) -C libft clean
	
fclean: clean
	rm -f $(NAME) 
	@$(MAKE) -C libft fclean

re : fclean all

-include $(DEP)

.PHONY: clean fclean all re bonus debug
