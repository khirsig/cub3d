CC = gcc

NAME = cub3D

LIBPATH = ./libs/libft/libft.a
MLXPATH = ./libs/mlx/libmlx.a

CFLAGS = -Wall -Werror -Wextra
LFLAGS = $(MLXPATH) -framework OpenGL -framework AppKit $(LIBPATH)

OBJECTS = *.o

SRC =	main.c	parse_map.c

all: $(NAME)

$(NAME): $(OBJECTS)
	@make --directory=./libs/libft
	@make --directory=./libs/mlx
	$(CC) $(SRC) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJECTS):
	$(CC) -c $(CFLAGS) $(SRC)

clean:
	@make clean --directory=./libs/libft
	@make clean --directory=./libs/mlx
	rm -f $(OBJECTS)

fclean: clean
	@make fclean --directory=./libs/libft
	rm -f $(NAME)

re: fclean $(NAME)
	make re --directory=./libft
