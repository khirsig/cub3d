/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:15:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/11 18:40:15 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	fill_game(t_data *data, t_game *game)
{
	int	w;
	int	h;

	h = 0;
	while(data->maze.map[h])
	{
		w = 0;
		while (data->maze.map[h][w])
		{
			if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 'S'
				|| data->maze.map[h][w] == 'W' || data->maze.map[h][w] == 'E')
			{
				game->x_pos = w + 0.5;
				game->y_pos = h + 0.5;
				if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 's')
				{
					game->planeY = 0.66;
					if (data->maze.map[h][w] == 'N')
						game->dirY = 1;
					else
						game->dirY = -1;
				}
				else
				{
					game->planeX = 0.66;
					if (data->maze.map[h][w] == 'O')
						game->dirX = 1;
					else
						game->dirX = -1;
				}
			}
			w++;
		}
		h++;
	}
	printf("X pos of player: %f\n", game->x_pos);
	printf("Y pos of player: %f\n", game->y_pos);
	printf("dirX of player: %f\n", game->dirX);
	printf("dirY of player: %f\n", game->dirY);
	printf("planeX of player: %f\n", game->planeX);
	printf("planeY of player: %f\n", game->planeY);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_vars	vars;
	t_game	game;
	int		index;

	(void)argc;
	data.file = open(argv[1], O_RDONLY);
	if (data.file == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	data.read_length =  parse_part_1(data.file, &data);
	printf("This is NO path: %s", data.maze.north_texture);
	printf("This is SO path: %s", data.maze.south_texture);
	printf("This is WE path: %s", data.maze.west_texture);
	printf("This is EA path: %s", data.maze.east_texture);
	printf("This is F: %i, %i, %i\n", data.maze.floor.r, data.maze.floor.g, data.maze.floor.b);
	printf("This is C: %i, %i, %i\n", data.maze.ceiling.r, data.maze.ceiling.g, data.maze.ceiling.b);
	if (parse_map(&data, argv[1]) == 0)
		return (1);
	index = 0;
	if (error_map(&data, data.maze.map) == 0)
		return (1);
	// printf("data.maze.map[18]: %c\n", data.maze.map[0][18]);
	while (data.maze.map[index] != NULL)
	{
		printf("|%s|\n", data.maze.map[index]);
		index++;
	}
	fill_game(&data, &game);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1000, 1000, "Cub3D");
	vars.mlx_img = mlx_new_image(vars.mlx, 1000, 1000);
	mlx_loop(vars.mlx);
	close(data.file);
	return (0);
}