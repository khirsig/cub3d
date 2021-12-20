/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vert_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:01:47 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/20 17:55:18 by jhagedor         ###   ########.fr       */
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
	if (data->ray.side == 0)
	{
		if (data->ray.rayDirX < 0)
			color = data->vars.texture[2][data->ray.texHeight * texY + data->ray.texX];
		else
			color = data->vars.texture[3][data->ray.texHeight * texY + data->ray.texX];
	}
	else
	{
		if (data->ray.rayDirY < 0)
			color = data->vars.texture[0][data->ray.texHeight * texY + data->ray.texX];
		else
			color = data->vars.texture[1][data->ray.texHeight * texY + data->ray.texX];
	}
	my_mlx_pixel_put(&data->vars, i, data->ray.drawStart, color);
}

void	draw_ver_line(int i, t_data *data)
{
	int	j;

	j = 0;
	while (j++ < data->ray.drawStart)
		my_mlx_pixel_put(&data->vars, i, j, data->maze.floor_color);
	while (data->ray.drawStart++ <= data->ray.drawEnd)
		draw_wall(data, i);
	j = data->ray.drawEnd + 1;
	while (j++ < 1000)
		my_mlx_pixel_put(&data->vars, i, j, data->maze.ceiling_color);
}
