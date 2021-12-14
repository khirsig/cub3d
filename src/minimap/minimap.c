/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:54:10 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/14 10:03:37 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static char get_map_pos(t_data *data, int x, int y)
{
	char	ret;
	int		x_temp;
	int		y_temp;

	if (x < 895)
		x_temp = data->player.x_pos + ((x - 905) / 10);
	else
		x_temp = data->player.x_pos + (x % 895 / 10);
	if (y < 95)
		y_temp = data->player.y_pos + ((y - 105) / 10);
	else
		y_temp = data->player.y_pos + (y % 95 / 10);
	if (x_temp >= 0 && y_temp >= 0 && x_temp < data->x_length && y_temp < data->y_length)
		return(data->maze.map[y_temp][x_temp]);
	else
		return ('0');
}

int	minimap(t_data *data)
{
	char	map_pos;
	int		x;
	int		y;

	y = 0;
	while (y < 200)
	{
		x = 800;
		while (x < 1000)
		{
			if (x >= 896 && x < 904 && y >= 96 && y < 104)
				my_mlx_pixel_put(&data->vars, x, y, 0x00FE0000);
			else if (x > 814 && x <= 986 && y < 186 && y >= 14)
			{
				map_pos = get_map_pos(data, x, y);
				if (map_pos == '1')
					my_mlx_pixel_put(&data->vars, x, y, 0x00444444);
			}
			x++;
		}
		y++;
	}
	return (0);
}