/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:15:26 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/20 12:04:00 by khirsig          ###   ########.fr       */
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

	if (argc != 2)
		exit(EXIT_FAILURE);
	parser(&data, argv[1]);
	data.vars.mlx = mlx_init();
	initializer(&data);
	mlx_loop_hook(data.vars.mlx, gameloop, &data);
	keyhook_handler(&data);
	mlx_loop(data.vars.mlx);
	close(data.file);
	return (0);
}
