/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_vert_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:54:51 by jhagedor          #+#    #+#             */
/*   Updated: 2022/01/17 15:04:27 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_wall(t_data *data, int i)
{
	int	texY;
	int	color;

	texY = (int)data->ray.texPos & (data->ray.texHeight - 1);
	data->ray.texPos += data->ray.step;
	color = data->vars.texture[0][data->ray.texHeight * texY + data->ray.texX];
	if (data->ray.side == 0 && data->ray.hit == 1)
	{
		if (data->ray.rayDirX < 0)
			color = data->vars.texture[2]
			[data->ray.texHeight * texY + data->ray.texX];
		else
			color = data->vars.texture[3]
			[data->ray.texHeight * texY + data->ray.texX];
	}
	else if (data->ray.hit == 1)
	{
		if (data->ray.rayDirY < 0)
			color = data->vars.texture[0]
			[data->ray.texHeight * texY + data->ray.texX];
		else
			color = data->vars.texture[1]
			[data->ray.texHeight * texY + data->ray.texX];
	}
	if (data->ray.hit == 2)
		color = data->maze.door_texture
		[data->ray.texHeight * texY + data->ray.texX];
	my_mlx_pixel_put(&data->vars, i, data->ray.drawStart, color);
}

void	draw_ver_line(int i, t_data *data)
{
	int	j;

	j = 0;
	data->ray.ZBuffer[i] = data->ray.perpWallDist;
	while (j < data->ray.drawStart)
	{
		my_mlx_pixel_put(&data->vars, i, j, data->maze.ceiling_color);
		j++;
	}
	while (data->ray.drawStart <= data->ray.drawEnd)
	{
		draw_wall(data, i);
		data->ray.drawStart++;
	}
	j = data->ray.drawEnd + 1;
	while (j < 1000)
	{
		my_mlx_pixel_put(&data->vars, i, j, data->maze.floor_color);
		j++;
	}
}
