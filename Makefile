NAME = cub3d

SRC = cub.c main.c keyevent.c utils/utils.c parsing/parse.c parsing/parse2.c parsing/parse3.c parsing/parse4.c parsing/parse5.c parsing/parse6.c utils/utils2.c utils/utils3.c utils/utils4.c utils/utils5.c utils/utlils6.c events.c read.c move_dowun.c

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
MLX = mlx/libmlx.a

OBJ = $(SRC:.c=.o)

CC = gcc -g3 -O3 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft ft_printf/libftprintf.a  -o cub3d


$(LIBFT):
	@make bonus -C ./libft

$(PRINTF):
	@make -C ./ft_printf

$(MLX): 
	@make -C ./mlx
	cp $(MLX) .

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

 re: fclean all