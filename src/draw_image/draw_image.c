/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:57:05 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/13 16:20:00 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void drawVerLine(int i, int drawStart, int drawEnd, t_data *data, int side)
{
	while (drawStart <= drawEnd)
	{
		if (side == 1)
			my_mlx_pixel_put(&data->vars, i, drawStart, 0x00FF0000);
		else
			my_mlx_pixel_put(&data->vars, i, drawStart, 0x00A52A2A);
		drawStart++;
	}
}

/*
Calculate ray vector (rayDirX, rayDirY) and rounded position of player (mapX, mapY)
*/
void	calculate_ray_vector(t_data *data, int i)
{
		data->ray.cameraX = 2 * i / 1000.0 - 1;
		data->ray.rayDirX = data->player.dirX + data->player.planeX * data->ray.cameraX;
		data->ray.rayDirY = data->player.dirY + data->player.planeY * data->ray.cameraX;
		data->ray.mapX = data->player.x_pos;
		data->ray.mapY = data->player.y_pos;
}

/*
Calculate deltaDist (deltaDistX, deltaDistY)
*/
void	calculate_delta_dist(t_data *data)
{
	if (data->ray.rayDirX == 0)
		data->ray.deltaDistX = 1e30;
	else
		data->ray.deltaDistX = sqrt(1 + (data->ray.rayDirY * data->ray.rayDirY) / (data->ray.rayDirX * data->ray.rayDirX));
	if (data->ray.rayDirY == 0)
		data->ray.deltaDistY = 1e30;
	else
		data->ray.deltaDistY = sqrt(1 + (data->ray.rayDirX * data->ray.rayDirX) / (data->ray.rayDirY * data->ray.rayDirY));
}

/*
calculate step and initial sideDist
*/
void	calculate_step_and_sideDist(t_data *data)
{
	if(data->ray.rayDirX < 0)
	{
		data->ray.stepX = -1;
		data->ray.sideDistX = (data->player.x_pos - data->ray.mapX) * data->ray.deltaDistX;
	}
	else
	{
		data->ray.stepX = 1;
		data->ray.sideDistX = (data->ray.mapX + 1.0 - data->player.x_pos) * data->ray.deltaDistX;
	}
	if(data->ray.rayDirY < 0)
	{
		data->ray.stepY = -1;
		data->ray.sideDistY = (data->player.y_pos - data->ray.mapY) * data->ray.deltaDistY;
	}
	else
	{
		data->ray.stepY = 1;
		data->ray.sideDistY = (data->ray.mapY + 1.0 - data->player.y_pos) * data->ray.deltaDistY;
	}
}

/*
calculate step and initial sideDist
*/
void	perform_DDA(t_data *data)
{
	//perform DDA
	data->ray.hit = 0;
	while(data->ray.hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if(data->ray.sideDistX < data->ray.sideDistY)
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
		//Check if ray has hit a wall
		if(data->maze.map[data->ray.mapY][data->ray.mapX] == '1')
			data->ray.hit = 1;
	}
}

/*
calculate ray distance and hight
*/
void	calc_ray_dist(t_data *data)
{
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if(data->ray.side == 0)
		data->ray.perpWallDist = (data->ray.sideDistX - data->ray.deltaDistX);
	else
		data->ray.perpWallDist = (data->ray.sideDistY - data->ray.deltaDistY);

	//Calculate height of line to draw on screen
	data->ray.lineHeight = (int)(1000 / data->ray.perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	data->ray.drawStart = - data->ray.lineHeight / 2 + 1000 / 2;
	if(data->ray.drawStart < 0)
		data->ray.drawStart = 0;
	data->ray.drawEnd = data->ray.lineHeight / 2 + 1000 / 2;
	if(data->ray.drawEnd >= 1000)
		data->ray.drawEnd = 1000 - 1;
	// if (i < 5)
	// 	printf("This is the distance: %i (Start: %i, End %i)\n", data->ray.drawEnd - data->ray.drawStart, data->ray.drawStart, data->ray.drawEnd);
}

void	draw_view(t_data *data)
{
	int		i;

	i = 0;
	while(i < 1000)
	{
		calculate_ray_vector(data, i);
		calculate_delta_dist(data);
		calculate_step_and_sideDist(data);
		perform_DDA(data);
		calc_ray_dist(data);
		drawVerLine(i, data->ray.drawStart, data->ray.drawEnd, data, data->ray.side);
		i++;
	}
}


/*
Loops through map and fills position, direction and plane.
*/

void	fill_player(t_data *data)
{
	int	w;
	int	h;

	h = 0;
	while(data->maze.map[h])
	{
		w = 0;
		while (data->maze.map[h][w])
		{
			if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 'S'
				|| data->maze.map[h][w] == 'W' || data->maze.map[h][w] == 'E')
			{
				printf("PPos: %i %i\n", h, w);
				data->player.x_pos = w + 0.5;
				data->player.y_pos = h + 0.5;
				if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 'S')
				{
					data->player.planeX = 0.66;
					if (data->maze.map[h][w] == 'N')
						data->player.dirY = 1;
					else
						data->player.dirY = -1;
				}
				else
				{
					data->player.planeY = 0.66;
					if (data->maze.map[h][w] == 'E')
						data->player.dirX = 1;
					else
						data->player.dirX = -1;
				}
			}
			w++;
		}
		h++;
	}

}