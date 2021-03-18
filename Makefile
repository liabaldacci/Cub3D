NAME =		cub3D

SRC_DIR = 	srcs
MLX_DIR = 	mlx
OBJS_DIR =	objs

CC =		clang -g -fsanitize=address
FLAGS_CC =	-Wall -Wextra -Werror -g
FLAGS_MLX =	-lm -lbsd -lX11 -lXext -lmlx
					
MLX =		$(MLX_DIR)/libmlx.a
SRCS =		$(SRC_DIR)/main.c $(SRC_DIR)/close.c $(SRC_DIR)/ft_mlx_pixel_put.c \
				$(SRC_DIR)/ft_empty_circle.c $(SRC_DIR)/ft_square.c $(SRC_DIR)/ft_line.c \
				$(SRC_DIR)/ft_filled_circle.c $(SRC_DIR)/key_hook.c $(SRC_DIR)/ft_init.c

HEAD =		-I ./$(NAME).h -I ./$(MLX_DIR) -L ./$(MLX_DIR)

OBJS =		$(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS)) #subst in directory

RM =		/bin/rm -rf

all: $(NAME)

$(NAME): $(MLX) $(OBJS) #$@ means the output file will be ./cub3D instead of ./a.out
	$(CC) $(FLAGS_MLX) $(FLAGS_CC) $(OBJS) $(HEAD) $(MLX) -o $@

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(HEAD) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./cub3D

debug: $(MLX) $(OBJS)
	$(CC) -g $(FLAGS_MLX) $(FLAGS_CC) $(OBJS) $(HEAD) $(MLX) -o "cub3D_debug"

.PONY: all clean fclean re
