CC 			 = cc

FLAGS 		 =	-Wall -Wextra -Werror

LDLIBS		 =  -lmlx -lXext -lX11 -lft

LIB			 = 	 libft/libft.a

MLX			 =   minilibx-linux/libmlx.a

LIB_PATH     =  -L minilibx-linux/ -L libft/

INCLUDEPATH  =	./

SRCPATH 	 =	./

SRCBONUSPATH = so_long_bonus/

ifdef BONUS
	INCLUDE_OPTION = -I$(SRCBONUSPATH)
	HEADER		   = $(SRCBONUSPATH)so_long_bonus.h
else
	INCLUDE_OPTION = -I$(SRCPATH)
	HEADER		   = so_long.h
endif

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
					$(SRCBONUSPATH)itoa.c		\

NAME 		=	so_long

OBJ 		=	$(SRC:.c=.o)

OBJBONUS	=	$(SRCBONUS:.c=.o)

NAME_BONUS	=	so_long_b

$(NAME): $(MLX) $(LIB) $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LDLIBS) $(INCLUDE_OPTION) -o $(NAME)

$(NAME_BONUS): $(MLX) $(LIB) $(HEADER) $(OBJBONUS) 
	$(CC) $(FLAGS) $(OBJBONUS) $(LIB_PATH) $(LDLIBS) $(INCLUDE_OPTION) -o $(NAME_BONUS)

bonus:
	$(MAKE) BONUS=1 $(NAME_BONUS)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE_OPTION)

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
