/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:15:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/18 19:57:05 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	create_trgb(int r, int g, int b)
{
	return(65536 * r + 256 * g + b);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	data = (t_data) { };
	init_player(&data);
	data.file = open(argv[1], O_RDONLY);
	parse_part_1(&data);
	printf("floor color  : %i\n", data.maze.floor_color);
	printf("ceiling color: %i\n", data.maze.ceiling_color);
	if (parse_map(&data, argv[1]) == 0)
		return (1);
	if (error_map(&data, data.maze.map) == 0)
		return (1);
	fill_player(&data);
	data.vars.mlx = mlx_init();
	load_texture(&data);
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