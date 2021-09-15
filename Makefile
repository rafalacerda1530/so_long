PATH_SRC = ./src/
PATH_GAME = ./src/game/
PATH_MAP = ./src/map/
PATH_GNL = ./src/utils/gnl/
PATH_MINILBX = ./src/utils/minilbx/
PATH_OBJS = ./objs/

MLX = $(PATH_MINILBX)libmlx.a
NAME = so_long

FILES = $(PATH_MAP)check_map.c $(PATH_MAP)map_utils.c \
		$(PATH_SRC)utils.c $(PATH_SRC)so_long.c\
		$(PATH_SRC)utils_score.c $(PATH_GAME)init_game.c \
		$(PATH_GAME)move.c $(PATH_GAME)print_map.c \
		$(PATH_GNL)get_next_line.c $(PATH_GNL)get_next_line_utils.c \


OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = -Wextra -Werror -Wall
MLXFLAGS = -I $(PATH_MINILBX) -L $(PATH_MINILBX) -lmlx -Ilmlx -lXext -lX11
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo done!!
	@make -C $(PATH_MINILBX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) -o so_long
	@echo program done!

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)map
	@mkdir -p $(PATH_OBJS)utils/gnl
	@mkdir -p $(PATH_OBJS)game
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(PATH_OBJS)
	@echo obj removed!

fclean: clean
	make clean -C $(PATH_MINILBX)
	$(RM) $(NAME)
	@echo clean everything

re: fclean all

.PHONY: re all fclean clean

test:	
	$(CC) -fsanitize=leak $(MLXFLAGS) $(CFLAGS) $(PATH_SRC)so_long.c $(FILES) ./minilibx/libmlx.a -o so_long
