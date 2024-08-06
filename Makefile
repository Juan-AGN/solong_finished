
FLAGS = -Wall -Wextra -Werror -g -I MLX42/include/MLX42

FLAGS_LINK = -ldl -lglfw -pthread -lm

NAME = so_long

FILES = src/main.c src/mapper.c src/map_tester.c src/gameplay.c src/screen.c src/move.c src/free_mem.c

OBJ = $(FILES:%.c=%.o)

MLX = MLX42/build/libmlx42.a

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(MAKE) -C libft
	cc $(FLAGS) $(FLAGS_LINK) $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

$(OBJ): %.o:%.c
	clang -c $(FLAGS) $^ -o $@

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	cmake -S MLX42 -B MLX42/build
	cmake --build MLX42/build -j4

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
	rm -f $(OBJ)
	$(MAKE) re -C libft

.PHONY: clean
.PHONY: fclean
.PHONY: re
.PHONY: all
