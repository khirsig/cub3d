/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 08:54:10 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/11 13:43:09 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** Checks which pixel of the minimap should be drawn like what.
** Calculates with 10x10 pixel for each drawn object.
*/
static char	get_map_pos(t_data *data, int x, int y)
{
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
	if (x_temp >= 0 && y_temp >= 0
		&& x_temp < data->x_length && y_temp < data->y_length)
		return (data->maze.map[y_temp][x_temp]);
	else
		return ('0');
}

/*
** Draws a fixed 200x200 Minimap at the top right position of the window.
** The player is fixed in the middle with 8 closest fields in each direction.
*/
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
				my_mlx_pixel_put(&data->vars, x, y, 0x00FFFFFF);
			else if (x > 814 && x <= 986 && y < 186 && y >= 14)
			{
				map_pos = get_map_pos(data, x, y);
				if (map_pos == '1')
					my_mlx_pixel_put(&data->vars, x, y, 0x00444444);
				if (map_pos == 'R' || map_pos == 'G')
					my_mlx_pixel_put(&data->vars, x, y, 0x00FE0000);
			}
			x++;
		}
		y++;
	}
	return (0);
}
