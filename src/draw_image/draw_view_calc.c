/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:57:05 by jhagedor          #+#    #+#             */
/*   Updated: 2022/02/15 21:29:02 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Calculate ray vector (ray_dir_x, ray_dir_y)
and rounded position of player (map_x, map_y)
*/
void	calculate_ray_vector(t_data *data, int i)
{
	data->ray.camera_x = 2 * i / 1000.0 - 1;
	data->ray.ray_dir_x = data->player.dir_x
		+ data->player.plane_x * data->ray.camera_x;
	data->ray.ray_dir_y = data->player.dir_y
		+ data->player.plane_y * data->ray.camera_x;
	data->ray.map_x = data->player.x_pos;
	data->ray.map_y = data->player.y_pos;
	if (data->ray.ray_dir_x == 0)
		data->ray.delta_dist_x = 1e30;
	else
		data->ray.delta_dist_x = fabs(1 / data->ray.ray_dir_x);
	if (data->ray.ray_dir_y == 0)
		data->ray.delta_dist_y = 1e30;
	else
		data->ray.delta_dist_y = fabs(1 / data->ray.ray_dir_y);
}

/*
Calculate step and initial sideDist
*/
void	calculate_step_and_sidedist(t_data *data)
{
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.x_pos - data->ray.map_x)
			* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->player.x_pos)
			* data->ray.delta_dist_x;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.y_pos - data->ray.map_y)
			* data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->player.y_pos)
			* data->ray.delta_dist_y;
	}
}

/*
Calculate step and initial sideDist
*/
void	perform_dda(t_data *data)
{
	data->ray.hit = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->maze.map[data->ray.map_y][data->ray.map_x] == '1')
			data->ray.hit = 1;
		if (data->maze.map[data->ray.map_y][data->ray.map_x] == '2')
			data->ray.hit = 2;
	}
}

/*
Calculate ray distance and hight
*/
void	calc_ray_dist(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perp_wall_dist
			= (data->ray.side_dist_x - data->ray.delta_dist_x);
	else
		data->ray.perp_wall_dist
			= (data->ray.side_dist_y - data->ray.delta_dist_y);
	data->ray.line_height = (int)(1000 / data->ray.perp_wall_dist);
	data->ray.draw_start = 1000 / 2 - data->ray.line_height / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + 1000 / 2;
	if (data->ray.draw_end >= 1000)
		data->ray.draw_end = 1000 - 1;
	if (data->ray.side == 0)
		data->ray.wall_x = data->player.y_pos
			+ data->ray.perp_wall_dist * data->ray.ray_dir_y;
	else
		data->ray.wall_x = data->player.x_pos
			+ data->ray.perp_wall_dist * data->ray.ray_dir_x;
}

/*
Calculate x position of wall
*/
void	calc_x_pos(t_data *data)
{
	data->ray.tex_width = 64;
	data->ray.tex_height = 64;
	data->ray.wall_x -= floor(data->ray.wall_x);
	data->ray.tex_x = (int)(data->ray.wall_x * (double)(data->ray.tex_width));
	if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
		data->ray.tex_x = data->ray.tex_width - data->ray.tex_x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
		data->ray.tex_x = data->ray.tex_width - data->ray.tex_x - 1;
	data->ray.step = 1.0 * data->ray.tex_height / data->ray.line_height;
	data->ray.tex_pos = (data->ray.draw_start - 1000 / 2
			+ data->ray.line_height / 2) * data->ray.step;
}
