CC 			    = cc

FLAGS 		    = -Wall -Wextra -Werror -MMD -MP -g3

INCLUDEPATH     = ./include/

SRCPATH 	    = ./src/

SRC_CLIENT_NAME = client.c 		\
				  utils.c	 		

SRC_SERVER_NAME = server.c		\
				  utils.c

SRC_CLIENT	    = $(addprefix $(SRCPATH), $(SRC_CLIENT_NAME))

SRC_SERVER      = $(addprefix $(SRCPATH), $(SRC_SERVER_NAME))

NAME_CLIENT     = client

NAME_SERVER     = server

OBJ_CLIENT 	    = $(SRC_CLIENT:.c=.o)

OBJ_SERVER      = $(SRC_SERVER:.c=.o)

DEP		        = $(patsubst %.o,%.d, $(OBJ_CLIENT) $(OBJ_SERVER))

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT)  : $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER)  : $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

%.o: %.c 
	$(CC) $(FLAGS) -I$(INCLUDEPATH) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(DEP)
	
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	
re : fclean all

.PHONY: clean fclean all re bonus

-include $(DEP)
