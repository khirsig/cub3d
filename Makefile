CC = gcc

NAME = cub3D

LIBPATH = ./libs/libft/libft.a
MLXPATH = ./libs/mlx/libmlx.a

CFLAGS = -Wall -Werror -Wextra
LFLAGS = $(MLXPATH) -framework OpenGL -framework AppKit $(LIBPATH)

OBJDIR = ./objs/
OBJECTS = $(OBJDIR)/*.o

SRC =	src/main.c							\
		src/parse_map/error_map.c			\
		src/parse_map/parse_map.c			\
		src/parse_map/map_length.c			\
		src/player/movement.c				\
		src/player/init_player.c			\
		src/player/display_vitals.c			\
		src/player/mod_vitals.c				\
		src/enemy/casting.c					\
		src/enemy/sprite_init.c				\
		src/enemy/count_enemy.c				\
		src/enemy/enemy_move.c				\
		src/minimap/minimap.c				\
		src/loop/loop.c						\
		src/keyhook/keyhook_handler.c		\
		src/keyhook/destroy.c				\
		src/parse_color/parse_color.c		\
		src/parse_color/parse_texture.c		\
		src/draw_image/draw_image.c			\

all: $(NAME)

$(NAME): $(OBJECTS)
	@make --directory=./libs/libft
	@make --directory=./libs/mlx
	$(CC) $(OBJECTS) $(CFLAGS) $(LFLAGS) -o $(NAME) $(LIBPATH)

$(OBJECTS): $(SRC)
	$(CC) -c $(CFLAGS) $(SRC)
	@rm -rf ./objs; mkdir ./objs
	@mv *.o $(OBJDIR)

clean:
	@make clean --directory=./libs/libft
	@make clean --directory=./libs/mlx
	rm -f $(OBJECTS)
	rm -rf ./objs

fclean: clean
	@make fclean --directory=./libs/libft
	rm -f $(NAME)

re: fclean $(NAME)
	make re --directory=./libs/libft
