CC 			 = cc

FLAGS 		 =	-Wall -Wextra -Werror

LDLIBS		 =  -lmlx -lXext -lX11 -lft

LIB			 = 	 libft/libft.a

MLX			 =   minilibx-linux/libmlx.a

LIB_PATH     =  -L minilibx-linux/ -L libft/

INCLUDEPATH  =	./

SRCPATH 	 =	./

SRCBONUSPATH = so_long_bonus/

SRC 		 =		$(SRCPATH)cleaning1.c	\
					$(SRCPATH)cleaning2.c	\
					$(SRCPATH)main.c		\
					$(SRCPATH)mlx1.c		\
					$(SRCPATH)mlx2.c		\
					$(SRCPATH)parsing1.c	\
					$(SRCPATH)parsing2.c	\
					$(SRCPATH)parsing3.c	\
					$(SRCPATH)parsing4.c	\
					$(SRCPATH)split.c		\

SRCBONUS     =		$(SRCBONUSPATH)cleaning1_bonus.c	\
				  	$(SRCBONUSPATH)cleaning2_bonus.c	\
					$(SRCBONUSPATH)main_bonus.c			\
					$(SRCBONUSPATH)mlx1_bonus.c			\
					$(SRCBONUSPATH)mlx2_bonus.c			\
					$(SRCBONUSPATH)mlx3_bonus.c			\
					$(SRCBONUSPATH)mlx4_bonus.c			\
					$(SRCBONUSPATH)mlx5_bonus.c			\
					$(SRCBONUSPATH)mlx6_bonus.c			\
					$(SRCBONUSPATH)parsing1_bonus.c		\
					$(SRCBONUSPATH)parsing2_bonus.c		\
					$(SRCBONUSPATH)parsing3_bonus.c		\
					$(SRCBONUSPATH)parsing4_bonus.c		\
					$(SRCBONUSPATH)split_bonus.c		\

NAME 		=	so_long

OBJ 		=	$(SRC:.c=.o)

OBJBONUS	=	$(SRCBONUS:.c=.o)

NAME_BONUS	=	so_long_b

$(NAME): $(MLX) $(LIB) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LDLIBS) -o $(NAME)

$(NAME_BONUS): $(MLX) $(LIB) $(OBJBONUS)
	$(CC) $(FLAGS) $(OBJBONUS) $(LIB_PATH) $(LDLIBS) -o $(NAME_BONUS)

bonus: $(NAME_BONUS)

.c.o:
	$(CC) $(FLAGS) -c $< -I $(INCLUDEPATH) -o ${<:.c=.o}

minilibx-linux/libmlx.a:
	$(MAKE) -C minilibx-linux

libft/libft.a:
	$(MAKE) -C libft

all: $(NAME)

clean:
	rm -f $(OBJ) $(OBJBONUS)
	$(MAKE) -C libft clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean


re : fclean all

.PHONY: clean fclean all re bonus