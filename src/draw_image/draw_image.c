/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:57:05 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/18 17:42:58 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_ver_line(int i, t_data *data)
{
	int		j;
	void	*wall;
	int		wid = 64;
	int		hght = 64;
	
	
	wall = mlx_xpm_file_to_image(data->vars.mlx, data->maze.north_texture, &wid, &hght);
	j = 0;
	while (j < data->ray.drawStart)
	{
		my_mlx_pixel_put(&data->vars, i, j, 0x00000000);
		j++;
	}
	while (data->ray.drawStart <= data->ray.drawEnd)
	{
		int texY = (int)data->ray.texPos & (data->ray.texHeight - 1);
		data->ray.texPos += data->ray.step;
		int color = data->vars.texture[0][data->ray.texHeight * texY + data->ray.texX];
		if (data->ray.side == 1)
			my_mlx_pixel_put(&data->vars, i, data->ray.drawStart, color);
		else
			my_mlx_pixel_put(&data->vars, i, data->ray.drawStart, 0x00004CB1);
		data->ray.drawStart++;
	}
	j = data->ray.drawEnd + 1;
	while (j < 1000)
	{
		my_mlx_pixel_put(&data->vars, i, j, 0x00000000);
		j++;
	}
}

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
}

/*
Calculate deltaDist (deltaDistX, deltaDistY)
*/
void	calculate_delta_dist(t_data *data)
{
	if (data->ray.rayDirX == 0)
		data->ray.deltaDistX = 1e30;
	else
		data->ray.deltaDistX = sqrt(1 + (data->ray.rayDirY * data->ray.rayDirY)
				/ (data->ray.rayDirX * data->ray.rayDirX));
	if (data->ray.rayDirY == 0)
		data->ray.deltaDistY = 1e30;
	else
		data->ray.deltaDistY = sqrt(1 + (data->ray.rayDirX * data->ray.rayDirX)
				/ (data->ray.rayDirY * data->ray.rayDirY));
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
	//calculate value of wallX
	if(data->ray.side == 0)
		data->ray.wallX = data->player.y_pos + data->ray.perpWallDist * data->ray.rayDirY;
	else
		data->ray.wallX = data->player.x_pos + data->ray.perpWallDist * data->ray.rayDirX;
	data->ray.wallX -= floor(data->ray.wallX);
	//x coordinate on the texture
	data->ray.texWidth = 64;
	data->ray.texHeight = 64;
	data->ray.texX = (int)(data->ray.wallX * (double)(data->ray.texWidth));
	if(data->ray.side == 0 && data->ray.rayDirX > 0)
		data->ray.texX = data->ray.texWidth - data->ray.texX - 1;
	if(data->ray.side == 1 && data->ray.rayDirY < 0)
		data->ray.texX = data->ray.texWidth - data->ray.texX - 1;
	// How much to increase the texture coordinate per screen pixel
	data->ray.step = 1.0 * data->ray.texHeight / data->ray.lineHeight;
	// Starting texture coordinate
	data->ray.texPos = (data->ray.drawStart - 1000 / 2 + data->ray.lineHeight / 2) * data->ray.step;
}

/*
Draw player view.
1) Calculate the ray vector (x and y value) for each vertical line.
2) Prepare for DDA algorithm.
3) Find the wall with DDA algorithm.
4) Calculate distance to wall.
5) Draw line accordingly.
*/
void	draw_view(t_data *data)
{
	int		i;

	i = 0;
	while (i < 1000)
	{
		calculate_ray_vector(data, i);
		calculate_delta_dist(data);
		calculate_step_and_sideDist(data);
		perform_DDA(data);
		calc_ray_dist(data);
		data->ray.ZBuffer[i] = data->ray.perpWallDist;
		draw_ver_line(i, data);
		i++;
	}
}

/*
Helper function
*/
void	fill_player_helper(t_data *data, int h, int w)
{
	// data->maze.north_texture = "../../resources/textures/wall.xpm";
	// data->maze.south_texture = "../../resources/textures/wall.xpm";
	// data->maze.west_texture = "../../resources/textures/wall.xpm";
	// data->maze.east_texture = "../../resources/textures/wall.xpm";
	if (data->maze.map[h][w] != '0' && data->maze.map[h][w] != '1')
	{
		data->player.x_pos = w + 0.5;
		data->player.y_pos = h + 0.5;
		if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 'S')
		{
			if (data->maze.map[h][w] == 'N')
			{
				data->player.planeX = -0.66;
				data->player.dirY = 1;
			}
			else
			{
				data->player.planeX = 0.66;
				data->player.dirY = -1;
			}
		}
		else
		{
			if (data->maze.map[h][w] == 'E')
			{
				data->player.planeY = 0.66;
				data->player.dirX = 1;
			}
			else
			{
				data->player.planeY = -0.66;
				data->player.dirX = -1;
			}
		}
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
	while (data->maze.map[h])
	{
		w = 0;
		while (data->maze.map[h][w])
		{
			fill_player_helper(data, h, w);
			w++;
		}
		h++;
	}
}
