/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:15:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/13 09:14:15 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"



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
	if (parse_map(&data, argv[1]) == 0)
		return (1);
	index = 0;
	if (error_map(&data, data.maze.map) == 0)
		return (1);
	while (data.maze.map[index] != NULL)
	{
		printf("|%s|\n", data.maze.map[index]);
		index++;
	}
	fill_game(&data, &game);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1000, 1000, "Cub3D");
	vars.mlx_img = mlx_new_image(vars.mlx, 1000, 1000);
	vars.addr = mlx_get_data_addr
		(vars.mlx_img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	calculate_dist(&data, &game, &vars);
	minimap(&data, &vars, &game);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.mlx_img, 0, 0);
	mlx_loop(vars.mlx);
	close(data.file);
	return (0);
}