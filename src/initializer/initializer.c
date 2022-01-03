/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:18:01 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/03 10:55:27 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	initializer(t_data *data)
{
	init_player(data);
	init_wall(data);
	init_enemy(data);
	init_interface(data);
	data->vars.mlx_win = mlx_new_window(data->vars.mlx,
			1000, 1000, "The Phenomenal Game");
	data->vars.mlx_img = mlx_new_image(data->vars.mlx, 1000, 1000);
	data->vars.addr = mlx_get_data_addr
		(data->vars.mlx_img, &data->vars.bits_per_pixel,
			&data->vars.line_length, &data->vars.endian);
}
