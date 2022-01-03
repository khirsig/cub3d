/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:57:05 by jhagedor          #+#    #+#             */
/*   Updated: 2022/01/03 14:14:27 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Calculate ray vector (rayDirX, rayDirY)
and rounded position of player (mapX, mapY)
*/
void	calculate_ray_vector(t_data *data, int i)
{
	data->ray.cameraX = 2 * i / 1000.0 - 1;
	data->ray.rayDirX = data->player.dirX
		+ data->player.planeX * data->ray.cameraX;
	data->ray.rayDirY = data->player.dirY
		+ data->player.planeY * data->ray.cameraX;
	data->ray.mapX = data->player.x_pos;
	data->ray.mapY = data->player.y_pos;
	if (data->ray.rayDirX == 0)
		data->ray.deltaDistX = 1e30;
	else
		data->ray.deltaDistX = fabs(1 / data->ray.rayDirX);
	if (data->ray.rayDirY == 0)
		data->ray.deltaDistY = 1e30;
	else
		data->ray.deltaDistY = fabs(1 / data->ray.rayDirY);
}

/*
Calculate step and initial sideDist
*/
void	calculate_step_and_sideDist(t_data *data)
{
	if (data->ray.rayDirX < 0)
	{
		data->ray.stepX = -1;
		data->ray.sideDistX = (data->player.x_pos - data->ray.mapX)
			* data->ray.deltaDistX;
	}
	else
	{
		data->ray.stepX = 1;
		data->ray.sideDistX = (data->ray.mapX + 1.0 - data->player.x_pos)
			* data->ray.deltaDistX;
	}
	if (data->ray.rayDirY < 0)
	{
		data->ray.stepY = -1;
		data->ray.sideDistY = (data->player.y_pos - data->ray.mapY)
			* data->ray.deltaDistY;
	}
	else
	{
		data->ray.stepY = 1;
		data->ray.sideDistY = (data->ray.mapY + 1.0 - data->player.y_pos)
			* data->ray.deltaDistY;
	}
}

/*
Calculate step and initial sideDist
*/
void	perform_DDA(t_data *data)
{
	data->ray.hit = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.sideDistX < data->ray.sideDistY)
		{
			data->ray.sideDistX += data->ray.deltaDistX;
			data->ray.mapX += data->ray.stepX;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sideDistY += data->ray.deltaDistY;
			data->ray.mapY += data->ray.stepY;
			data->ray.side = 1;
		}
		if (data->maze.map[data->ray.mapY][data->ray.mapX] == '1')
			data->ray.hit = 1;
	}
}

/*
Calculate ray distance and hight
*/
void	calc_ray_dist(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpWallDist = (data->ray.sideDistX - data->ray.deltaDistX);
	else
		data->ray.perpWallDist = (data->ray.sideDistY - data->ray.deltaDistY);
	data->ray.lineHeight = (int)(1000 / data->ray.perpWallDist);
	data->ray.drawStart = 1000 / 2 - data->ray.lineHeight / 2;
	if (data->ray.drawStart < 0)
		data->ray.drawStart = 0;
	data->ray.drawEnd = data->ray.lineHeight / 2 + 1000 / 2;
	if (data->ray.drawEnd >= 1000)
		data->ray.drawEnd = 1000 - 1;
	if (data->ray.side == 0)
		data->ray.wallX = data->player.y_pos
			+ data->ray.perpWallDist * data->ray.rayDirY;
	else
		data->ray.wallX = data->player.x_pos
			+ data->ray.perpWallDist * data->ray.rayDirX;
}

/*
Calculate x position of wall
*/
void	calc_x_pos(t_data *data)
{
	data->ray.texWidth = 64;
	data->ray.texHeight = 64;
	data->ray.wallX -= floor(data->ray.wallX);
	data->ray.texX = (int)(data->ray.wallX * (double)(data->ray.texWidth));
	if (data->ray.side == 0 && data->ray.rayDirX > 0)
		data->ray.texX = data->ray.texWidth - data->ray.texX - 1;
	if (data->ray.side == 1 && data->ray.rayDirY < 0)
		data->ray.texX = data->ray.texWidth - data->ray.texX - 1;
	data->ray.step = 1.0 * data->ray.texHeight / data->ray.lineHeight;
	data->ray.texPos = (data->ray.drawStart - 1000 / 2
			+ data->ray.lineHeight / 2) * data->ray.step;
}
