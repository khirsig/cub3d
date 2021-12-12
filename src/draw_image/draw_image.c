/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:57:05 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/12 13:13:17 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calculate_dist(t_data *data, t_game *game)
{
	int		i;
	double	cameraX;
	//ray direction
	double	rayDirX;
	double	rayDirY;
	//which box of the map we're in
	int		mapX;
	int		mapY;
	//length of ray from current position to next x or y-side
	double	sideDistX;
	double	sideDistY;
	//length of ray from one x or y-side to next x or y-side
	double	deltaDistX;
	double	deltaDistY;
	//direction to step in x or y-direction (either +1 or -1)
	int		stepX;
	int		stepY;
	//was there a wall hit?
	int		hit = 0;
	//was a NS or a EW wall hit?
	int		side;

	i = 0;
	while(i < 1000)
	{
		cameraX = 2 * i / 1000.0 - 1;
		rayDirX = game->dirX + game->planeX * cameraX;
		rayDirY = game->dirY + game->planeY * cameraX;
		
		mapX = game->x_pos;
		mapY = game->y_pos;

		if (rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		if (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->x_pos - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->x_pos) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->y_pos - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->y_pos) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(data->maze.map[mapX][mapY] == '1')
				hit = 1;
		}
	}
}


/*
Loops through map and fills position, direction and plane.
*/

void	fill_game(t_data *data, t_game *game)
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
				game->x_pos = w + 0.5;
				game->y_pos = h + 0.5;
				if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 's')
				{
					game->planeY = 0.66;
					if (data->maze.map[h][w] == 'N')
						game->dirY = 1;
					else
						game->dirY = -1;
				}
				else
				{
					game->planeX = 0.66;
					if (data->maze.map[h][w] == 'O')
						game->dirX = 1;
					else
						game->dirX = -1;
				}
			}
			w++;
		}
		h++;
	}
	
}