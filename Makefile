NAME = cub3d

FILES =	main.c cub.c keyevent.c utils/utils.c parsing/parse.c\
		parsing/parse2.c parsing/parse3.c parsing/parse4.c parsing/parse5.c\
		parsing/parse6.c utils/utils2.c utils/utils3.c utils/utils4.c utils/utils5.c\
		utils/utlils6.c events.c read.c move_dowun.c\
		raycast1.c raycast2.c

HEADERS = ./cub3d.h\
		  ./libft/libft.h\

ARCS = ./libft/libft.a

OBJ = $(FILES:.c=.o)

#------------------------------------------------------------------------------
OPENGL_PATH = ./mlx/

MLX = $(OPENGL_PATH)libmlx.a -framework OpenGL

APPKIT = -framework AppKit

#------------------------------------------------------------------------------
MLX_FLAGS = $(MLX) $(APPKIT)

FLAGS = -g -Wall -Wextra -Werror -fsanitize=address

sanitize = -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

CC = gcc

all: $(NAME) clean
$(NAME): $(OBJ)
	@make -C ./mlx
	@make -C ./libft
	@$(CC) $(FILES) $(FLAGS) $(MLX_FLAGS) -Ofast -O3 $(ARCS) -o cub3d

clean:
	@rm -rf $(OBJ)
	@make -C ./libft clean


fclean: clean
	@make -C ./mlx clean
	@make -C ./libft fclean
	@rm -rf cub3d


re: fclean all
