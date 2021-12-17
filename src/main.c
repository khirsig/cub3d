/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:15:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 14:26:31 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"



int	main(int argc, char **argv)
{
	t_data	data;
	int		index;

	(void)argc;
	data.player.walk_left = 0;
	data.player.walk_right = 0;
	data.player.walk_down = 0;
	data.player.walk_up = 0;
	data.player.is_rotating = 0;
	data.player.rotation_direction = LEFT;
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
	data.vars.mlx_win = mlx_new_window(data.vars.mlx, 1000, 1000, "Cub3D");
	data.vars.mlx_img = mlx_new_image(data.vars.mlx, 1000, 1000);
	data.vars.addr = mlx_get_data_addr
		(data.vars.mlx_img, &data.vars.bits_per_pixel, &data.vars.line_length, &data.vars.endian);
	mlx_key_hook(data.vars.mlx_win, keyhook, &data);
	mlx_hook(data.vars.mlx_win, 2, (1L << 0), &player_press, &data);
	mlx_hook(data.vars.mlx_win, 3, (1L << 1), &player_release, &data);
	mlx_loop_hook(data.vars.mlx, gameloop, &data);
	mlx_loop(data.vars.mlx);
	close(data.file);
	return (0);
}