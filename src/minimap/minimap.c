/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:54:10 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/13 14:22:01 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	minimap(t_data *data)
{
	char	map_pos;
	int		x;
	int		x_temp;
	int		y;
	int		y_temp;

	y = 0;
	while (y < 200)
	{
		x = 800;
		while (x < 1000)
		{
			if (x >= 895 && x < 905 && y >= 95 && y < 105)
				my_mlx_pixel_put(&data->vars, x, y, 0x00FE0000);
			else if (x > 814 && x <= 986 && y < 186 && y >= 14)
			{
				if (x < 895)
					x_temp = data->player.x_pos + ((x - 905) / 10);
				else
					x_temp = data->player.x_pos + (x % 895 / 10);
				if (y < 95)
					y_temp = data->player.y_pos + ((y - 105) / 10);
				else
					y_temp = data->player.y_pos + (y % 95 / 10);
				if (x_temp >= 0 && y_temp >= 0 && x_temp < data->x_length && y_temp < data->y_length)
				{
					map_pos = data->maze.map[y_temp][x_temp];
					if (map_pos == '1')
						my_mlx_pixel_put(&data->vars, x, y, 0x00444444);
					else
						my_mlx_pixel_put(&data->vars, x, y, 0x00FFFFFF);
				}
				else
					my_mlx_pixel_put(&data->vars, x, y, 0x00FFFFFF);
			}
			else
				my_mlx_pixel_put(&data->vars, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	return (0);
}