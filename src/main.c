/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:15:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/18 09:22:28 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"



int	main(int argc, char **argv)
{
	t_data	data;
	int		index;

	(void)argc;
	init_player(&data);
	data.numEnemies = 0;
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
	fill_player(&data);
	data.vars.mlx = mlx_init();
	enemy_init(&data);
	init_interface(&data);
	data.vars.mlx_win = mlx_new_window(data.vars.mlx, 1000, 1000, "Cub3D");
	data.vars.mlx_img = mlx_new_image(data.vars.mlx, 1000, 1000);
	data.vars.addr = mlx_get_data_addr
		(data.vars.mlx_img, &data.vars.bits_per_pixel, &data.vars.line_length, &data.vars.endian);
	mlx_loop_hook(data.vars.mlx, gameloop, &data);
	keyhook_handler(&data);
	mlx_loop(data.vars.mlx);
	close(data.file);
	return (0);
}