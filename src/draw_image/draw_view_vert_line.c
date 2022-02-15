/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_vert_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:54:51 by jhagedor          #+#    #+#             */
/*   Updated: 2022/02/15 21:25:41 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	draw_wall_get_color(t_data *data, int texY)
{
	int	color;

	if (data->ray.side == 0 && data->ray.hit == 1)
	{
		if (data->ray.ray_dir_x < 0)
			color = data->vars.texture[2]
			[data->ray.tex_height * texY + data->ray.tex_x];
		else
			color = data->vars.texture[3]
			[data->ray.tex_height * texY + data->ray.tex_x];
	}
	else if (data->ray.hit == 1)
	{
		if (data->ray.ray_dir_y < 0)
			color = data->vars.texture[0]
			[data->ray.tex_height * texY + data->ray.tex_x];
		else
			color = data->vars.texture[1]
			[data->ray.tex_height * texY + data->ray.tex_x];
	}
	if (data->ray.hit == 2)
		color = data->maze.door_texture
		[data->ray.tex_height * texY + data->ray.tex_x];
	return (color);
}

void	draw_wall(t_data *data, int i)
{
	int	tex_y;
	int	color;

	tex_y = (int)data->ray.tex_pos & (data->ray.tex_height - 1);
	data->ray.tex_pos += data->ray.step;
	color = draw_wall_get_color(data, tex_y);
	my_mlx_pixel_put(&data->vars, i, data->ray.draw_start, color);
}

void	draw_ver_line(int i, t_data *data)
{
	int	j;

	j = 0;
	data->ray.z_buffer[i] = data->ray.perp_wall_dist;
	while (j < data->ray.draw_start)
	{
		my_mlx_pixel_put(&data->vars, i, j, data->maze.ceiling_color);
		j++;
	}
	while (data->ray.draw_start <= data->ray.draw_end)
	{
		draw_wall(data, i);
		data->ray.draw_start++;
	}
	j = data->ray.draw_end + 1;
	while (j < 1000)
	{
		my_mlx_pixel_put(&data->vars, i, j, data->maze.floor_color);
		j++;
	}
}
